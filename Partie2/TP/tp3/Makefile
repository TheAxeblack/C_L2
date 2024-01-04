CC = gcc
OPTIONS = -W -Wall -g -std=c89 -pedantic -O3 `pkg-config --cflags MLV`
DEBUG = -W -Wall -pedantic -std=c89 -g `pkg-config --cflags MLV`
MLV = `pkg-config --libs-only-l MLV` `pkg-config --libs-only-other --libs-only-L MLV`

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
BIN_DIR = bin

TXT_FILES = $(wildcard $(SRC_DIR)/*.c)
DAT_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(TXT_FILES))
DEB_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.do, $(TXT_FILES))

.PHONY: all clean prog debug

all: $(BIN_DIR)/prog $(BIN_DIR)/debug

prog: $(BIN_DIR)/prog
	@$<

debug: $(BIN_DIR)/debug
	@$<

$(BIN_DIR)/prog: $(DAT_FILES)
	@$(CC) $(OPTIONS) $^ -o $@ $(MLV)

$(BIN_DIR)/debug: $(DEB_FILES)
	@$(CC) $(DEBUG) $^ -o $@ $(MLV)

$(OBJ_DIR)/%.do: $(SRC_DIR)/%.c
	@$(CC) $(DEBUG) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(OPTIONS) -I$(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*
