#include "lexicon.h"
#include <imgui/imgui.h>
#include <imgui/misc/cpp/imgui_stdlib.h>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

extern std::vector<pugi::xml_node> lexlist;
extern int current_word_id;
extern pugi::xml_node curr_word;

std::string search_conword;
std::string search_natword;
std::string search_pronun;
std::string search_definition;

int current_find_index = 0;
int found_count = 0, found_total = 0;
int search_changed = 0;
extern int scroll;
bool empty_conword = false;
bool empty_natword = false;
bool empty_definition = false;
bool empty_pronun = false;
bool match_case = false;

int lexi_find_dialogue() {

	ImGuiIO io = ImGui::GetIO();

	ImGui::Text("Conword");
	ImGui::SameLine(150);
	if (ImGui::InputText("##CONWORD", &search_conword)) {
		search_changed = 1;
	}

	ImGui::Text("Locword");
	ImGui::SameLine(150);
	if (ImGui::InputText("##LOCWORD", &search_natword)) {
		search_changed = 1;
	}

	ImGui::Text("Pronunciation");
	ImGui::SameLine(150);
	if (ImGui::InputText("##PROWORD", &search_pronun)) {
		search_changed = 1;
	}

	ImGui::Text("Definition");
	ImGui::SameLine(150);
	if (ImGui::InputText("##DEFINITION", &search_definition)) {
		search_changed = 1;
	}

	ImGui::Text("%i/%i results", found_count, found_total);

	ImGui::Separator();

	if (ImGui::Checkbox("Match case", &match_case)) {
		search_changed = 1;
	}

	ImGui::Separator();

	if (ImGui::Button("Find \(f2\)##button") ||
	    ImGui::IsKeyPressed(ImGuiKey_F2)) {

		if (search_changed) {
			search_changed = 0;
			found_count = 0;
		}

		pugi::xml_node words =
		    dict.child("dictionary").child("lexicon");
		std::regex conword_crit(search_conword,
					!match_case ? std::regex::icase
						    : std::regex::collate);
		std::regex natword_crit(search_natword,
					!match_case ? std::regex::icase
						    : std::regex::collate);
		std::regex defword_crit(search_definition,
					!match_case ? std::regex::icase
						    : std::regex::collate);
		std::regex pronun_crit(search_pronun,
				       !match_case ? std::regex::icase
						   : std::regex::collate);

		empty_conword = search_conword.empty();
		empty_natword = search_natword.empty();
		empty_definition = search_definition.empty();
		empty_pronun = search_pronun.empty();

		found_total = 0;
		for (auto i = 0; i < lexlist.size(); ++i) {
			pugi::xml_node node = lexlist[i];

			if ((std::regex_search(
				 node.child("conWord").text().as_string(),
				 conword_crit) ||
			     empty_conword) &&
			    (std::regex_search(
				 node.child("localWord").text().as_string(),
				 natword_crit) ||
			     empty_natword) &&
			    (std::regex_search(
				 node.child("pronunciation").text().as_string(),
				 pronun_crit) ||
			     empty_pronun) &&
			    (std::regex_search(
				 node.child("definition").text().as_string(),
				 defword_crit) ||
			     empty_definition)) {
				++found_total;
			}
		}

		if (found_total) {
			for (auto i = current_find_index; i < lexlist.size();
			     ++i) {
				pugi::xml_node node = lexlist[i];

				int quit = 0;

				if ((std::regex_search(node.child("conWord")
							   .text()
							   .as_string(),
						       conword_crit) ||
				     empty_conword) &&
				    (std::regex_search(node.child("localWord")
							   .text()
							   .as_string(),
						       natword_crit) ||
				     empty_natword) &&
				    (std::regex_search(
					 node.child("pronunciation")
					     .text()
					     .as_string(),
					 pronun_crit) ||
				     empty_pronun) &&
				    (std::regex_search(node.child("definition")
							   .text()
							   .as_string(),
						       defword_crit) ||
				     empty_definition)) {
					current_word_id = lexlist[i]
							      .child("wordId")
							      .text()
							      .as_int();
					curr_word = node;
					current_find_index = i + 1;
					++found_count;
					quit = 1;
				}

				if (i == (lexlist.size() - 1)) {
					current_find_index = 0;
					found_count = 0;
					i = 0;
				}

				if (quit)
					break;
			}
		}

		update_lexicon_word_prop(curr_word);

		scroll = current_find_index;
	}

	ImGui::SameLine();
	if (ImGui::Button("Close##button")) {
		scroll = 0;
		return 1;
	}
	return 0;
}
