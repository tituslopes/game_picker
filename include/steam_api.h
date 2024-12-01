#ifndef STEAM_API_H
#define STEAM_API_H

#include "cJSON.h"

cJSON* parse_steam_json(const char *json_data);

void get_game_list(cJSON *json);
void free_steam_json(cJSON *json);

#endif
