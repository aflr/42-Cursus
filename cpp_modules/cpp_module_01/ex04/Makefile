# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 15:25:24 by aflorido          #+#    #+#              #
#    Updated: 2025/01/22 11:10:09 by aflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables ---
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME		= sed
SRC			= main.cpp
OBJ			= $(SRC:.cpp=.o)

TEST_FILES	= empty.txt tricky.txt lorem.txt

# --- Colors ---
BLUE		= \033[0;34m
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

# --- Targets ---
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(TEST_FILES) $(TEST_FILES:=.replace) $(TEST_FILES:=.sed.replace)

re: fclean all

test: $(NAME) $(TEST_FILES)
	@clear
	@echo "${BLUE}----- Negative tests -----${RESET}"

	@echo "\nNo arguments"
	@echo "./$(NAME)";
	@valgrind -q ./$(NAME) || true

	@echo "\nOne argument";
	@echo "./$(NAME) lorem.txt";
	@valgrind -q ./$(NAME) lorem.txt || true

	@echo "\nTwo arguments";
	@echo "./$(NAME) lorem.txt a";
	@valgrind -q ./$(NAME) lorem.txt a || true

	@echo "\nEmpty target string";
	@echo "./$(NAME) lorem.txt \"\" a";
	@valgrind -q ./$(NAME) lorem.txt "" a || true

	@echo "\nFile not found";
	@echo "./$(NAME) notfound.txt a b";
	@valgrind -q ./$(NAME) notfound.txt a b || true

	@echo "\n${BLUE}----- Positive tests -----${RESET}"

	@echo "\nEmpty file";
	@echo "./$(NAME) empty.txt a b";
	@valgrind -q ./$(NAME) empty.txt a b
	@sed s/a/b/g empty.txt > empty.txt.sed.replace
	@diff empty.txt.replace empty.txt.sed.replace

	@echo "\n1 char -> 1 char";
	@echo "./$(NAME) lorem.txt o 0";
	@valgrind -q ./$(NAME) lorem.txt o 0
	@sed s/o/0/g lorem.txt > lorem.txt.sed.replace
	@diff lorem.txt.replace lorem.txt.sed.replace

	@echo "\n2 chars -> 2 chars";
	@echo "./$(NAME) lorem.txt et 00";
	@valgrind -q ./$(NAME) lorem.txt et 00
	@sed s/et/00/g lorem.txt > lorem.txt.sed.replace
	@diff lorem.txt.replace lorem.txt.sed.replace

	@echo "\nEmpty replacement string";
	@echo "./$(NAME) lorem.txt a \"\"";
	@valgrind -q ./$(NAME) lorem.txt a ""
	@sed s/a//g lorem.txt > lorem.txt.sed.replace
	@diff lorem.txt.replace lorem.txt.sed.replace

	@echo "\n1 char -> 2 chars";
	@echo "./$(NAME) lorem.txt a aa";
	@valgrind -q ./$(NAME) tricky.txt a aa
	@sed s/a/aa/g tricky.txt > tricky.txt.sed.replace
	@diff tricky.txt.replace tricky.txt.sed.replace

	@echo "\n2 chars -> 1 char";
	@echo "./$(NAME) tricky.txt aa a";
	@valgrind -q ./$(NAME) tricky.txt aa a
	@sed s/aa/a/g tricky.txt > tricky.txt.sed.replace
	@diff tricky.txt.replace tricky.txt.sed.replace

empty.txt:
	@$(RM) $@ && touch $@;

tricky.txt:
	@$(RM) $@ && echo "\na\naa\naaa\naaaa\naaaaa\naaaaaa\naaaaaaa\naaaaaaaa\naaaaaaaaa\naaaaaaaaaa\naaaaaaaaaaa" > $@;

lorem.txt:
	@$(RM) $@ && echo "\nLorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do\
	eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad\
	minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip\
	ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate\
	velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat\
	cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id\
	est laborum." > $@;

.PHONY: all clean fclean re test
