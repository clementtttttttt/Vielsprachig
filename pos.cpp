#include "pos.h"
#include "lexicon.h"
#include "imgui.h"
#include <iostream>
#include <iterator>
#include <imgui/misc/cpp/imgui_stdlib.h>

extern std::vector<int> poslist;
extern std::string procol, posname, wposid;
std::string posnameinput,posnoteinput;

int pos_curr_pos_id;
pugi::xml_node pos_curr_decl = pugi::xml_node();

pugi::xml_node find_pos_from_pos_id(int id) {
	pugi::xml_node pos = dict.child("dictionary").child("partsOfSpeech");

	for (auto it = pos.first_child(); it; it = it.next_sibling()) {
		int val = it.child((posname + "Id").c_str()).text().as_int();
		if (val == id) {
			return it;
		}
	}
	int conedit = 0;

	return pugi::xml_node();
}

int postextin_callback(ImGuiInputTextCallbackData *in) {
	find_pos_from_pos_id(pos_curr_pos_id).child((char*)in->UserData).text().set(in->Buf);

	update_lexicon_page();

	return 0;
}

void refresh_poslist(){
	pugi::xml_node poses = dict.child("dictionary").child("partsOfSpeech");
	poslist.clear();

	for (auto it = poses.first_child(); it; it = it.next_sibling()) {
		poslist.push_back(it.child((posname+"Id").c_str()).text().as_int());
	}
}

int find_new_pos_id() {
	pugi::xml_node pos = dict.child("dictionary").child("partsOfSpeech");

	int maxid = 0;

	for (auto it = pos.first_child(); it; it = it.next_sibling()) {
		int comp = it.child((posname + "Id").c_str()).text().as_int();
		if (comp > maxid) {
			maxid = comp;
		}
	}
	return ++maxid;
}

bool dim_open = false;

int find_new_decl_id() {
	pugi::xml_node decl = dict.child("dictionary").child("declensionCollection");

	int maxid = 0;

	for (auto it = decl.first_child(); it; it = it.next_sibling()) {
		int comp = it.child("declensionId").text().as_int();
		if (comp > maxid) {
			maxid = comp;
		}
	}
	return ++maxid;
}

pugi::xml_node create_pos(){
	pugi::xml_node posp = dict.child("dictionary").child("partsOfSpeech");

	pugi::xml_node pos = posp.append_child();

	pos.append_child((posname + "Id").c_str()).text().set(find_new_pos_id());
	pos.append_child((posname + "Name").c_str()).text().set("(New POS)");
	pos.append_child((posname + "Notes").c_str());
	pos.append_child(("definitionMandatory" + posname).c_str());
	pos.append_child(("pronunciationMandatory" + posname).c_str());
	pos.append_child((posname + "Pattern").c_str());
	pos.append_child((posname + "Gloss").c_str());


	return pos;
}

void update_pos_page(){
	refresh_poslist();
	posnameinput = std::string(find_pos_from_pos_id(pos_curr_pos_id).child((posname + "Name").c_str()).text().as_string());


}

			pugi::xml_document::iterator  dim_sel;

void draw_pos_page(){

	ImVec2 pos = ImGui::GetCursorScreenPos();
	ImVec2 sz = ImGui::GetWindowSize();
	ImVec2 ratio = ImVec2(sz.x / 1280, sz.y / 720);

	ImGui::SetCursorScreenPos(ImVec2(pos.x + 202 * ratio.x, 22));

	ImGui::BeginGroup();

	if (ImGui::BeginListBox("##Part of Speech listbox",ImVec2(200* ratio.x, 560 * ratio.y))) {
		static bool pos_selected = false;

		for (auto i = poslist.begin(); i != poslist.end(); ++i) {

			if(*i != pos_curr_pos_id) pos_selected = false;
			else pos_selected = true;

			if(ImGui::Selectable(
			    (std::string(find_pos_from_pos_id(*i)
						 .child((posname + "Name").c_str())
					     .text()
					     .as_string()) +
			     " ")
				.c_str(),
			    &pos_selected)){

				pos_curr_pos_id = *i;
				update_pos_page();
				dim_open = false;
			
			}

		}

        ImGui::EndListBox();
    }

	if (ImGui::Button("New POS", ImVec2(ratio.x * 90, 40 * ratio.y))) {
		;

		pugi::xml_node pos = create_pos();

		pos_curr_pos_id = pos.child((posname + "Id").c_str()).text().as_int();

		update_pos_page();

	}

	ImGui::SameLine();

	if (ImGui::Button("Delete POS", ImVec2(ratio.x * 90, 40 * ratio.y))) {
		;
        pugi::xml_node old = find_pos_from_pos_id(pos_curr_pos_id);
		pugi::xml_node curr = old;

		if(!(curr = curr.previous_sibling())){
                old.parent().remove_child(old);
                curr = dict.child("dictionary").child(posname.c_str()).first_child();
        }else{
                old.parent().remove_child(old);
        }
		pos_curr_pos_id = curr.child((posname + "Id").c_str()).text().as_int();

		update_pos_page();

	}

    ImGui::EndGroup();

	pos.x += (202+202) * ratio.x;

	pos.y = 22;
	ImGui::SetCursorScreenPos(ImVec2(pos.x, pos.y));

	ImGui::BeginGroup();
	ImGui::PushItemWidth(300);

	if (ImGui::InputText("##posname", &posnameinput,
			     ImGuiInputTextFlags_CallbackEdit,
			     postextin_callback, (void*)(posname + "Name").c_str())) {
	}

	//  ImGui::SetCursorScreenPos(ImVec2(pos.x+604*ratio.x, 22 + 60));
	if(posnameinput.empty()){

		ImGui::SameLine();

		ImGui::SetCursorScreenPos(ImVec2(pos.x + 4, pos.y));
// Particular widget styling
		ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(128,128,128,255));
		ImGui::Text("POS name goes here");
		ImGui::PopStyleColor();
	}


	ImGui::InputTextMultiline("##Notes", &posnoteinput, ImVec2(0, 0),
				  ImGuiInputTextFlags_CallbackEdit,
				  postextin_callback, (void*)(posname + "Notes").c_str());

	if(posnoteinput.empty()){

		ImGui::SameLine();

		pos.y = ImGui::GetCursorScreenPos().y;

		ImGui::SetCursorScreenPos(ImVec2(pos.x + 4, pos.y));
// Particular widget styling
		ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(128,128,128,255));
		ImGui::Text("POS notes goes here");
		ImGui::PopStyleColor();

	}
	
	ImGui::Separator();
	
	if(ImGui::BeginListBox("POS declensions")){
			
			pugi::xml_node decls = dict.child("dictionary").child("declensionCollection");
			
			pugi::xml_node it = decls.first_child();
			while(it){
				if(it.child("declensionRelatedId").text().as_int() == pos_curr_pos_id && it.child("declensionTemplate").text().as_int() == 1){
					
					if(ImGui::Selectable((it.child("declensionText").text().as_string() + std::string("## hurr durr")).c_str())){
						
						pos_curr_decl = it;
						dim_open = true;
						
					}
					
				}	
				it = it.next_sibling();
			}
		
			ImGui::EndListBox();
	}

	if(ImGui::Button("New declension")){
		pugi::xml_node decls = dict.child("dictionary").child("declensionCollection");
		pugi::xml_node newd = decls.append_child();
		newd.append_child("declensionRelatedId").text().set(pos_curr_pos_id);
		newd.append_child("declensionTemplate").text().set(1);
		newd.append_child("declensionText").text().set("(New declension)");

	}

	ImGui::SameLine();

	if(ImGui::Button("Delete declension")){
		pos_curr_decl.parent().remove_child(pos_curr_decl);
	}
	

	
	if(dim_open){
		if(ImGui::Begin("Declension dimensions", &dim_open)){
			
			
			ImGui::PushItemWidth(ImGui::GetWindowWidth());
			
			if(ImGui::BeginListBox("Dimensions")){
					int count=0;
					std::string in;
					
					auto rang = pos_curr_decl.children("dimensionNode");
					auto it = rang.begin();
					ImGui::PushItemWidth(ImGui::GetWindowWidth());
					while(it != rang.end()){
						in = it->child("dimensionName").text().as_string();
						if(ImGui::InputText((std::string(" ## ") + std::to_string(count++)).c_str(), &in)){
						
							it->child("dimensionName").text().set(in.c_str());
						}
						if(ImGui::IsItemFocused()) 							dim_sel = *it;
						

					
						++it;
					}
					ImGui::PopItemWidth();
					
					ImGui::EndListBox();
				
			}
			
			ImGui::PopItemWidth();
			ImGui::PushItemWidth(ImGui::GetWindowWidth()*0.95);
			if(ImGui::Button("New")){
				pugi::xml_node dn=pos_curr_decl.append_child("dimensionNode");
				dn.append_child("dimensionName").text().set("(New dimension)");
			}
			ImGui::SameLine();
			
			if(ImGui::Button("Delete")){
				dim_sel->parent().remove_child(*dim_sel);
			}
			
			ImGui::PopItemWidth();
			
			
			ImGui::End();
		}
		
	}
		
		
	

	ImGui::SetCursorScreenPos(ImVec2(pos.x, pos.y));

	ImGui::PopItemWidth();
	ImGui::EndGroup();


}
