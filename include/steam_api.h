#ifndef STEAM_API_H
#define STEAM_API_H

#include "cJSON.h"

typedef struct {
    int appid;
    char name[256];
    int playtime;
    char genre[256];
} Game;

cJSON* parse_steam_json(const char *json_data);

Game *get_game_list(cJSON *json, int *game_list);
void free_steam_json(cJSON *json);

#endif
