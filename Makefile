CC = gcc
CFLAGS = -Wall -Wextra -pedantic
SOURCES = src/main.c include/cjson/cJSON.c
LIBS = -lcurl

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

TARGET = $(BIN_DIR)/game_picker

SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/steam_api.c $(SRC_DIR)/game_storage.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(BIN_DIR) $(OBJ_DIR) $(TARGET)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_DIR)/*.o -o $(TARGET)

$(OBJ_DIR)/$.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(LIBS_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

.PHONY: all clean
