#include "backends/imgui_impl_opengl3.h"
#include "hello_imgui/hello_imgui.h"
#include "hello_imgui_assets.h"
#include "imgui.h"
#include <cstdlib>
#include <imgui.h>
#include <iostream>
#include "imgui_default_settings.h"
#include "pugixml.hpp"
#include "embf.h"
#include <archive.h>
#include <archive_entry.h>

#include "lexicon.h"
#include "runner_callbacks.h"
#include "runner_params.h"


enum modes{
    nil, M_LEX,M_PROP
};


int mode = M_PROP;

int popup=0;
std::string errstr;

pugi::xml_document dict;

char * confont;

ImFont *imconfont = 0;

int hasconfont = 0;


void handle_upload_file(std::string const &filename,  // the filename of the file the user selected
    std::string const &mime_type, // the MIME type of the file the user selected, for example "image/png"
    std::string_view buffer,      // the file's content is exposed in this string_view - access the data with buffer.data() and size with buffer.size().
    void *callback_data = nullptr // optional callback data - identical to whatever you passed to handle_upload_file()
  ){
    struct archive *arr = archive_read_new();
    archive_read_support_format_zip(arr);
    int r =archive_read_open_memory(arr, buffer.data(), buffer.size());
    if (r != ARCHIVE_OK){
        popup=1;
        errstr = std::string(archive_error_string(arr));

        archive_free(arr);
        return;
    }

    struct archive_entry *fileentry;

    int foundxml=0;
    imconfont = 0;
    delete [] confont;
    confont = 0;

    hasconfont = 0;

    while(archive_read_next_header(arr, &fileentry) == ARCHIVE_OK){
        if(!strcmp(archive_entry_pathname(fileentry),"PGDictionary.xml")){
            foundxml = 1;

            char* tmpstr = new char[archive_entry_size(fileentry)];

            archive_read_data(arr, tmpstr, archive_entry_size(fileentry));
            std::string dict_stro(tmpstr);

            dict.load_string(tmpstr);

            delete [] tmpstr;



        }
        else if(!strcmp(archive_entry_pathname(fileentry), "conLangFont")){

            delete [] confont;
            confont = new char[archive_entry_size(fileentry)];
            archive_read_data(arr, confont, archive_entry_size(fileentry));
            hasconfont = 1;
        }
        else {
            archive_read_data_skip(arr);
        }
    }

    if (foundxml == 0){
        popup=1;
        errstr = "Cannot find PGDictionary.xml in archive";
        return;
    }

    update_lexicon_page();
    fix_lexicon_word_prop();




}



void maingui(){



    if (ImGui::BeginMainMenuBar())
    {

        if (ImGui::BeginMenu("File"))
        {

            if (ImGui::MenuItem("Open", "Ctrl+O")) {
                  emscripten_browser_file::upload(".pgd", handle_upload_file);
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
            if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
            ImGui::Separator();
            if (ImGui::MenuItem("Cut", "CTRL+X")) {}
            if (ImGui::MenuItem("Copy", "CTRL+C")) {}
            if (ImGui::MenuItem("Paste", "CTRL+V")) {}
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
   // ImGui::BeginGroup();
    ImVec2 pos = ImGui::GetCursorScreenPos();
    ImVec2 sz = ImGui::GetWindowSize();
    ImVec2 ratio = ImVec2(sz.x/1280, sz.y/720);

    ImGui::BeginGroup();
        ImGui::SetCursorScreenPos(ImVec2(pos.x, 22));
        if(ImGui::Button("Lexicon", ImVec2((float)200*ratio.x,(float)120*ratio.y))){
            mode = M_LEX;
        }
        if(ImGui::Button("Properties", ImVec2((float)200*ratio.x,(float)120*ratio.y))){
            mode = M_PROP;
        }


    ImGui::EndGroup();

    if (mode == M_LEX){

        draw_lexicon_page();


    }

    if(popup){
        ImGui::OpenPopup("Error opening file");
    }

    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

    if(ImGui::BeginPopupModal("Error opening file")){
        ImGui::Text("Error: %s", errstr.c_str());
        if (ImGui::Button("OK", ImVec2(120, 0))) { popup = 0; ImGui::CloseCurrentPopup(); }
        ImGui::EndPopup();
    }
    //ImGui::EndGroup();

}

void load_noto_sans(){
        HelloImGui::LoadFontTTF("notosans.ttf", 20, true);

}

void pre_new_frame(){


        if(confont !=0 && imconfont == 0 && hasconfont){
                        ImGuiIO &io = ImGui::GetIO();

                                io.Fonts->Clear();
            load_noto_sans();

            static const ImWchar dummy_ranges[] = { 0x20, 0xFFFF, 0 } ; // Will not be copied by AddFont* so keep in scope.
            imconfont = io.Fonts->AddFontFromMemoryTTF(confont, 20, 20, NULL, dummy_ranges);

            io.Fonts->Build();
            ImGui_ImplOpenGL3_CreateFontsTexture();


        }
        if(confont == 0) imconfont == 0;
}

int main(int , char *[])
{





    auto params = HelloImGui::RunnerParams {.callbacks.ShowGui = maingui, .callbacks.PreNewFrame = pre_new_frame,  .appWindowParams.windowTitle = "Vielsprachig", //.appWindowParams.windowGeometry.sizeAuto = true,
    .appWindowParams.windowGeometry.size = {300,200},  };

    params.callbacks.LoadAdditionalFonts = load_noto_sans;

    HelloImGui::Run(
        params
    );

    return 0;
}
