CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./libcipher/.lib -L./libftmath/.lib
LIBS = -lcipher -lftmath

SRC_DIR = src
OBJ_DIR = .obj

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

TARGET = rsa

DEPS = libftmath/.lib/libftmath.a libcipher/.lib/libcipher.a

all: $(TARGET)

$(TARGET): $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

re_libftmath:
	$(MAKE) -C libftmath

re_libcipher:
	$(MAKE) -C libcipher

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(TARGET)

ffclean: fclean
	@make fclean -C libftmath
	@make fclean -C libcipher
	
re: fclean all

re_all: ffclean re_libftmath re_libcipher all

.PHONY: all clean fclean re_libftmath re_libcipher re

