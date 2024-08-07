#include "backends/imgui_impl_opengl3.h"
#include "hello_imgui/hello_imgui.h"
#include "hello_imgui/hello_imgui_assets.h"
#include "imgui.h"
#include "hello_imgui/imgui_default_settings.h"
#include "pugixml.hpp"
#include <archive.h>
#include <archive_entry.h>
#include <backends/imgui_impl_sdl2.h>
#include <cstdlib>
#include <misc/cpp/imgui_stdlib.h>
#include <iostream>
#include <sstream>

#include "lexicon.h"
#include "phono.hpp"
#include "pos.h"
#include "emscripten_spec.h"

#include "hello_imgui/runner_callbacks.h"
#include "hello_imgui/runner_params.h"
#include <SDL2/SDL.h>

#ifndef __EMSCRIPTEN__

					#include <src/include/nfd.h>
#endif


enum modes { nil,
			 M_LEX,
			 M_PHO,
			 M_POS };

int mode = M_LEX;

int popup = 0;
std::string errstr;

pugi::xml_document dict;

char *confont;

ImFont *imconfont = 0;

int hasconfont = 0;

struct stat old_xml_stat = {};

int find_win = 0;
bool openfind = false;
bool vkeyboard = false;

std::string curr_lang_fname;

std::string procol, posname, wposid;

bool less_than_ver(const std::string &a, const std::string &b) {
	std::vector<std::string> ra, rb;

	std::stringstream data(a), datb(b);

	std::string l;

	while (std::getline(data, l, '.')) {
		ra.push_back(l);
	}

	while (std::getline(datb, l, '.')) {
		rb.push_back(l);
	}

	for (int i = 0; i < std::min(ra.size(), rb.size()); ++i) {
		if (std::stoi(ra[i]) < std::stoi(rb[i])) {
			return true;
		}
	}

	return false;
}


void handle_upload_file(
	std::string const &filename,  // the filename of the file the user selected
	std::string const &mime_type, // the MIME type of the file the user
								  // selected, for example "image/png"
	std::string_view
		buffer,					  // the file's content is exposed in this string_view - access
								  // the data with buffer.data() and size with buffer.size().
	void *callback_data = nullptr // optional callback data - identical to
								  // whatever you passed to handle_upload_file()
) {

	openfind = 0;
	extern bool open_conjugator;
	open_conjugator = false;

	curr_lang_fname = filename;

	struct archive *arr = archive_read_new();
	archive_read_support_format_zip(arr);

	int r = archive_read_open_memory(arr, buffer.data(), buffer.size());
	if (r != ARCHIVE_OK) {
		popup = 1;
		errstr = std::string(archive_error_string(arr));

		archive_free(arr);
		return;
	}

	struct archive_entry *fileentry;

	int foundxml = 0;
	imconfont = 0;
	delete[] confont;
	confont = 0;

	hasconfont = 0;

	while (archive_read_next_header(arr, &fileentry) == ARCHIVE_OK) {
		if (!strcmp(archive_entry_pathname(fileentry),
					"PGDictionary.xml")) {
			foundxml = 1;

			char *tmpstr = new char[archive_entry_size(fileentry)];

			archive_read_data(arr, tmpstr,
							  archive_entry_size(fileentry));
			std::string dict_stro(tmpstr);

			dict.load_string(tmpstr);

			delete[] tmpstr;

			memcpy(&old_xml_stat, archive_entry_stat(fileentry),
				   sizeof(struct stat));
		} else if (!strcmp(archive_entry_pathname(fileentry),
						   "conLangFont")) {

			delete[] confont;
			confont = new char[archive_entry_size(fileentry)];
			archive_read_data(arr, confont,
							  archive_entry_size(fileentry));
			hasconfont = 1;
		} else {
			archive_read_data_skip(arr);
		}
	}

	if (foundxml == 0) {
		popup = 1;
		errstr = "Cannot find PGDictionary.xml in archive";
		return;
	}

	if (less_than_ver(dict.child("dictionary").child("PolyGlotVer").text().as_string(), "3.6")) {
		procol = "etymologyCollection";
		posname = "class";
		wposid = "wordTypeId";
	} else {
		procol = "pronunciationCollection";
		posname = "partOfSpeech";
		wposid = "wordPosId";
	}

	update_lexicon_page();
	fix_lexicon_word_prop();
}

void maingui() {

	if (ImGui::BeginMainMenuBar()) {

		if (ImGui::BeginMenu("File")) {

			if (ImGui::MenuItem("Open", "Ctrl+O")) {
	
				#ifdef __EMSCRIPTEN__
				emscripten_browser_file::upload(
					".pgd", handle_upload_file);
				#else
										NFD_Init();
					
										nfdu8char_t *outPath;
					nfdu8filteritem_t filters =  { "PolyGlot language file", "pgd"  };
					nfdopendialogu8args_t args = {0};
					args.filterList = &filters;
					args.filterCount = 1;
					nfdresult_t result = NFD_OpenDialogU8_With(&outPath, &args);
					if (result == NFD_OKAY)
					{
						puts(outPath);
						FILE *f = fopen(outPath, "rb");
						if(!f){
							popup = true;
						}
						else{
							
							//find file size
							fseek(f, 0, SEEK_END);
							int sz;
							
							char *buf = new char[sz=ftell(f)];
							fseek(f,0,SEEK_SET);
							if(fread(buf, sz, 1, f) == -1){
									popup = true;
							}
							else{
								
								handle_upload_file(std::string(basename(outPath)), "", std::string_view(buf, sz));
								NFD_FreePathU8(outPath);
							}
							
							delete [] buf;
						}
						
					}
					else if (result == NFD_CANCEL)
					{
						puts("User pressed cancel.");
					}
					else 
					{
						printf("Error: %s\n", NFD_GetError());
					}

					NFD_Quit();
					
				//	handle_upload_file();
					
				#endif

				
			}
			if (ImGui::MenuItem("Save", "Ctrl+S")) {
				std::stringstream ss;

				dict.save(ss, PUGIXML_TEXT(""),
						  pugi::format_raw);

				std::cout << ss.str().length() << std::endl;

				struct archive *arr = archive_write_new();
				archive_write_set_format_zip(arr);
				archive_write_set_options(
					arr, "zip:compression=deflate");

				std::vector<char> buffer(1000);
				size_t used;

				buffer.resize(ss.str().length() + 10000 +
							  buffer.size());

				int r = archive_write_open_memory(
					arr, buffer.data(), buffer.size(), &used);

				archive_entry *fileentry = archive_entry_new();

				archive_entry_copy_stat(fileentry,
										&old_xml_stat);
				archive_entry_set_size(fileentry,
									   (ss.str().length()));
				archive_entry_set_pathname(fileentry,
										   "PGDictionary.xml");
				archive_entry_set_perm(fileentry, 0755);
				archive_entry_set_filetype(fileentry, AE_IFREG);

				archive_write_header(arr, fileentry);

				archive_write_data(arr, ss.str().c_str(),
								   ss.str().length() +
									   1);

				archive_entry_free(fileentry);

				archive_write_close(arr);
				archive_write_free(arr); // Note 5

				std::string_view sv(
					reinterpret_cast<char *>(buffer.data()),
					used);
					
				#ifdef __EMSCRIPTEN__
				emscripten_browser_file::download(
					curr_lang_fname, "application/octet-stream",
					sv);
				#else

				
				
				#endif
			}
			if (ImGui::MenuItem("Open from browser stor.", "")) {
			}
			if (ImGui::MenuItem("Save to browser stor.", "")) {
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Edit")) {
			if (ImGui::MenuItem("Undo", "CTRL+Z")) {
			}
			if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {
			} // Disabled item
			ImGui::Separator();
			if (ImGui::MenuItem("Cut", "CTRL+X")) {
			}
			if (ImGui::MenuItem("Copy", "CTRL+C")) {
			}
			if (ImGui::MenuItem("Paste", "CTRL+V")) {
			}

			if (mode == M_LEX) {
				if (ImGui::MenuItem("Find Word", "CTRL+F")) {

					openfind = true;
				}
			}

			ImGui::EndMenu();
		}

		ImGui::EndMainMenuBar();
	}

	ImVec2 pos = ImGui::GetCursorScreenPos();
	ImVec2 sz = ImGui::GetWindowSize();
	ImVec2 ratio = ImVec2(sz.x / 1280, sz.y / 720);

	ImGui::BeginGroup();
	ImGui::SetCursorScreenPos(ImVec2(pos.x, 22));

	ImGui::PushAllowKeyboardFocus(false);

	if (ImGui::Button("Lexicon",
					  ImVec2((float)200 * ratio.x, (float)120 * ratio.y))) {
		mode = M_LEX;
	}
	if (ImGui::Button("Phonology & Rom.",
					  ImVec2((float)200 * ratio.x, (float)120 * ratio.y))) {
		mode = M_PHO;
	}
	if (ImGui::Button("Part of Speech",
					  ImVec2((float)200 * ratio.x, (float)120 * ratio.y))) {
		mode = M_POS;
	}

	ImGui::PopAllowKeyboardFocus();

	ImGui::EndGroup();

	if (mode == M_LEX) {

		draw_lexicon_page();
	}
	if (mode == M_PHO) {
		draw_phono_page();
	}
	if (mode == M_POS) {
		draw_pos_page();
	}

	if (popup) {
		ImGui::OpenPopup("Error opening file");
	}

	ImVec2 center = ImGui::GetMainViewport()->GetCenter();
	ImGui::SetNextWindowPos(center, ImGuiCond_Appearing,
							ImVec2(0.5f, 0.5f));

	if (ImGui::BeginPopupModal("Error opening file")) {
		ImGui::Text("Error: %s", errstr.c_str());
		if (ImGui::Button("OK", ImVec2(120, 0))) {
			popup = 0;
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
	// ImGui::EndGroup();
	if (openfind) {
		if (ImGui::Begin("Find Word", &openfind,
						 ImGuiWindowFlags_AlwaysAutoResize)) {
			if (lexi_find_dialogue()) {
				openfind = false;
			}
		}

		ImGui::End();
	} else {
		lexi_find_dialogue_set_scroll_false();
	}
	
	#ifdef __EMSCRIPTEN__

	ImGuiIO &io = ImGui::GetIO();
	toggle_vkeyboard(io.WantCaptureKeyboard);
	#endif
}

void load_noto_sans() { HelloImGui::LoadFontTTF("notosans.ttf", 20, true); }

std::string content; // this stores the content for our internal clipboard

char const *get_content_for_imgui(void *user_data [[maybe_unused]]) {
	/// Callback for imgui, to return clipboard content
	return content.c_str();
}

void set_content_from_imgui(void *user_data [[maybe_unused]],
							char const *text) {
	/// Callback for imgui, to set clipboard content
	content = text;
	
	#ifdef __EMSCRIPTEN__
	emscripten_browser_clipboard::copy(
		content); // send clipboard data to the browser
	#endif
	
}

void pre_new_frame() {
	#ifdef __EMSCRIPTEN__
	emscripten_browser_clipboard::paste([](std::string const &paste_data,
										   void *callback_data
										   [[maybe_unused]]) {
		/// Callback to handle clipboard paste from browser
		content = std::move(paste_data);
	});
	#endif
	ImGuiIO &imgui_io = ImGui::GetIO();
	imgui_io.GetClipboardTextFn = get_content_for_imgui;
	imgui_io.SetClipboardTextFn = set_content_from_imgui;

	if (confont != 0 && imconfont == 0 && hasconfont) {
		ImGuiIO &io = ImGui::GetIO();
		ImGui::MemFree(imconfont);

		io.Fonts->Clear();
		load_noto_sans();

		static const ImWchar dummy_ranges[] = {
			0x20, 0xFFFF,
			0}; // Will not be copied by AddFont* so keep in scope.
		imconfont = io.Fonts->AddFontFromMemoryTTF(confont, 20, 20,
												   NULL, dummy_ranges);

		io.Fonts->Build();
		ImGui_ImplOpenGL3_CreateFontsTexture();
	}
	if (confont == 0)
		imconfont = 0;
}


int main(int, char *[]) {
	auto params = HelloImGui::RunnerParams{
		.callbacks.ShowGui = maingui,
		.callbacks.PreNewFrame = pre_new_frame,
		.appWindowParams.windowTitle = "Vielsprachig", //.appWindowParams.windowGeometry.sizeAuto
													   //= true,
		.appWindowParams.windowGeometry.size = {300, 200}};

	params.callbacks.LoadAdditionalFonts = load_noto_sans;

#ifdef __EMSCRIPTEN__
	SDL_SetHint(SDL_HINT_EMSCRIPTEN_KEYBOARD_ELEMENT, "#minput");
	SDL_SetHint(SDL_HINT_GRAB_KEYBOARD, "true");
#endif

	pugi::xml_node obj = dict.append_child("dictionary");
	obj.append_child("lexicon");
	obj.append_child("partsOfSpeech");
	obj.append_child("declensionCollection");

	old_xml_stat = {};

	curr_lang_fname = "new.pgd";

	procol = "pronunciationCollection";
	posname = "partOfSpeech";
	wposid = "wordPosId";
	pugi::xml_node procn = obj.append_child(procol.c_str());
	procn.append_child("proGuide");
	HelloImGui::Run(params);

	return 0;
}
