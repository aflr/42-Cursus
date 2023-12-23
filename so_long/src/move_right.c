/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:27:01 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/16 22:37:20 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_all *all)
{
	if (all->map[all->player_y][all->player_x + 1] == '1')
	{
		if (all->player_dir != 'R')
		{
			mlx_image_to_window(all->mlx, all->i02,
				all->player_x * TILE_W, all->player_y * TILE_H);
			mlx_image_to_window(all->mlx, all->i05,
				all->player_x * TILE_W, all->player_y * TILE_H);
			all->player_dir = 'R';
		}
	}
	else
	{
		move_player(all, 1, 0);
		mlx_image_to_window(all->mlx, all->i05,
			all->player_x * TILE_W, all->player_y * TILE_H);
		print_moves(all);
	}
}
