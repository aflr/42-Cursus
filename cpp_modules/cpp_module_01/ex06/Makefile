# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 16:58:54 by aflorido          #+#    #+#              #
#    Updated: 2025/01/22 12:03:48 by aflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables ---
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -Wno-implicit-fallthrough
NAME		= harlFilter
SRC			= main.cpp Harl.cpp
OBJ			= $(SRC:.cpp=.o)

# --- Targets ---
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all
	@valgrind --leak-check=full -q ./$(NAME) "DEBUG"
	@echo "----------------------------------------"
	@valgrind --leak-check=full -q ./$(NAME) "INFO"
	@echo "----------------------------------------"
	@valgrind --leak-check=full -q ./$(NAME) "WARNING"
	@echo "----------------------------------------"
	@valgrind --leak-check=full -q ./$(NAME) "ERROR"
	@echo "----------------------------------------"
	@valgrind --leak-check=full -q ./$(NAME) "NONSENSE"

.PHONY: all clean fclean re run
