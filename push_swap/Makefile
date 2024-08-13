# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 18:02:21 by aflorido          #+#    #+#              #
#    Updated: 2024/07/27 20:48:51 by aflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CHECKER	= checker
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

# Stack
DIR_ST	= src_stack/
SRC_ST	= ft_has_duplicates.c ft_is_sorted.c ft_stack_size.c \
	fts_error.c fts_free.c fts_parse.c \
	fts_push_pop.c fts_push.c fts_rev_rotate.c \
	fts_rotate.c fts_swap.c fts_utils.c \
	fts_find.c
OBJ_ST	= $(addprefix $(DIR_ST),$(SRC_ST:.c=.o))

# Push_swap
DIR_PS	= src_push_swap/
SRC_PS	= ft_center.c ft_gen_utils.c ft_send_to_a.c \
	ft_send_to_b.c fts_compute_rots.c fts_dest.c \
	ft_exec_ops.c fts_sort.c fts_update.c push_swap.c
OBJ_PS	= $(addprefix $(DIR_PS),$(SRC_PS:.c=.o))

# Checker
DIR_CH	= src_checker/
SRC_CH	= checker.c
OBJ_CH	= $(addprefix $(DIR_CH),$(SRC_CH:.c=.o))

# Get_next_line
DIR_GNL	= src_get_next_line/
SRC_GNL	= get_next_line.c get_next_line_utils.c
OBJ_GNL	= $(addprefix $(DIR_GNL),$(SRC_GNL:.c=.o))

# --- Targets ---
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ_ST) $(OBJ_PS)
	$(CC) $(CFLAGS) $(OBJ_ST) $(OBJ_PS) -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(OBJ_GNL) $(OBJ_ST) $(OBJ_CH)
	$(CC) $(CFLAGS) $(OBJ_GNL) $(OBJ_ST) $(OBJ_CH) -o $(CHECKER)

clean:
	$(RM) $(OBJ_ST) $(OBJ_PS) $(OBJ_CH) $(OBJ_GNL)

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

norm:
	@norminette \
	$(wildcard $(DIR_ST)*.[ch]) \
	$(wildcard $(DIR_PS)*.[ch]) \
	$(wildcard $(DIR_CH)*.[ch]) \
	$(wildcard $(DIR_GNL)*.[ch])

.PHONY: all bonus clean fclean re norm