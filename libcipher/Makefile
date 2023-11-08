CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L../libftmath/.lib
LIBS = -lcipher -lftmath

SRC_DIR = src
OBJ_DIR = .obj

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

TARGET = libcipher.a

DEPS = ../libftmath/.lib/libftmath.a

all: $(TARGET)

$(TARGET): $(OBJS) $(DEPS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

recompile_libftmath:
		$(MAKE) -C ../libftmath

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean recompile_libftmath

