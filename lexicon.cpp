#include "lexicon.h"
#include <imgui.h>
#include <imgui/misc/cpp/imgui_stdlib.h>
#include <iostream>
#include <map>
#include <regex>
#include <unistd.h>

extern pugi::xml_document dict;

std::vector<pugi::xml_node> lexlist;
std::vector<int> poslist;

std::string coninput;
std::string natinput;
std::string proinput;
std::string definput;

int current_pos_id;

int current_word_id;
pugi::xml_node curr_word;

extern char *confont;

bool isautogen;
bool isautoproc;

extern std::string procol, posname, wposid;

int find_new_id() {
	pugi::xml_node words = dict.child("dictionary").child("lexicon");

	int maxid = 0;

	for (auto it = words.first_child(); it; it = it.next_sibling()) {
		int comp = it.child("wordId").text().as_int();
		if (comp > maxid) {
			maxid = comp;
		}
	}
	return ++maxid;
}

pugi::xml_node find_word_from_conword_id(int id) {
	pugi::xml_node words = dict.child("dictionary").child("lexicon");

	for (auto it = words.first_child(); it; it = it.next_sibling()) {
		int val = it.child("wordId").text().as_int();
		if (val == id) {
			return it;
		}
	}
	int conedit = 0;

	return pugi::xml_node();
}

pugi::xml_node find_pos_from_pos_id(int id) {
	pugi::xml_node words = dict.child("dictionary").child("partsOfSpeech");

	for (auto it = words.first_child(); it; it = it.next_sibling()) {
		int val = it.child((posname + "Id").c_str()).text().as_int();
		if (val == id) {
			return it;
		}
	}
	int conedit = 0;

	return pugi::xml_node();
}

int contextin_callback(ImGuiInputTextCallbackData *in) {
	curr_word.child("conWord").text().set(in->Buf);

	update_lexicon_page();

	return 0;
}

int nattextin_callback(ImGuiInputTextCallbackData *in) {
	curr_word.child("localWord").text().set(in->Buf);

	update_lexicon_page();

	return 0;
}

int protextin_callback(ImGuiInputTextCallbackData *in) {
	curr_word.child("pronunciation").text().set(in->Buf);

	update_lexicon_page();

	return 0;
}

int deftextin_callback(ImGuiInputTextCallbackData *in) {
	curr_word.child("definition").text().set(in->Buf);

	update_lexicon_page();

	return 0;
}

void update_lexicon_page() {

	lexlist.clear();
	poslist.clear();

	pugi::xml_node words = dict.child("dictionary").child("lexicon");
	pugi::xml_node poses = dict.child("dictionary").child("partsOfSpeech");

	for (auto it = words.first_child(); it; it = it.next_sibling()) {
		lexlist.push_back(it);
	}
	for (auto it = poses.first_child(); it; it = it.next_sibling()) {
		poslist.push_back(it.child((posname+"Id").c_str()).text().as_int());
	}
}

void update_lexicon_word_prop(pugi::xml_node node) {

	current_word_id = node.child("wordId").text().as_int();

	curr_word = node;

	current_pos_id = node.child(wposid.c_str()).text().as_int();
	//  coninput.resize(strlen(result.child("conWord").first_child().value())+1);
	coninput = node.child("conWord").text().as_string();
	natinput = node.child("localWord").text().as_string();
	proinput = node.child("pronunciation").text().as_string();
	definput = node.child("definition").text().as_string();
	isautogen = !node.child("autoDeclOverride").text().as_bool();
	isautoproc = !node.child("wordProcOverride").text().as_bool();
}

void fix_lexicon_word_prop() { update_lexicon_word_prop(lexlist[0]); }

pugi::xml_node create_entry() {

	int new_id = find_new_id();
	pugi::xml_node word =
	    dict.child("dictionary").child("lexicon").append_child("word");
	word.append_child("wordId").text().set(new_id);
	word.append_child("localWord").text().set("");
	word.append_child("conWord").text().set("");
	word.append_child(wposid.c_str()).text().set("");
	word.append_child("pronunciation").text().set("");
	word.append_child("definition").text().set("");
	word.append_child("wordProcOverride").text().set("F");
	word.append_child("autoDeclOverride").text().set("F");
	word.append_child("wordRuleOverride").text().set("F");
	word.append_child("wordClassCollection").text().set("");
	word.append_child("wordClassTextValueCollection").text().set("");
	word.append_child("wordEtymologyNotes").text().set("");

	return word;
}

extern ImFont *imconfont;

int scroll = 0;

bool open_conjugator = false;

struct regex_w_order {
	std::string in;
	int order;
};

struct sort_by_e_order {
	bool operator()(struct regex_w_order a, struct regex_w_order b) const {
		return a.order < b.order;
	}
};

std::regex regex_from_map(
    const std::map<struct regex_w_order, std::string, sort_by_e_order> map) {
	std::string pattern_str = "(";
	auto it = map.begin();
	if (it != map.end()) {

		pattern_str += "(";
		pattern_str += it->first.in;
		pattern_str += ")";
		for (++it; it != map.end(); ++it) {
			pattern_str += "|";
			pattern_str += "(";
			pattern_str += it->first.in;
			pattern_str += ")";
		}
	}
	pattern_str += ")";
			std::cout << "" << pattern_str << std::endl;

	return std::regex(pattern_str);
}

std::string custom_regex_replace(
    const std::string &text,
    std::map<struct regex_w_order, std::string, sort_by_e_order>
	replacement_map,
    std::map<std::string, int> order) {

	auto regex = regex_from_map(replacement_map);
	std::string result;
	std::sregex_token_iterator it(text.begin(), text.end(), regex);
	std::sregex_token_iterator end;

	size_t last_pos = 0;
	for (; it != end; ++it) {
		//  result += text.substr(last_pos, it->position() - last_pos);

		std::string match_res(it->first, text.end());

		std::string key = it->str();
			std::cout << "TEXT" << text << std::endl;

		for (auto mit = replacement_map.begin(); mit != replacement_map.end(); ++mit) {
			std::smatch submatch;

			if (std::regex_search(match_res, submatch,
					      std::regex(mit->first.in))) {
				if (submatch.position() == 0) {
					key = mit->first.in;
					break;
				}
			}
		}
		result += replacement_map.at({key, order[key]});
		//    last_pos = it->position() + it->length();
	}
	//  result += text.substr(last_pos, text.size() - last_pos);

	return result;
}

void draw_lexicon_page() {

	ImVec2 pos = ImGui::GetCursorScreenPos();
	ImVec2 sz = ImGui::GetWindowSize();
	ImVec2 ratio = ImVec2(sz.x / 1280, sz.y / 720);

	static int items_current = 0;

	ImGui::SetCursorScreenPos(ImVec2(pos.x + 202 * ratio.x, 22));

	if (imconfont != 0)
		ImGui::PushFont(imconfont);

	ImGui::BeginGroup();

	if(ImGui::BeginListBox(" ", ImVec2(400 * ratio.x, 620 * ratio.y))){

	static bool selected;

	

	for (auto i = dict.child("dictionary")
			  .child("lexicon")
			  .children("word")
			  .begin();
	     i !=
	     dict.child("dictionary").child("lexicon").children("word").end();
	     ++i) {

		int i_word_id = i->child("wordId").text().as_int();

		selected = (i_word_id == current_word_id);

		if (ImGui::Selectable(
			(std::string(i->child("conWord").text().as_string()) +
			 " ##" + std::to_string(i_word_id))
			    .c_str(),
			&selected)) {
			// if(ImGui::IsMouseClicked(ImGuiMouseButton_Left)){
			update_lexicon_word_prop(*i);
			//}
		}

		if (scroll &&
		    (scroll - 1) == std::distance(dict.child("dictionary")
						      .child("lexicon")
						      .children("word")
						      .begin(),
						  i)) {
			ImGui::SetScrollHereY(0);
		}
	}

	ImGui::EndListBox();
    }

	if (ImGui::Button("New word", ImVec2(ratio.x * 133, 40 * ratio.y))) {
		;

		curr_word = create_entry();

		current_word_id = curr_word.child("wordId").text().as_int();

		update_lexicon_page();
		update_lexicon_word_prop(curr_word);
	}

	ImGui::SameLine();

	if (ImGui::Button("Delete word", ImVec2(ratio.x * 133, 40 * ratio.y))) {
		;
        pugi::xml_node old = curr_word;

		if(!(curr_word = curr_word.previous_sibling())){
                old.parent().remove_child(old);
                curr_word = dict.child("dictionary").child("lexicon").first_child();
        }else{
                old.parent().remove_child(old);
        }
		current_word_id = curr_word.child("wordId").text().as_int();

		update_lexicon_page();
		update_lexicon_word_prop(curr_word);
	}

	ImGui::EndGroup();

	ImGui::SetCursorScreenPos(ImVec2(pos.x + 604 * ratio.x, 22));
	ImGui::BeginGroup();

	if (ImGui::InputText("##Conword", &coninput,
			     ImGuiInputTextFlags_CallbackEdit,
			     contextin_callback)) {
	}
	if (imconfont)
		ImGui::PopFont();

	// ImGui::SetCursorScreenPos(ImVec2(pos.x+202*ratio.x, 22 +
	// 620*ratio.y));

	if (ImGui::InputText("##Natword", &natinput,
			     ImGuiInputTextFlags_CallbackEdit,
			     nattextin_callback)) {
	}

	//  ImGui::SetCursorScreenPos(ImVec2(pos.x+604*ratio.x, 22 + 60));

	if (isautoproc) {
		std::string disp =
		    curr_word.child("conWord").text().as_string();

		if (!dict.child("dictionary")
			 .child(procol.c_str())
			 .child("proGuideRecurse")
			 .text()
			 .as_bool()) {

			std::map<struct regex_w_order, std::string,
				 sort_by_e_order>
			    replacement_map;

			int count = 0;

			std::map<std::string, int> ordermap;

			for (auto it = dict.child("dictionary")
					   .child(procol.c_str())
					   .children("proGuide")
					   .begin();
			     it != dict.child("dictionary")
				       .child(procol.c_str())
				       .children("proGuide")
				       .end();
			     ++it) {
				replacement_map[{it->child("proGuideBase")
						     .text()
						     .as_string(),
						 ++count}] =
				    it->child("proGuidePhon")
					.text()
					.as_string();
				ordermap[it->child("proGuideBase")
					     .text()
					     .as_string()] = {count};
			}
			if(!replacement_map.empty() || !ordermap.empty()){
			disp = custom_regex_replace(disp, replacement_map,
						    ordermap);
			}
		} else {
			int match = 0;

			std::string disp_org;

			while (disp_org != disp) {
				disp_org = disp;
				for (auto it =
					 dict.child("dictionary")
					     .child(procol.c_str())
					     .children("proGuide")
					     .begin();
				     it != dict.child("dictionary")
					       .child(procol.c_str())
					       .children("proGuide")
					       .end();
				     ++it) {
					disp = std::regex_replace(
					    disp,
					    std::regex(it->child("proGuideBase")
							   .text()
							   .as_string()),
					    it->child("proGuidePhon")
						.text()
						.as_string());
				}
			}
		}
		ImGui::InputText("##Pronunciation",&disp, ImGuiInputTextFlags_ReadOnly);
        curr_word.child("pronunciation").text().set(disp.c_str());
	} else {
		if (ImGui::InputText("##Pronunciation", &proinput,
				     ImGuiInputTextFlags_CallbackEdit,
				     protextin_callback)) {
		}
	}

	// ImGui::SetCursorScreenPos(ImVec2(pos.x+604*ratio.x, 22 + 90));

	if (ImGui::BeginCombo("##Part of Speech",
			      find_pos_from_pos_id(current_pos_id)
				  .child((posname + "Name").c_str())
				  .first_child()
				  .value())) {

		static bool pos_selected = false;

		for (auto i = poslist.begin(); i != poslist.end(); ++i) {
			ImGui::Selectable(
			    (std::string(find_pos_from_pos_id(*i)
						 .child((posname + "Name").c_str())
					     .first_child()
					     .value()) +
			     " ")
				.c_str(),
			    &pos_selected);
			if (pos_selected) {
				current_pos_id = *i;

				curr_word.child(wposid.c_str()).text().set(*i);
			}

			pos_selected = false;
		}

		ImGui::EndCombo();
	}

	ImGui::Separator();

	ImGui::InputTextMultiline("##Definition", &definput, ImVec2(0, 0),
				  ImGuiInputTextFlags_CallbackEdit,
				  deftextin_callback);

	ImGui::Separator();

	if (ImGui::Button("Conjugations")) {
		open_conjugator = true;
	}

	ImGui::SameLine();

	if (ImGui::Checkbox("Enable declension autogen", &isautogen)) {
		if (isautogen) {
			curr_word.child("autoDeclOverride").text().set("F");
		} else {
			curr_word.child("autoDeclOverride").text().set("T");
		}
	}
	ImGui::SameLine();
	if (ImGui::Checkbox("Enable pronunciation autogen", &isautoproc)) {
		if (isautoproc) {
			curr_word.child("wordProcOverride").text().set("F");
		} else {
			curr_word.child("wordProcOverride").text().set("T");
		}
	}

	if (open_conjugator) {
		lexi_conjugator_dialogue(&open_conjugator);
	}

	ImGui::EndGroup();
}
