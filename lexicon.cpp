#include "lexicon.h"
#include <imgui.h>
#include "pugixml.hpp"
#include <iostream>
#include <imgui/misc/cpp/imgui_stdlib.h>

extern pugi::xml_document dict;


std::vector<std::string> lexlist;
std::vector<std::string> poslist;

std::string coninput;
std::string natinput;
std::string proinput;

int current_pos;

std::string current_word_id;

extern char *confont;

std::string find_new_id(){
    pugi::xml_node words = dict.child("dictionary").child("lexicon");

    int maxid = 0;

    for(auto it = words.first_child(); it; it = it.next_sibling()){
        int comp = std::atoi(it.child("wordId").first_child().value());
        if(comp > maxid){
            maxid = comp;
        }
    }
    return std::to_string(++maxid);
}


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

pugi::xml_node find_pos_from_pos_id(std::string str){
    pugi::xml_node words = dict.child("dictionary").child("partsOfSpeech");

    for(auto it = words.first_child(); it; it = it.next_sibling()){
        std::string val = it.child("partOfSpeechId").first_child().value();
        if(val == str){
            std::cout << val << std::endl;
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
    poslist.clear();

    pugi::xml_node words = dict.child("dictionary").child("lexicon");
    pugi::xml_node poses = dict.child("dictionary").child("partsOfSpeech");


    for(auto it = words.first_child(); it; it = it.next_sibling()){
        lexlist.push_back(it.child("wordId").first_child().value());
    }
    for(auto it = poses.first_child(); it; it = it.next_sibling()){
        poslist.push_back(it.child("partOfSpeechId").first_child().value());
        std::cout << it.child("partOfSpeechId").first_child().value() << std::endl;
    }

}


void update_lexicon_word_prop(std::string word){
    pugi::xml_node result = find_word_from_conword_id(word);

    current_word_id = word;

    current_pos = std::atoi(result.child("wordPosId").first_child().value());
  //  coninput.resize(strlen(result.child("conWord").first_child().value())+1);
    coninput = result.child("conWord").first_child().value();
    natinput = result.child("localWord").first_child().value();
    proinput = result.child("pronunciation").first_child().value();


}

void fix_lexicon_word_prop(){
    update_lexicon_word_prop(lexlist[0]);
}

std::string create_entry(){
    pugi::xml_node word =  dict.child("dictionary").child("lexicon").append_child("word");
    word.append_child("wordId").text().set(find_new_id().c_str());
    word.append_child("localWord").text().set("");
    word.append_child("conWord").text().set("");
    word.append_child("wordPosId").text().set("");
    word.append_child("pronunciation").text().set("");
    word.append_child("definition").text().set("");
    word.append_child("wordProcOverride").text().set("");
    word.append_child("autoDeclOverride").text().set("");
    word.append_child("wordRuleOverride").text().set("");
    word.append_child("wordClassCollection").text().set("");
    word.append_child("wordClassTextValueCollection").text().set("");
    word.append_child("wordEtymologyNotes").text().set("");



    return word.child("wordId").text().as_string();
}


extern ImFont *imconfont;


void draw_lexicon_page(){

    ImVec2 pos = ImGui::GetCursorScreenPos();
    ImVec2 sz = ImGui::GetWindowSize();
    ImVec2 ratio = ImVec2(sz.x/1280, sz.y/720);

    ImGui::PushItemWidth(100);
    static int items_current=0;

    ImGui::SetCursorScreenPos(ImVec2(pos.x+202*ratio.x, 22));

    if(imconfont != 0)
        ImGui::PushFont(imconfont);

    ImGui::BeginListBox(" ", ImVec2(400*ratio.x,620*ratio.y));

    static bool selected = false;

    for(auto i = lexlist.begin();i!=lexlist.end();++i){
        ImGui::Selectable((std::string(find_word_from_conword_id(*i).child("conWord").first_child().value()) + " ").c_str(), &selected);
        if(selected){
            update_lexicon_word_prop(*i);

        }

        selected = false;

    }
    ImGui::EndListBox();

    ImGui::SetCursorScreenPos(ImVec2(pos.x+604*ratio.x, 22));
    ImGui::PushItemWidth(ratio.x * 400);

    if(ImGui::InputText("##Conword",&coninput, ImGuiInputTextFlags_CallbackEdit, contextin_callback)){


    }
    if(imconfont)
        ImGui::PopFont();


    ImGui::SetCursorScreenPos(ImVec2(pos.x+202*ratio.x, 22 + 620*ratio.y));

    if(ImGui::Button("New word", ImVec2(ratio.x * 133,40*ratio.y))){;

        std::string id = create_entry();

        current_word_id = id;

        update_lexicon_page();
        update_lexicon_word_prop(id);
    }

    ImGui::SetCursorScreenPos(ImVec2(pos.x+604*ratio.x, 22 + 30*ratio.y));
    ImGui::PushItemWidth(ratio.x * 400);

    if(ImGui::InputText("##Natword",&natinput, ImGuiInputTextFlags_CallbackEdit, nattextin_callback)){


    }

    ImGui::SetCursorScreenPos(ImVec2(pos.x+604*ratio.x, 22 + 60*ratio.y));
    ImGui::PushItemWidth(ratio.x * 400);

    if(ImGui::InputText("##Pronunciation",&proinput, ImGuiInputTextFlags_CallbackEdit, protextin_callback)){


    }

    pos = ImGui::GetCursorScreenPos();

    ImGui::SetCursorScreenPos(ImVec2(pos.x+604*ratio.x, pos.y + 30* ratio.y));
    ImGui::PushItemWidth(ratio.x * 400);



    if(ImGui::BeginCombo("Part of Speech", find_pos_from_pos_id(std::to_string(current_pos)).child("partOfSpeechName").first_child().value())){

        static bool pos_selected = false;

        for(auto i = poslist.begin();i!=poslist.end();++i){
            ImGui::Selectable((std::string(find_pos_from_pos_id(*i).child("partOfSpeechName").first_child().value()) + " ").c_str(), &pos_selected);
            if(pos_selected){
                current_pos = std::atoi(i->c_str());
                pugi::xml_node n = find_word_from_conword_id(current_word_id);

                n.child("wordPosId").first_child().set_value(i->c_str());


            }

            pos_selected = false;

        }

        ImGui::EndCombo();
    }

}
