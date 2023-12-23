/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:26:23 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/16 22:37:12 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_all *all)
{
	if (all->map[all->player_y + 1][all->player_x] == '1')
	{
		if (all->player_dir != 'D')
		{
			mlx_image_to_window(all->mlx, all->i02,
				all->player_x * TILE_W, all->player_y * TILE_H);
			mlx_image_to_window(all->mlx, all->i03,
				all->player_x * TILE_W, all->player_y * TILE_H);
			all->player_dir = 'D';
		}
	}
	else
	{
		move_player(all, 0, 1);
		mlx_image_to_window(all->mlx, all->i03,
			all->player_x * TILE_W, all->player_y * TILE_H);
		print_moves(all);
	}
}
