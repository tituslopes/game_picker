#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cjson/cJSON.h"
#include "../include/steam_api.h"

cJSON* parse_steam_json(const char *json_data) {
  cJSON *json = cJSON_Parse(json_data);
  if (json == NULL) {
    fprintf(stderr, "Error parsing JSON\n");
    return NULL;
  }
  return json;
}

void get_game_list(cJSON *json) {
  if (json == NULL) {
    return;
  }

  cJSON *response = cJSON_GetObjectItem(json, "response");
  if (response == NULL) {
    printf("No response for the current object\n");
    return;
  }

  cJSON *games = cJSON_GetObjectItem(response, "games");
  if (games == NULL) {
    printf("No games found in the response\n");
    return;
  }

  int game_count = cJSON_GetArraySize(games);
  for (int i = 0; i < game_count; i++) {
    cJSON *game = cJSON_GetArrayItem(games, i);
    if (game != NULL) {
      cJSON *name = cJSON_GetObjectItem(game, "name");
      cJSON *playtime = cJSON_GetObjectItem(game, "playtime_forever");

      if (name != NULL && playtime != NULL) {
        printf("Game: %s\nPlaytime %d hours\n", name->valuestring, playtime->valueint / 60);
      }
    }
  }
}

void free_steam_json(cJSON *json) {
  if (json == NULL) {
    fprintf(stderr, "Attempting to delete NULL pointer\n");
    return;
  }
  cJSON_Delete(json);
}
