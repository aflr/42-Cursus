/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:53:51 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/16 22:41:47 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * This function adds an enemy in a "random" position
 * @return 0 if it was added, 1 if it was not
 */
int	add_enemy(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (++i < all->h)
	{
		j = -1;
		while (++j < all->w)
		{
			if (all->map[i][j] == '0')
			{
				all->enemy_x = j;
				all->enemy_y = i;
				return (0);
			}
		}
	}
	return (1);
}

/**
 * This function moves the enemy in the map
 * The enemy moves "randomly", as available
 */
void	move_enemy_dir(t_all *all, int ex, int ey, int dir)
{
	if (dir == 0 && all->map[ey - 1][ex] == '0')
		move_enemy(all, 0, -1);
	else if (dir == 1 && all->map[ey + 1][ex] == '0')
		move_enemy(all, 0, +1);
	else if (dir == 2 && all->map[ey][ex - 1] == '0')
		move_enemy(all, -1, 0);
	else if (dir == 3 && all->map[ey][ex + 1] == '0')
		move_enemy(all, +1, 0);
}

void	move_enemy(t_all *all, int x, int y)
{
	mlx_image_to_window(all->mlx, all->i02,
		all->enemy_x * TILE_W, all->enemy_y * TILE_H);
	all->enemy_x += x;
	all->enemy_y += y;
	mlx_image_to_window(all->mlx, all->i10,
		all->enemy_x * TILE_W, all->enemy_y * TILE_H);
	if (all->enemy_x == all->player_x && all->enemy_y == all->player_y)
		all->game_state = 2;
}
