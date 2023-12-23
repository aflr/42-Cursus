/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:26:17 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/16 20:18:36 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_image(t_all *all, int x, int y, char c)
{
	if (c == '1')
		mlx_image_to_window(all->mlx, all->i01, x * TILE_W, y * TILE_H);
	else
	{
		mlx_image_to_window(all->mlx, all->i02, x * TILE_W, y * TILE_H);
		if (c == 'P')
			mlx_image_to_window(all->mlx, all->i03, x * TILE_W, y * TILE_H);
		if (c == 'E')
			mlx_image_to_window(all->mlx, all->i07, x * TILE_W, y * TILE_H);
		if (c == 'C')
			mlx_image_to_window(all->mlx, ft_random_poke(all), x * TILE_W,
				y * TILE_H);
	}
}

/*
 * This function initializes the tiles of the map.
 */
static void	init_window(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->h)
	{
		x = 0;
		while (x < all->w)
		{
			ft_put_image(all, x, y, all->map[y][x]);
			x++;
		}
		y++;
	}
}

static void	animate_exit(t_all *all)
{
	if (all->frame % 30 == 0)
		mlx_image_to_window(all->mlx, all->i07,
			all->exit_x * TILE_W, all->exit_y * TILE_H);
	else if (all->frame % 30 == 10)
		mlx_image_to_window(all->mlx, all->i08,
			all->exit_x * TILE_W, all->exit_y * TILE_H);
	else if (all->frame % 30 == 20)
		mlx_image_to_window(all->mlx, all->i09,
			all->exit_x * TILE_W, all->exit_y * TILE_H);
}

/*
 * This function is the main loop of the game.
 * It listens for key presses, updates the game state
 * and renders the game. If the game is over, it exits.
*/
void	ft_game_loop(void *param)
{
	t_all	*all;

	all = (t_all *)param;
	all->frame++;
	if (all->frame % 5)
		return ;
	animate_exit(all);
	if (mlx_is_key_down(all->mlx, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(all->mlx, MLX_KEY_Q))
		(mlx_close_window(all->mlx), free_all(all), exit(0));
	if (mlx_is_key_down(all->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(all->mlx, MLX_KEY_S))
		move_down(all);
	if (mlx_is_key_down(all->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(all->mlx, MLX_KEY_W))
		move_up(all);
	if (mlx_is_key_down(all->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(all->mlx, MLX_KEY_A))
		move_left(all);
	if (mlx_is_key_down(all->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(all->mlx, MLX_KEY_D))
		move_right(all);
	if (all->game_state)
		print_winlose(all);
}

/*
 * This function starts the game.
 * It initializes the window and starts the main loop.
 */
void	start_game(t_all *all)
{
	init_window(all);
	mlx_loop_hook(all->mlx, ft_game_loop, all);
	mlx_loop(all->mlx);
}
//mlx_image_to_window(mlx, img, 0, 0)
