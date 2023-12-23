# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 02:01:49 by aflorido          #+#    #+#              #
#    Updated: 2023/12/16 23:23:08 by aflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables ---
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= so_long
USER		= aflorido
RM			= rm -f

# Libft library
LIBFT_DIR	= libft
LIBFT		= libft.a

# MLX42 library
MLX_DIR		= mlx
MLX			= libmlx42.a

# Frameworks (Using mlx42 from Codam)
FW			= -framework Cocoa -framework OpenGL -framework IOKit
# FW		= -framework OpenGL -framework AppKit -framework IOKit

# Includes and libraries
INC			= -Iinclude -lm\
	-lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" \
	-lmlx42 -lft -L.

# Sources
SRC_DIR		= src
SRC_FILES	= main.c ft_load_textures.c fts_error.c fts_free.c \
	fts_print.c map_parse.c map_solvable.c map_utils.c map_valid.c \
	move_down.c move_left.c move_right.c move_up.c \
	start_game.c ft_random_poke.c move_utils.c
BONUS_DIR	= src_bonus
BONUS_FILES	= main_bonus.c ft_load_textures_bonus.c fts_error_bonus.c \
	fts_free_bonus.c fts_print_bonus.c map_parse_bonus.c map_solvable_bonus.c \
	map_utils_bonus.c map_valid_bonus.c move_down_bonus.c move_left_bonus.c \
	move_right_bonus.c move_up_bonus.c start_game_bonus.c \
	ft_random_poke_bonus.c move_utils_bonus.c ft_enemy_bonus.c

SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS_SRC	= $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))

# Colors
BLACK	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
MAGENTA	= \033[0;35m
CYAN	= \033[0;36m
WHITE	= \033[0;37m
# Styles
RESET	= \033[0m
BOLD	= \033[1m
DIM		= \033[2m
ITALIC	= \033[3m
UNDER	= \033[4m
INVERT	= \033[7m
DASH	= \033[9m

# --- Targets ---

all: $(NAME)

$(NAME):
	@clear
	@echo "$(CYAN)$(ITALIC)Compiling $(NAME)...$(RESET)"
	@make -C $(LIBFT_DIR)
	@mv $(LIBFT_DIR)/$(LIBFT) .
	@make -C $(MLX_DIR)
	@mv $(MLX_DIR)/$(MLX) .
	@$(CC) $(CFLAGS) $(SRC) $(FW) $(INC) -o $(NAME)
	@$(MAKE) ascii

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@echo "$(YELLOW)$@ OK$(RESET)"

fclean: clean
	@$(RM) $(LIBFT)
	@$(RM) $(MLX)
	@$(RM) $(NAME)
	@echo "$(RED)$@ OK$(RESET)"

re: fclean all

bonus:
	@clear
	@echo "$(CYAN)$(ITALIC)Compiling $(NAME) BONUS...$(RESET)"
	@make -C $(LIBFT_DIR)
	@mv $(LIBFT_DIR)/$(LIBFT) .
	@make -C $(MLX_DIR)
	@mv $(MLX_DIR)/$(MLX) .
	@$(CC) $(CFLAGS) $(BONUS_SRC) $(FW) $(INC) -o $(NAME)
	@$(MAKE) ascii_bonus

norm:
	@echo "$(CYAN)$(INVERT)LIBFT$(RESET)"
	@norminette $(LIBFT_DIR)/*.c $(LIBFT_DIR)/*.h
	@echo "$(CYAN)$(INVERT)SRC$(RESET)"
	@norminette $(SRC) include/$(NAME).h
	@echo "$(CYAN)$(INVERT)BONUS$(RESET)"
	@norminette $(BONUS_SRC) include/$(NAME)_bonus.h

invalid:
	@./$(NAME) maps/invalid/bad_char.ber&
	@./$(NAME) maps/invalid/bad_file_extension.txt&
	@./$(NAME) maps/invalid/empty.ber&
	@./$(NAME) maps/invalid/many_exits.ber&
	@./$(NAME) maps/invalid/many_players.ber&
	@./$(NAME) maps/invalid/no_coins.ber&
	@./$(NAME) maps/invalid/no_exit.ber&
	@./$(NAME) maps/invalid/no_player.ber&
	@./$(NAME) maps/invalid/not_enclosed.ber&
	@./$(NAME) maps/invalid/not_rectangular.ber&
	@./$(NAME) maps/invalid/unreachable_coin.ber&
	@./$(NAME) maps/invalid/unreachable_exit.ber&

ascii:
	@echo "$(GREEN)$(BOLD)"
	@echo "                                                               "
	@echo "  #####     ###             #          ###    #     #    ####  "
	@echo " #     #   #   #            #         #   #   ##    #   #    # "
	@echo " #        #     #           #        #     #  # #   #  #       "
	@echo "  #####   #     #           #        #     #  #  #  #  #   ### "
	@echo "       #  #     #           #        #     #  #   # #  #     # "
	@echo " #     #   #   #            #         #   #   #    ##   #    # "
	@echo "  #####     ###             ######     ###    #     #    ##### "
	@echo "                   #######                                     "
	@echo "                                                               "
	@echo "$(RESET)"

ascii_bonus: ascii
	@echo "$(GREEN)$(BOLD)"
	@echo " ######     ###    #     #  #     #   #####  "
	@echo " #     #   #   #   ##    #  #     #  #     # "
	@echo " #     #  #     #  # #   #  #     #  #       "
	@echo " ######   #     #  #  #  #  #     #   #####  "
	@echo " #     #  #     #  #   # #  #     #        # "
	@echo " #     #   #   #   #    ##  #     #  #     # "
	@echo " ######     ###    #     #   #####    #####  "
	@echo "                                             "
	@echo "$(RESET)"

.PHONY: all clean fclean re norm bonus invalid ascii
