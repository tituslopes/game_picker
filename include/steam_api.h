#ifndef STEAM_API_H
#define STEAM_API_H

void get_owned_games(const char *steam_id, const char *api_key);
void parse_games(const char *response);

#endif
