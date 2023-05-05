#include "lexicon.h"
#include <imgui.h>
#include <iostream>
#include <imgui/misc/cpp/imgui_stdlib.h>
#include <regex>
#include <unistd.h>

extern pugi::xml_document dict;


std::vector<int> lexlist;
std::vector<int> poslist;

std::string coninput;
std::string natinput;
std::string proinput;

int current_pos_id;

int current_word_id;

extern char *confont;

std::string find_new_id(){
    pugi::xml_node words = dict.child("dictionary").child("lexicon");

    int maxid = 0;

    for(auto it = words.first_child(); it; it = it.next_sibling()){
        int comp = it.child("wordId").text().as_int();
        if(comp > maxid){
            maxid = comp;
        }
    }
    return std::to_string(++maxid);
}


pugi::xml_node find_word_from_conword_id(int id){
    pugi::xml_node words = dict.child("dictionary").child("lexicon");

    for(auto it = words.first_child(); it; it = it.next_sibling()){
        int val = it.child("wordId").text().as_int();
        if(val == id){
            return it;
        }
    }    int conedit = 0;

    return pugi::xml_node();
}

pugi::xml_node find_pos_from_pos_id(int id){
    pugi::xml_node words = dict.child("dictionary").child("partsOfSpeech");

    for(auto it = words.first_child(); it; it = it.next_sibling()){
        int val = it.child("partOfSpeechId").text().as_int();
        if(val == id){
            return it;
        }
    }    int conedit = 0;

    return pugi::xml_node();
}

int contextin_callback(ImGuiInputTextCallbackData *in){
    pugi::xml_node n = find_word_from_conword_id(current_word_id);
    n.child("conWord").text().set(in -> Buf);

    update_lexicon_page();

    return 0;
}

int nattextin_callback(ImGuiInputTextCallbackData *in){
    pugi::xml_node n = find_word_from_conword_id(current_word_id);
    n.child("localWord").text().set(in -> Buf);

    update_lexicon_page();

    return 0;
}

int protextin_callback(ImGuiInputTextCallbackData *in){
    pugi::xml_node n = find_word_from_conword_id(current_word_id);
    n.child("pronunciation").text().set(in -> Buf);

    update_lexicon_page();

    return 0;
}

int deftextin_callback(ImGuiInputTextCallbackData *in){
    pugi::xml_node n = find_word_from_conword_id(current_word_id);
    n.child("definition").text().set(in -> Buf);

    update_lexicon_page();

    return 0;
}

void update_lexicon_page(){

    lexlist.clear();
    poslist.clear();

    pugi::xml_node words = dict.child("dictionary").child("lexicon");
    pugi::xml_node poses = dict.child("dictionary").child("partsOfSpeech");


    for(auto it = words.first_child(); it; it = it.next_sibling()){
        lexlist.push_back(it.child("wordId").text().as_int());
    }
    for(auto it = poses.first_child(); it; it = it.next_sibling()){
        poslist.push_back(it.child("partOfSpeechId").text().as_int());
    }

}
    std::string definput;


void update_lexicon_word_prop(int id){

    pugi::xml_node result = find_word_from_conword_id(id);

    current_word_id = id;

    current_pos_id = result.child("wordPosId").text().as_int();
  //  coninput.resize(strlen(result.child("conWord").first_child().value())+1);
    coninput = result.child("conWord").text().as_string();
    natinput = result.child("localWord").text().as_string();
    proinput = result.child("pronunciation").text().as_string();
    definput = result.child("definition").text().as_string();


}

void fix_lexicon_word_prop(){
    update_lexicon_word_prop(lexlist[0]);
}

int create_entry(){
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



    return word.child("wordId").text().as_int();
}


extern ImFont *imconfont;

int scroll = 0;

bool open_conjugator = false;

void draw_lexicon_page(){

    ImVec2 pos = ImGui::GetCursorScreenPos();
    ImVec2 sz = ImGui::GetWindowSize();
    ImVec2 ratio = ImVec2(sz.x/1280, sz.y/720);

    ImGui::PushItemWidth(100);
    static int items_current=0;

    ImGui::SetCursorScreenPos(ImVec2(pos.x+202*ratio.x, 22));

    if(imconfont != 0)
        ImGui::PushFont(imconfont);

    ImGui::BeginGroup();

    ImGui::BeginListBox(" ", ImVec2(400*ratio.x,620*ratio.y));

    static bool selected;

    for(auto i = lexlist.begin();i!=lexlist.end();++i){

        selected = (*i == current_word_id);

        pugi::xml_node res = find_word_from_conword_id(*i);

        if(ImGui::Selectable((std::string(res.child("conWord").text().as_string()) + " ##" + std::string(res.child("wordId").text().as_string())).c_str(), &selected)){
           // if(ImGui::IsMouseClicked(ImGuiMouseButton_Left)){
                update_lexicon_word_prop(*i);
            //}
        }

        if(scroll && (scroll-1) == (i - lexlist.begin())){
            ImGui::SetScrollHereY(0);
        }


    }

    ImGui::EndListBox();


    if(ImGui::Button("New word", ImVec2(ratio.x * 133,40*ratio.y))){;

        int id = create_entry();

        current_word_id = id;

        update_lexicon_page();
        update_lexicon_word_prop(id);
    }

    ImGui::EndGroup();

        ImGui::SetCursorScreenPos(ImVec2(pos.x+604*ratio.x, 22));
    ImGui::BeginGroup();

    ImGui::PushItemWidth(ratio.x * 400);

    if(ImGui::InputText("##Conword",&coninput, ImGuiInputTextFlags_CallbackEdit, contextin_callback)){


    }
    if(imconfont)
        ImGui::PopFont();


   // ImGui::SetCursorScreenPos(ImVec2(pos.x+202*ratio.x, 22 + 620*ratio.y));


    ImGui::PushItemWidth(ratio.x * 400);

    if(ImGui::InputText("##Natword",&natinput, ImGuiInputTextFlags_CallbackEdit, nattextin_callback)){


    }

  //  ImGui::SetCursorScreenPos(ImVec2(pos.x+604*ratio.x, 22 + 60));
    ImGui::PushItemWidth(ratio.x * 400);

    if(ImGui::InputText("##Pronunciation",&proinput, ImGuiInputTextFlags_CallbackEdit, protextin_callback)){


    }

   // ImGui::SetCursorScreenPos(ImVec2(pos.x+604*ratio.x, 22 + 90));
    ImGui::PushItemWidth(ratio.x * 400);

    if(ImGui::BeginCombo("##Part of Speech", find_pos_from_pos_id(current_pos_id).child("partOfSpeechName").first_child().value())){

        static bool pos_selected = false;

        for(auto i = poslist.begin();i!=poslist.end();++i){
            ImGui::Selectable((std::string(find_pos_from_pos_id(*i).child("partOfSpeechName").first_child().value()) + " ").c_str(), &pos_selected);
            if(pos_selected){
                current_pos_id = *i;
                pugi::xml_node n = find_word_from_conword_id(current_word_id);

                n.child("wordPosId").text().set(*i);


            }

            pos_selected = false;

        }

        ImGui::EndCombo();
    }



    ImGui::Separator();

    ImGui::InputTextMultiline("##Definition", &definput, ImVec2(0,0), ImGuiInputTextFlags_CallbackEdit, deftextin_callback);

    ImGui::Separator();

    if(ImGui::Button("Conjugations")){
        open_conjugator = true;
    }

    ImGui::SameLine();

    bool isautogen = find_word_from_conword_id(current_word_id).child("autoDeclOverride").text().as_bool();
    if(ImGui::Checkbox("Override declension autogen", &isautogen)){
        if(isautogen){
            find_word_from_conword_id(current_word_id).child("autoDeclOverride").text().set("T");
        }
        else{
                        find_word_from_conword_id(current_word_id).child("autoDeclOverride").text().set("F");
        }
    }

    if(open_conjugator){
        lexi_conjugator_dialogue(&open_conjugator);
    }

    ImGui::EndGroup();

}
