#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cJSON.h"
#include "../include/steam_api.h"

cJSON* parse_steam_json(const char *json_data) {
  cJSON *json = cJSON_Parse(json_data);
  if (json == NULL) {
    fprintf(stderr, "Error parsing JSON\n");
    return NULL;
  }
  return json;
}

Game *get_game_list(cJSON *json, int *game_count) {
  if (json == NULL) {
    return NULL;
  }

  cJSON *response = cJSON_GetObjectItem(json, "response");
  if (response == NULL) {
    printf("No response for the current object\n");
    return NULL;
  }

  cJSON *games = cJSON_GetObjectItem(response, "games");
  if (games == NULL) {
    printf("No games found in the response\n");
    return NULL;
  }

  *game_count = cJSON_GetArraySize(games);
  Game *game_list = malloc(*game_count * sizeof(Game));

  for (int i = 0; i < *game_count; i++) {
    cJSON *game = cJSON_GetArrayItem(games, i);
    if (game == NULL) continue;

    cJSON *appid_json = cJSON_GetObjectItem(game, "appid");
    cJSON *name_json = cJSON_GetObjectItem(game, "name");
    cJSON *playtime_json = cJSON_GetObjectItem(game, "playtime_forever");

    if (name_json == NULL || playtime_json == NULL) continue;

    game_list[i].appid = appid_json->valueint;
    game_list[i].playtime = playtime_json->valueint;
    strncpy(game_list[i].name, name_json->valuestring, sizeof(game_list[i].name));
    
    }
}

void get_recommended_game(cJSON *json) {
  if (json == NULL) {
    return;
  }


}

void free_steam_json(cJSON *json) {
  if (json == NULL) {
    fprintf(stderr, "Attempting to delete NULL pointer\n");
    return;
  }
  cJSON_Delete(json);
}
