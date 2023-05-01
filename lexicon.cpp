#include "lexicon.h"
#include <imgui.h>
#include "pugixml.hpp"
#include <iostream>
#include <imgui/misc/cpp/imgui_stdlib.h>

extern pugi::xml_document dict;


std::vector<std::string> lexlist;
std::string coninput;
std::string natinput;
std::string proinput;


std::string current_word_id;

pugi::xml_node find_word_from_conword_id(std::string str){
    pugi::xml_node words = dict.child("dictionary").child("lexicon");

    for(auto it = words.first_child(); it; it = it.next_sibling()){
        std::string val = it.child("wordId").first_child().value();
        if(val == str){
            return it;
        }
    }    int conedit = 0;

    return pugi::xml_node();
}

int contextin_callback(ImGuiInputTextCallbackData *in){
    pugi::xml_node n = find_word_from_conword_id(current_word_id);
    n.child("conWord").first_child().set_value(in -> Buf);

    update_lexicon_page();

    return 0;
}

int nattextin_callback(ImGuiInputTextCallbackData *in){
    pugi::xml_node n = find_word_from_conword_id(current_word_id);
    n.child("localWord").first_child().set_value(in -> Buf);

    update_lexicon_page();

    return 0;
}

int protextin_callback(ImGuiInputTextCallbackData *in){
    pugi::xml_node n = find_word_from_conword_id(current_word_id);
    n.child("pronunciation").first_child().set_value(in -> Buf);

    update_lexicon_page();

    return 0;
}

void update_lexicon_page(){

    lexlist.clear();

    pugi::xml_node words = dict.child("dictionary").child("lexicon");

    for(auto it = words.first_child(); it; it = it.next_sibling()){
        lexlist.push_back(it.child("wordId").first_child().value());
    }

}

void update_lexicon_word_prop(std::string word){
    pugi::xml_node result = find_word_from_conword_id(word);

    current_word_id = word;
  //  coninput.resize(strlen(result.child("conWord").first_child().value())+1);
    coninput = result.child("conWord").first_child().value();
    natinput = result.child("localWord").first_child().value();
    proinput = result.child("pronunciation").first_child().value();


}

void draw_lexicon_page(){

    ImVec2 pos = ImGui::GetCursorScreenPos();
    ImVec2 sz = ImGui::GetWindowSize();
    ImVec2 ratio = ImVec2(sz.x/1280, sz.y/720);

    ImGui::PushItemWidth(100);
    static int items_current=0;

    ImGui::SetCursorScreenPos(ImVec2(pos.x+202*ratio.x, 22));

    ImGui::BeginListBox(" ", ImVec2(200*ratio.x,600*ratio.y));

    static bool selected = false;

    for(auto i = lexlist.begin();i!=lexlist.end();++i){
        ImGui::Selectable(find_word_from_conword_id(*i).child("conWord").first_child().value(), &selected);
        if(selected){
            update_lexicon_word_prop(*i);

        }

        selected = false;

    }
    ImGui::EndListBox();

    ImGui::SetCursorScreenPos(ImVec2(pos.x+424*ratio.x, 22));
    ImGui::PushItemWidth(ratio.x * 400);

    if(ImGui::InputText("Conword",&coninput, ImGuiInputTextFlags_CallbackEdit, contextin_callback)){


    }


    ImGui::SetCursorScreenPos(ImVec2(pos.x+424*ratio.x, 52));
    ImGui::PushItemWidth(ratio.x * 400);

    if(ImGui::InputText("Natword",&natinput, ImGuiInputTextFlags_CallbackEdit, nattextin_callback)){


    }

    ImGui::SetCursorScreenPos(ImVec2(pos.x+424*ratio.x, 82));
    ImGui::PushItemWidth(ratio.x * 400);

    if(ImGui::InputText("Pronunciation",&proinput, ImGuiInputTextFlags_CallbackEdit, protextin_callback)){


    }
}
