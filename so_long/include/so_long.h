/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 02:53:03 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/16 20:46:11 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "../libft/libft.h"
# include "../mlx/include/MLX42/MLX42_Input.h"
# include "../mlx/include/MLX42/MLX42.h"

# define TILE_W	64
# define TILE_H	64

// --- Structures ---

// Structure that holds everything, like Norminette intended
typedef struct s_all
{
	// Count entities
	int				count_exit;
	int				count_player;
	int				count_collect;
	// Model
	int				w;
	int				h;
	int				coins;
	int				exit_x;
	int				exit_y;
	int				player_x;
	int				player_y;
	char			player_dir; // 'U' = up, 'D' = down, 'L' = left, 'R' = right
	int				moves;
	int				game_state; // 0 = playing, 1 = win, 2 = lose
	char			**map;
	unsigned long	frame;
	// View
	mlx_t			*mlx;
	mlx_texture_t	*t01;
	mlx_texture_t	*t02;
	mlx_texture_t	*t03;
	mlx_texture_t	*t04;
	mlx_texture_t	*t05;
	mlx_texture_t	*t06;
	mlx_texture_t	*t07;
	mlx_texture_t	*t08;
	mlx_texture_t	*t09;
	mlx_texture_t	*t10;
	mlx_texture_t	*t11;
	mlx_texture_t	*t12;
	mlx_texture_t	*t13;
	mlx_texture_t	*t14;
	mlx_texture_t	*t15;
	mlx_texture_t	*t16;
	mlx_texture_t	*t17;
	mlx_texture_t	*t18;
	mlx_texture_t	*t19;
	mlx_texture_t	*t20;
	mlx_texture_t	*t21;
	mlx_image_t		*i01;
	mlx_image_t		*i02;
	mlx_image_t		*i03;
	mlx_image_t		*i04;
	mlx_image_t		*i05;
	mlx_image_t		*i06;
	mlx_image_t		*i07;
	mlx_image_t		*i08;
	mlx_image_t		*i09;
	mlx_image_t		*i10;
	mlx_image_t		*i11;
	mlx_image_t		*i12;
	mlx_image_t		*i13;
	mlx_image_t		*i14;
	mlx_image_t		*i15;
	mlx_image_t		*i16;
	mlx_image_t		*i17;
	mlx_image_t		*i18;
	mlx_image_t		*i19;
	mlx_image_t		*i20;
	mlx_image_t		*i21;
}	t_all;

// --- Functions ---

// Map functions

void		parse_map(int fd, t_all *all);
void		ft_resize_map(t_all *all, int new_size);
int			is_map_enclosed(t_all *all);
int			is_entities_correct(t_all *all);
int			is_map_solvable(t_all *all);

// Error functions

void		ft_error(char *str);
void		ft_error_map(char *str, t_all *all);
void		ft_error_free(char *str, t_all *all);

// Game functions

void		ft_load_textures(t_all *all);
void		start_game(t_all *all);
void		ft_game_loop(void *param);
mlx_image_t	*ft_random_poke(t_all *all);

// Movement functions

void		move_up(t_all *all);
void		move_down(t_all *all);
void		move_left(t_all *all);
void		move_right(t_all *all);
int			move_player(t_all *all, int x, int y);

// Print functions

void		print_moves(t_all *all);
void		print_winlose(t_all *all);

// Free functions

void		free_all(t_all *all);
void		free_map(t_all *all);
void		free_images(t_all *all);
void		free_textures(t_all *all);

#endif
