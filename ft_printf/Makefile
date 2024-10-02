# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 10:28:20 by aflorido          #+#    #+#              #
#    Updated: 2024/10/02 17:52:49 by aflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LIBC	= ar -rcs
NAME	= libftprintf.a
RM		= rm -rf

# Mandatory part (unused)
DIR_MAN		= mandatory
SRC_MAN		= ft_printf.c ft_printf_utils.c
OBJ_MAN		= $(addprefix $(DIR_MAN)/,$(SRC_MAN:.c=.o))

# Bonus part
DIR_BON		= bonus
SRC_BON		= ft_printf_bonus.c ft_fs_bonus.c ft_parse_bonus.c \
			ft_printers_1_bonus.c ft_printers_2_bonus.c \
			ft_printf_utils_1_bonus.c ft_printf_utils_2_bonus.c \
			ft_printf_aux_1_bonus.c ft_printf_aux_2_bonus.c
OBJ_BON		= $(addprefix $(DIR_BON)/,$(SRC_BON:.c=.o))

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ_BON)
	$(LIBC) $(NAME) $(OBJ_BON)

clean:
	$(RM) $(OBJ_MAN) $(OBJ_BON)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

bonus: $(NAME)

norm:
	@norminette \
	$(wildcard $(DIR_MAN)/*.[ch]) \
	$(wildcard $(DIR_BON)/*.[ch])

.PHONY: all clean fclean re bonus norm
