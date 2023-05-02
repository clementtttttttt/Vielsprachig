#include "lexicon.h"
#include <string>
#include <imgui/imgui.h>
#include <imgui/misc/cpp/imgui_stdlib.h>
#include <regex>
#include <vector>

extern std::vector<int> lexlist;
extern int current_word_id;

std::string search_conword;
int current_find_index=0;
int found_count = 0, found_total = 0;
int search_changed = 0;
extern int scroll;
int empty_conword = 0;

int lexi_find_dialogue(){

            ImGui::Text("Find word...");

            ImGui::Text("Conword");
            ImGui::SameLine();
            if(ImGui::InputText("##CONWORD", &search_conword)){
                search_changed = 1;
            }

            ImGui::Text("%i/%i results", found_count, found_total);

            if(ImGui::Button("Find##button")){
                if(search_changed){
                    search_changed = 0;
                    found_count = 0;
                }


                pugi::xml_node words = dict.child("dictionary").child("lexicon");
                std::regex conword_crit(search_conword);

                if(search_conword.empty()){
                    empty_conword = 1;
                }
                else empty_conword = 0;

                found_total = 0;
                for(auto i=0;i<lexlist.size();++i){
                    pugi::xml_node node = find_word_from_conword_id(lexlist[i]);

                    if((std::regex_search(node.child("conWord").text().as_string(), conword_crit) || empty_conword)){
                        ++found_total;
                    }
                }
                for(auto i=current_find_index;i<lexlist.size();++i){
                    pugi::xml_node node = find_word_from_conword_id(lexlist[i]);

                    int quit=0;

                    if((std::regex_search(node.child("conWord").text().as_string(), conword_crit) || empty_conword)){
                        current_word_id = lexlist[i];
                        current_find_index = i+1;
                        ++found_count;
                        quit=1;
                    }

                    if(i == (lexlist.size()-1)){
                        current_find_index = 0;
                        found_count = 0;

                    }

                    if(quit) break;
                }


                update_lexicon_word_prop(current_word_id);

                scroll = current_find_index;

            }

            ImGui::SameLine();
            if(ImGui::Button("Cancel##button")){
                ImGui::CloseCurrentPopup();
                return 1;
            }
            return 0;
}
