/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:25:47 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/16 21:46:33 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * This function moves the player in the map by the given x and y increments.
 * It also removes the previous player image, updates structure if coins
 * or the exit are reached, and increments the moves counter.
 */
int	move_player(t_all *all, int x, int y)
{
	mlx_image_to_window(all->mlx, all->i02,
		all->player_x * TILE_W, all->player_y * TILE_H);
	all->player_x += x;
	all->player_y += y;
	if (all->map[all->player_y][all->player_x] == 'C')
	{
		all->map[all->player_y][all->player_x] = '0';
		all->coins--;
		mlx_image_to_window(all->mlx, all->i02,
			all->player_x * TILE_W, all->player_y * TILE_H);
	}
	else if (all->player_y == all->exit_y
		&& all->player_x == all->exit_x
		&& !all->coins)
	{
		all->game_state = 1;
	}
	all->moves++;
	return (1);
}
