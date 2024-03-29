NAME = Account

OBJS_DIR = objs
SRCS = 	tests.cpp \
		Account.cpp

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))

FLAGS = -Wall -Werror -Wextra -std=c++98

RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@c++ $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\n${RED}./Account \n${NC}"

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	@c++ $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all
	@./Account