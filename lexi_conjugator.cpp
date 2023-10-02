#include "lexicon.h"
#include <imgui/imgui.h>
#include <imgui/misc/cpp/imgui_stdlib.h>
#include <iostream>
#include <regex>
#include <sstream>
#include <vector>

struct dim_sorter {
	inline bool operator()(const pugi::xml_node &struct1,
						   const pugi::xml_node &struct2) {
		return (struct1.child("declensionId").text().as_int()) <
			   (struct2.child("declensionId").text().as_int());
	}
};

extern pugi::xml_node curr_word;

std::vector<pugi::xml_node> find_decl_from_rel_id(int id) {
	pugi::xml_node words =
		dict.child("dictionary").child("declensionCollection");

	std::vector<pugi::xml_node> ret{};

	for (auto it = words.first_child(); it; it = it.next_sibling()) {
		int val = it.child("declensionRelatedId").text().as_int();
		if (val == id && !it.child("dimensionNode")) {
			ret.push_back(it);
		}
	}
	int conedit = 0;

	std::sort(ret.begin(), ret.end(), dim_sorter());

	return ret;
}

void create_conj_entry(std::string dimid) {
	pugi::xml_node ent = dict.child("dictionary")
							 .child("declensionCollection")
							 .append_child("declensionNode");

	ent.append_child("declensionText").text().set("");

	extern int current_word_id;
	ent.append_child("declensionRelatedId").text().set(current_word_id);
	ent.append_child("combinedDimId").text().set(dimid.c_str());

	int maxid = 0;
	for (auto it = dict.child("dictionary")
					   .child("declensionCollection")
					   .first_child();
		 it; it = it.next_sibling()) {
		maxid =
			std::max(maxid, it.child("declensionId").text().as_int());
	}
	ent.append_child("declensionId").text().set(maxid);
}

std::vector<pugi::xml_node> find_rule_from_rel_pos_id(int id) {
	pugi::xml_node words =
		dict.child("dictionary").child("declensionCollection");

	std::vector<pugi::xml_node> ret(0);

	for (auto it = words.first_child(); it; it = it.next_sibling()) {
		int val = it.child("decGenRuleTypeId").text().as_int();
		if (val == id) {
			ret.push_back(it);
		}
	}
	int conedit = 0;

	return ret;
}

std::vector<pugi::xml_node> find_decl_from_rel_pos_id(int id) {
	pugi::xml_node words =
		dict.child("dictionary").child("declensionCollection");

	std::vector<pugi::xml_node> ret(0);

	for (auto it = words.first_child(); it; it = it.next_sibling()) {
		int val = it.child("declensionRelatedId").text().as_int();
		if (val == id && it.child("dimensionNode")) {
			std::cout << id <<std::endl;
			ret.push_back(it);
		}
	}
	int conedit = 0;

	std::sort(ret.begin(), ret.end(), dim_sorter());
	
	return ret;
}

extern int current_pos_id;
extern int current_word_id;

int xidx = 0, yidx = 1, pageidx = 2;

std::vector<std::vector<std::string>> conjs;

int lexi_conjugator_dialogue(bool *p_open) {

	auto list_of_dim = find_decl_from_rel_pos_id(current_pos_id);

	pugi::xml_document placeholder_doc;
	pugi::xml_node placeholder_node =
		placeholder_doc.append_child("placeholder");
	placeholder_node.append_child("dimensionNode");

	placeholder_node.child("dimensionNode").text().set("placeholder");

	int true_size = list_of_dim.size();

	while (list_of_dim.size() < 3) {
		list_of_dim.push_back(placeholder_node);
	}
	if (ImGui::Begin("Conjugator", p_open)) {
		int count = 0;

		if (true_size == 0) {
			ImGui::Text("No conjugations exist for pos.");
			goto break_if_when_ts_0;
		}

		if (ImGui::BeginCombo("Columns", list_of_dim[xidx]
											 .child("declensionText")
											 .text()
											 .as_string())) {
			for (int i = 0; i < list_of_dim.size(); ++i) {
				if (xidx == i)
					continue;
				if (!strcmp(list_of_dim[i]
								.child("dimensionNode")
								.text()
								.as_string(),
							"placeholder"))
					continue;

				if (ImGui::Selectable(
						list_of_dim[i]
							.child("declensionText")
							.text()
							.as_string())) {
					xidx = i;
				}
			}
			ImGui::EndCombo();
		};

		if (true_size >= 2) {
			ImGui::SameLine();

			if (ImGui::BeginCombo("Rows",
								  list_of_dim[yidx]
									  .child("declensionText")
									  .text()
									  .as_string())) {
				for (int i = 0; i < list_of_dim.size(); ++i) {
					if (yidx == i)
						continue;
					if (!strcmp(list_of_dim[i]
									.child("dimensionNode")
									.text()
									.as_string(),
								"placeholder"))
						continue;

					if (ImGui::Selectable(
							list_of_dim[i]
								.child("declensionText")
								.text()
								.as_string())) {
						yidx = i;
					}
				}
				ImGui::EndCombo();
			};
		}

		for (pageidx = 0; pageidx == xidx || pageidx == yidx; ++pageidx)
			;

		ImGui::Separator();
		std::vector<int> list_of_idxs(list_of_dim.size());

		if (ImGui::BeginTabBar("Pages")) {

			for (auto p = list_of_dim[pageidx]
							  .children("dimensionNode")
							  .begin();
				 p != list_of_dim[pageidx]
						  .children("dimensionNode")
						  .end() &&
				 !list_of_dim[pageidx].empty();
				 p++) {
				if (ImGui::BeginTabItem(
						p->child("dimensionName")
							.text()
							.as_string())) {
					list_of_idxs[pageidx] =
						p->child("dimensionId")
							.text()
							.as_int();
					ImGui::EndTabItem();
				}
			}

			ImGui::EndTabBar();
		}

		if (!(xidx == yidx || xidx == pageidx || yidx == pageidx) &&
			ImGui::BeginTable(
				"ConjugTable",
				std::distance(
					list_of_dim[xidx].children("dimensionNode").begin(),
					list_of_dim[xidx].children("dimensionNode").end()) +
					1)) {

			ImGui::TableNextRow();
			int col_idx = 0;
			ImGui::TableSetColumnIndex(col_idx++);
			ImGui::Text("");

			for (auto x = list_of_dim[xidx]
							  .children("dimensionNode")
							  .begin();
				 x != list_of_dim[xidx]
						  .children("dimensionNode")
						  .end() &&
				 !list_of_dim[xidx].empty();
				 x++) {
				ImGui::TableSetColumnIndex(col_idx++);
				ImGui::Text(x->child("dimensionName")
								.text()
								.as_string());
			}
			ImGui::TableNextRow();

			ImGui::TableNextColumn();
			for (auto y = list_of_dim[yidx]
							  .children("dimensionNode")
							  .begin();
				 y != list_of_dim[yidx]
						  .children("dimensionNode")
						  .end() &&
				 !list_of_dim[yidx].empty();
				 y++) {
				ImGui::Text(y->child("dimensionName")
								.text()
								.as_string());
				// ImGui::InputText("", &strs[i]);
			}

			std::vector<pugi::xml_node> ents =
				find_decl_from_rel_id(current_word_id);
			std::vector<pugi::xml_node> rules =
				find_rule_from_rel_pos_id(current_pos_id);

			int id_count = 0;

			for (auto x = list_of_dim[xidx]
							  .children("dimensionNode")
							  .begin();
				 x !=
				 list_of_dim[xidx].children("dimensionNode").end();
				 x++) {
				list_of_idxs[xidx] =
					x->child("dimensionId").text().as_int();

				ImGui::TableNextColumn();

				for (auto y = list_of_dim[yidx]
								  .children("dimensionNode")
								  .begin();
					 y != list_of_dim[yidx]
							  .children("dimensionNode")
							  .end();
					 y++) {
					std::stringstream find_idx;

					list_of_idxs[yidx] =
						y->child("dimensionId")
							.text()
							.as_int();

					for (int t = 0; t < true_size; ++t) {
						if (t < true_size)
							find_idx
								<< ","
								<< list_of_idxs[t];
					}
					find_idx << ",";

					if (curr_word.child("autoDeclOverride")
							.text()
							.as_bool()) {
						int found = 0;
						for (auto i = ents.begin();
							 i != ents.end(); ++i) {
							if (i->child("combinedD"
										 "imId")
									.text()
									.as_string() ==
								find_idx.str()) {
								std::string inp =
									i->child(
										 "decle"
										 "nsion"
										 "Text")
										.text()
										.as_string();
								if (ImGui::InputText(
										(std::string(
											 "#"
											 "#"
											 " "
											 "I"
											 "N"
											 "P"
											 " ") +
										 std::to_string(
											 id_count++))
											.c_str(),
										&inp)) {
									i->child(
										 "declensionText")
										.text()
										.set(
											inp.c_str());
								}
								found = 1;
							}
						}

						if (!found) {
							create_conj_entry(
								find_idx.str());
						}
					} else {
						std::string disp =
							curr_word.child("conWord")
								.text()
								.as_string();
						for (auto i = rules.begin();
							 i != rules.end(); ++i) {
							if (i->child("decGenRul"
										 "eComb")
									.text()
									.as_string() ==
								find_idx.str()) {
								std::regex f_regex(
									i->child(
										 "decGe"
										 "nRule"
										 "Rege"
										 "x")
										.text()
										.as_string());

								if (std::regex_search(
										curr_word
											.child(
												"conWord")
											.text()
											.as_string(),
										f_regex)) {
									for (
										auto rit =
											i->children(
												 "decGenTrans")
												.begin();
										rit !=
										i->children(
											 "decGenTrans")
											.end();
										++rit) {
										std::string regex_str =
											std::string(
												rit->child(
													   "decGenTransRegex")
													.text()
													.as_string());
										if (regex_str ==
											"$") {
											regex_str =
												".$";
											disp +=
												" ";
										}
										std::regex rep =
											std::regex(
												regex_str);
										disp = std::regex_replace(
											disp,
											rep,
											std::string(
												rit->child(
													   "decGenTransReplace")
													.text()
													.as_string()));
									}
								}
							}
						}

						ImGui::Text(disp.c_str());
					}
					// ImGui::InputText("", &strs[i]);
				}
			}
			ImGui::EndTable();
		}
	}
break_if_when_ts_0:
	ImGui::End();
	return 0;
}
