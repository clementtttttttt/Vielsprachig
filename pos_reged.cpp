#include "pos.h"
#include "imgui.h"
#include <imgui/misc/cpp/imgui_stdlib.h>
#include <iostream>

std::vector<unsigned int> dim_idz;



pugi::xml_node find_dim_from_id(pugi::xml_node n, unsigned long id){

	auto list = n.children("dimensionNode");
	
	for(auto i = list.begin();i != list.end(); ++i){
			if(i->child("dimensionId").text().as_int() == id){
				return *i;
			}
	}
	return pugi::xml_node();
	
}
			pugi::xml_node rn, t_sel;

void pos_reged(bool *open, pugi::xml_node parent, unsigned long id){
						unsigned long uid = 0;

	if(ImGui::Begin("Declension regex rules", open)){
		unsigned int count =0;
			auto list = parent.children("declensionNode");
			unsigned long dim_ent = 0;
			for(auto it = list.begin();it != list.end();++it){
				if(it->child("declensionTemplate").text().as_int() && it->child("declensionRelatedId").text().as_int() == id){
					ImGui::Text((it->child("declensionText")).text().as_string());
					ImGui::SameLine();
					
					if(dim_idz.size() <= dim_ent){
							dim_idz.resize(dim_ent + 1);
							dim_idz[dim_ent] = 0;
					}
					pugi::xml_node dim;
					if(ImGui::BeginCombo(("## dimejnsionscombo" + std::to_string(dim_ent)).c_str(), (dim = find_dim_from_id(*it, dim_idz[dim_ent])).child("dimensionName").text().as_string())){
							
							auto dim_list = it->children("dimensionNode");
							
							for(auto jit = dim_list.begin(); jit != dim_list.end(); ++jit){
								if(ImGui::Selectable((std::string(jit->child("dimensionName").text().as_string()) + " ##" + std::to_string(++uid)).c_str())){
									dim_idz[dim_ent] = jit->child("dimensionId").text().as_int();
								}	
							}
							
							ImGui::EndCombo();
					}
					++dim_ent;
				}
				
			}
			
			std::string selector = ",";
			for(unsigned long i = 0; i < dim_idz.size(); ++i){
					selector += (std::to_string(dim_idz[i]) + ",");
			}
			
			ImGui::Separator();
			
			auto rules_list = parent.children("decGenRule");
			
			
			if(ImGui::BeginListBox("##rulesbox")){
			unsigned int id = 0;
				for(auto i = rules_list.begin();i != rules_list.end(); ++i){
					
					if(std::string(i->child("decGenRuleComb").text().as_string()) == selector){
							if(ImGui::Selectable((std::string(i->child("decGenRuleName").text().as_string()) +" ##" + std::to_string(++id)).c_str())){
								rn = *i;		
							}
					}
	
				}
				ImGui::EndListBox();
			}
			
			if(ImGui::Button("New Rule")){
				pugi::xml_node new_r = parent.append_child("decGenRule");
				new_r.append_child("decGenRuleName").text().set("(New rule)");
				new_r.append_child("decGenRuleTypeId").text().set(id);
				new_r.append_child("decGenRuleComb").text().set(selector.c_str());
				new_r.append_child("decGenRuleRegex").text().set(".*");
			}
			
			ImGui::SameLine();
			
			if(ImGui::Button("Delete Rule")){
				rn.parent().remove_child(rn);
			}
			
			ImGui::Separator();
			
			std::string rule_name = rn.child("decGenRuleName").text().as_string();
			
			ImVec2 pos = ImGui::GetCursorScreenPos();
			ImGui::InputText(("##name"), &rule_name);

			if (rule_name.empty()) {

				ImGui::SameLine();

				ImGui::SetCursorScreenPos(ImVec2(pos.x + 4, pos.y));
		// Particular widget styling
				ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(128, 128, 128, 255));
				ImGui::Text("Regex rule name goes here");
				ImGui::PopStyleColor();
			}	
			
			std::string rule_filter = rn.child("decGenRuleRegex").text().as_string();
			
			pos = ImGui::GetCursorScreenPos();
			ImGui::InputText("##filters", &rule_filter);

			if (rule_filter.empty()) {

				ImGui::SameLine();

				ImGui::SetCursorScreenPos(ImVec2(pos.x + 4, pos.y));
		// Particular widget styling
				ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(128, 128, 128, 255));
				ImGui::Text("Regex rule filter goes here");
				ImGui::PopStyleColor();
			}	
			
			auto rule_trans = rn.children("decGenTrans");
			
			if(ImGui::BeginListBox("## TRANZ")){
				unsigned int anotheruid = 0;
				for(auto rti = rule_trans.begin(); rti != rule_trans.end(); ++rti){
					std::string reg = rti->child("decGenTransRegex").text().as_string();
					std::string rep = rti->child("decGenTransReplace").text().as_string();
					
					if(ImGui::InputText(("## sdiflisdhfluhuioP" + std::to_string(++anotheruid)).c_str(), &reg)){
						rti->child("decGenTransRegex").text().set(reg.c_str());
						
					}
										if(ImGui::IsItemFocused()){
													t_sel = *rti;

					}
					ImGui::SameLine();
					if(ImGui::InputText(("## buggerall" + std::to_string(++anotheruid)).c_str(), &rep)){
						rti->child("decGenTransReplace").text().set(rep.c_str());
					}	
					if(ImGui::IsItemFocused()){
													t_sel = *rti;

					}
				}
			
				ImGui::EndListBox();
			}
			if(ImGui::Button("New Transform")){
				pugi::xml_node new_r = rn.append_child("decGenTrans");
				new_r.append_child("decGenTransRegex");
				new_r.append_child("decGenTransReplace");	
			}
			
			ImGui::SameLine();
			
			if(ImGui::Button("Delete Transform")){
				t_sel.parent().remove_child(t_sel);
			}
			

		
		ImGui::End();
	}	
	
}
