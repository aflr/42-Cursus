# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 16:08:56 by aflorido          #+#    #+#              #
#    Updated: 2025/01/14 16:11:55 by aflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME		= references

all: $(NAME)

$(NAME): main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
