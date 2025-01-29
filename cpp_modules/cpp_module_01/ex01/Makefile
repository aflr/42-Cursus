# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 15:25:24 by aflorido          #+#    #+#              #
#    Updated: 2025/01/14 16:36:02 by aflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables ---
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME		= moarBrainz
SRC			= main.cpp Zombie.cpp zombieHorde.cpp
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
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re run
