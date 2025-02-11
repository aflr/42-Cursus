# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 17:10:32 by aflorido          #+#    #+#              #
#    Updated: 2025/02/08 23:56:55 by aflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables ---
NAME		= test.elf
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
SRC			= main.cpp AMateria.cpp Cure.cpp Ice.cpp Character.cpp MateriaSource.cpp
OBJ			= ${SRC:.cpp=.o}

# --- Targets ---
all: ${NAME}

${NAME}: ${OBJ}
	${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

run: all
	valgrind --leak-check=full --track-origins=yes -q ./${NAME}

.PHONY:	all clean fclean re run
