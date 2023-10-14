# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 02:35:23 by aflorido          #+#    #+#              #
#    Updated: 2023/10/12 13:25:10 by aflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
NAME		= minitalk

# Server specific
S_NAME		= server
S_SRC		= server.c utilities.c
S_OBJ		= $(S_SRC:.c=.o)

# Client specific
C_NAME		= client
C_SRC		= client.c utilities.c
C_OBJ		= $(C_SRC:.c=.o)

# Bonus
S_SRC_BONUS	= server_bonus.c utilities_bonus.c
S_OBJ_BONUS	= $(S_SRC_BONUS:.c=.o)
C_SRC_BONUS	= client_bonus.c utilities_bonus.c
C_OBJ_BONUS	= $(C_SRC_BONUS:.c=.o)

# Colors
GREEN		= "\x1b[32m"
RED			= "\x1b[31m"
RESET		= "\x1b[0m"

# Targets
.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@echo $(GREEN) $(<:.c=.o) compiled correctly $(RESET)

all: $(S_NAME) $(C_NAME)

$(NAME): all

$(S_NAME): $(S_OBJ)
	@$(CC) $(CFLAGS) -o $(S_NAME) $(S_OBJ)
	@echo ✅ $(GREEN) $@ done $(RESET) ✅

$(C_NAME): $(C_OBJ)
	@$(CC) $(CFLAGS) -o $(C_NAME) $(C_OBJ)
	@echo ✅ $(GREEN) $@ done $(RESET) ✅

clean:
	@$(RM) *.o
	@echo 🧹 $(RED) $@ done $(RESET) 🧹

fclean: clean
	@$(RM) $(S_NAME) $(C_NAME)
	@echo 🧹 $(RED) $@ done $(RESET) 🧹

re: fclean all

bonus: $(S_OBJ_BONUS) $(C_OBJ_BONUS)
	@$(CC) $(CFLAGS) -o $(S_NAME) $(S_OBJ_BONUS)
	@echo ✅ $(GREEN) $@ $(S_NAME) done $(RESET) ✅
	@$(CC) $(CFLAGS) -o $(C_NAME) $(C_OBJ_BONUS)
	@echo ✅ $(GREEN) $@ $(C_NAME) done $(RESET) ✅

.PHONY: all clean fclean re bonus .c.o
