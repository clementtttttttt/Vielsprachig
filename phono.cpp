
#include "phono.hpp"
#include "imgui.h"
#include "lexicon.h"
#include <imgui/misc/cpp/imgui_stdlib.h>

bool recgen = false;

void draw_phono_page() {

	std::string pat, rep;

	int count = 0;

	ImVec2 pos = ImGui::GetCursorScreenPos();
	ImVec2 sz = ImGui::GetWindowSize();
	ImVec2 ratio = ImVec2(sz.x / 1280, sz.y / 720);

	ImGui::SetCursorScreenPos(ImVec2(pos.x + 202 * ratio.x, 22));

	ImGui::BeginGroup();

	ImGui::Text("IPA autogen conf");

	if (ImGui::BeginListBox("##IPA conv. conf",ImVec2(282 * ratio.x, 600 * ratio.y))) {

		ImGui::PushItemWidth( 131 * ratio.x);
		for (auto it = dict.child("dictionary")
				   .child("pronunciationCollection")
				   .children("proGuide")
				   .begin();
		     it != dict.child("dictionary")
			       .child("pronunciationCollection")
			       .children("proGuide")
			       .end();
		     ++it) {
			pat = it->child("proGuideBase").text().as_string();
			rep = it->child("proGuidePhon").text().as_string();
			ImGui::InputText(
			    ("##PHO_BOX " + std::to_string(++count)).c_str(),
			    &pat);
			ImGui::SameLine();
			ImGui::InputText(
			    ("##PHO_BOX_REP " + std::to_string(++count))
				.c_str(),
			    &rep);
		}
		ImGui::PopItemWidth();
		ImGui::EndListBox();
	}

	recgen = 			dict.child("dictionary")
			 .child("pronunciationCollection")
			 .child("proGuideRecurse")
			 .text()
			 .as_bool();

	ImGui::Separator();

	if (ImGui::Checkbox("Enable recursive autogen", &recgen)) {
		if (recgen) {
			dict.child("dictionary")
			 .child("pronunciationCollection")
			 .child("proGuideRecurse")
			 .text()
			 .set("T");
		} else {
			dict.child("dictionary")
			 .child("pronunciationCollection")
			 .child("proGuideRecurse")
			 .text()
			 .set("F");		}
	}

	ImGui::EndGroup();
}
