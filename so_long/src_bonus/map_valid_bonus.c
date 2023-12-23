/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:00:36 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/16 21:01:09 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * This function checks if the map is enclosed in walls.
 * I consider a map to be enclosed if the first and last
 * rows and columns are all '1'.
 */
int	is_map_enclosed(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->w)
		if (all->map[0][i++] != '1' || all->map[all->h - 1][i - 1] != '1')
			return (0);
	i = 0;
	while (i < all->h)
		if (all->map[i++][0] != '1' || all->map[i - 1][all->w - 1] != '1')
			return (0);
	return (1);
}

/**
* This function checks if the number of each entity is correct.
* The map must contain 1 exit, at least 1 collectible, and 1 starting
* position to be valid.
*/
int	is_entities_correct(t_all *all)
{
	return (all->count_player == 1
		&& all->count_exit == 1
		&& all->count_collect > 0);
}
