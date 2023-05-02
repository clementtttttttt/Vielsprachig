#include "pugixml.hpp"
void update_lexicon_page();
void draw_lexicon_page();
void fix_lexicon_word_prop();
int lexi_find_dialogue();
int lexi_conjugator_dialogue(bool *p_open);
void update_lexicon_word_prop(int id);
pugi::xml_node find_word_from_conword_id(int id);

extern pugi::xml_document dict;

