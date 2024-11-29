/* 
* game_picker - A tool to recommend games based on your Steam library
*
* Copyright (C) 2024 Thiago L. B. <thiago.lp.bz@gmail.com>
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
* License: GNU General Public License v3.0
*
* Description:
* A simple command-line tool that helps you pick a game from your Steam
* library based on genre preferences and play history.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cjson/cJSON.h"

char* read_file(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }

  fseek(file, 0, SEEK_END);
  long length = ftell(file);
  fseek(file, 0, SEEK_SET);
}

int main() {


 return 0;
}
