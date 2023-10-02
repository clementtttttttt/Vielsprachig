
#include "phono.hpp"
#include "imgui.h"
#include "lexicon.h"
#include <imgui/misc/cpp/imgui_stdlib.h>
#include <iostream>

bool recgen = false;

pugi::xml_node current_pho_ent;

extern std::string procol;

void draw_phono_page() {

	std::string pat, rep;

	int count = 0;

	ImVec2 pos = ImGui::GetCursorScreenPos();
	ImVec2 sz = ImGui::GetWindowSize();
	ImVec2 ratio = ImVec2(sz.x / 1280, sz.y / 720);

	ImGui::SetCursorScreenPos(ImVec2(pos.x + 202 * ratio.x, 22));

	ImGui::BeginGroup();

	ImGui::Text("IPA autogen conf");

	if (ImGui::BeginListBox("##IPA conv. conf", ImVec2(282 * ratio.x, 560 * ratio.y))) {

		ImGui::PushItemWidth(131 * ratio.x);

		for (auto it = dict.child("dictionary")
						   .child(procol.c_str())
						   .children("proGuide")
						   .begin();
			 it != dict.child("dictionary")
					   .child(procol.c_str())
					   .children("proGuide")
					   .end();
			 ++it) {

			pat = it->child("proGuideBase").text().as_string();
			rep = it->child("proGuidePhon").text().as_string();
			if (ImGui::InputText(
					("##PHO_BOX " + std::to_string(++count)).c_str(),
					&pat)) {

				it->child("proGuideBase").text().set(pat.c_str());
			};
			if (ImGui::IsItemActive()) {
				current_pho_ent = *it;
			}
			ImGui::SameLine();
			if (ImGui::InputText(
					("##PHO_BOX_REP " + std::to_string(++count))
						.c_str(),
					&rep)) {
				it->child("proGuidePhon").text().set(rep.c_str());
			}

			if (ImGui::IsItemActive()) {
				current_pho_ent = *it;
			}
		}
		ImGui::PopItemWidth();
		ImGui::EndListBox();
	}

	recgen = dict.child("dictionary")
				 .child(procol.c_str())
				 .child("proGuideRecurse")
				 .text()
				 .as_bool();

	ImGui::Separator();

	if (ImGui::Checkbox("Enable recursive autogen", &recgen)) {
		if (recgen) {
			dict.child("dictionary")
				.child(procol.c_str())
				.child("proGuideRecurse")
				.text()
				.set("T");
		} else {
			dict.child("dictionary")
				.child(procol.c_str())
				.child("proGuideRecurse")
				.text()
				.set("F");
		}
	}

	if (ImGui::Button("New rule")) {
		pugi::xml_node protrans_par = dict.child("dictionary")
										  .child(procol.c_str());

		pugi::xml_node node = protrans_par.append_child("proGuide");

		node.append_child("proGuideBase").text().set("");
		node.append_child("proGuidePhon").text().set("");
	}

	ImGui::SameLine();

	if (ImGui::Button("Delete rule")) {
		current_pho_ent.parent().remove_child(current_pho_ent);
	}

	ImGui::SameLine();

	if (ImGui::Button("^")) {
		current_pho_ent.parent().insert_move_before(current_pho_ent, current_pho_ent.previous_sibling());
	}

	ImGui::SameLine();

	if (ImGui::Button("v")) {
		current_pho_ent.parent().insert_move_after(current_pho_ent, current_pho_ent.next_sibling());
	}

	ImGui::EndGroup();
}
