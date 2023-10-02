void draw_pos_page();

#include "pugixml.hpp"

pugi::xml_node find_pos_from_pos_id(int id);
void refresh_poslist();

void pos_reged(bool *open,pugi::xml_node parent, unsigned long id);
