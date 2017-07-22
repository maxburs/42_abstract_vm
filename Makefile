NAME := abstract_vm

SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include

CXXFLAGS := -Wall -Wextra -Werror -pedantic

CXXFLAGS := -I ./$(INCLUDE_DIR)

CXX := clang++

SRC := \
	main.cpp \
	abstract_vm.cpp \

OBJ := $(SRC:.cpp=.o)

HEADERS := $(shell find $(INCLUDE_DIR) -name *.h)

all: $(NAME)

$(NAME): $(addprefix $(BUILD_DIR)/,$(OBJ))
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
