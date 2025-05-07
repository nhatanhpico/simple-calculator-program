# OS := $(shell uname)

# ifeq ($(OS), Darwin)
#     CC = clang
# else
#     CC = g++
# endif

CC = g++
CFLAGS := -Iinclude -std=c++11
OUT_DIR := out
SRC_DIR := src
OBJ_DIR := obj

$(OBJ_DIR)/%_c.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: mkdir mystack_unitest mycalculator_unitest main

mystack_unitest: $(OBJ_DIR)/mystack_unitest_c.o $(OBJ_DIR)/mystack_c.o
	$(CC) $(CFLAGS) $^ -o $(OUT_DIR)/$@

mycalculator_unitest: $(OBJ_DIR)/mycalculator_unitest_c.o $(OBJ_DIR)/mycalculator_c.o $(OBJ_DIR)/mystack_c.o
	$(CC) $(CFLAGS) $^ -o $(OUT_DIR)/$@

main: $(OBJ_DIR)/main_c.o $(OBJ_DIR)/mycalculator_c.o $(OBJ_DIR)/mystack_c.o
	$(CC) $(CFLAGS) $^ -o $(OUT_DIR)/$@

.PHONY: clean mkdir

mkdir:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OUT_DIR)

clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR)