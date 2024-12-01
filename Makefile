CC = gcc
CFLAGS = -Wall -Wextra -pedantic
LIBS = -lcurl  # Only link against curl (not cjson)

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

TARGET = $(BIN_DIR)/game_picker

# Include cJSON.c directly from the src directory
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/steam_api.c $(SRC_DIR)/cJSON.c

# Object files: Include cJSON.o directly
OBJ_FILES = $(OBJ_DIR)/main.o $(OBJ_DIR)/steam_api.o $(OBJ_DIR)/cJSON.o

# Include directory for cJSON headers
LIBS_DIR = include  # cJSON.h is directly in the include directory

# Default rule
all: $(BIN_DIR) $(OBJ_DIR) $(TARGET)

# Create bin directory
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Create obj directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Link object files to create the target executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(TARGET) $(LIBS)  # Only link against curl (no need for -lcjson)

# Rule to create .o files from .c files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(LIBS_DIR) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

# Mark these as phony targets
.PHONY: all clean

