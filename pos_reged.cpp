#include "pos.h"
#include "imgui.h"
#include <imgui/misc/cpp/imgui_stdlib.h>

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
	
		
		ImGui::End();
	}	
	
}
