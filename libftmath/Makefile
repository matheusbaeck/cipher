# Makefile for libftmath

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror
LDFLAGS := -lm

# Directories
SRC_DIR := src
OBJ_DIR := .obj
LIB_DIR := .lib

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Output library name
LIB_NAME := libftmath.a
LIB := $(LIB_DIR)/$(LIB_NAME)

# Targets
all: $(LIB)

$(LIB): $(OBJS)
	@mkdir -p $(LIB_DIR)
	ar rcs $(LIB) $(OBJS)
	@echo "Library $(LIB_NAME) created successfully."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re

