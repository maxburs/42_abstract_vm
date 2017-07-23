NAME := avm

SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include

FLAGS := -g -Wall -Wextra -Werror -pedantic -std=c++11 -I ./$(INCLUDE_DIR)

CC := clang++

SRC := \
	main.cpp \
	abstract_vm.cpp \
	operand_factory.cpp

OBJ := $(SRC:.cpp=.o)

HEADERS := $(shell find $(INCLUDE_DIR) -name *.h)

all: $(NAME)

$(NAME): $(addprefix $(BUILD_DIR)/,$(OBJ))
	$(CC) $(FLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(BUILD_DIR)
	$(CC) $(FLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
