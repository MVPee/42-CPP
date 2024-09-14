NAME := PmergeMe

RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m

OBJS_DIR := objs
SOURCES := 	main.cpp \
			PmergeMe.cpp

OBJECTS := $(addprefix $(OBJS_DIR)/, $(SOURCES:%.cpp=%.o))
DEPENDS := $(addprefix $(OBJS_DIR)/, $(SOURCES:%.cpp=%.d))

CXX := c++
CXXFLAGS := -std=c++98 -Wall -Werror -Wextra -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "\n${RED}./$(NAME)\n${NC}"

-include $(DEPENDS)

$(OBJS_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(OBJS_DIR)
	@$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	@$(RM) -rf $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

run: all
	./$(NAME) 3 5 9 7 4

.PHONY: all clean fclean re run
