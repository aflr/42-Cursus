/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solvable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:58:56 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/14 18:22:45 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_matrix(char **matrix, int i)
{
	while (i >= 0)
		free(matrix[i--]);
	free(matrix);
}

/**
 * This function checks if there are no coins in the map.
 * @return b : 1 if there are no coins, 0 otherwise.
 */
static int	no_coins(char **map, t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (++i < all->h)
	{
		j = -1;
		while (++j < all->w)
			if (map[i][j] == 'C')
				return (0);
	}
	return (1);
}

static char	**ft_clone_map(t_all *all)
{
	char	**clone_map;
	int		i;

	clone_map = malloc(sizeof(char *) * all->h);
	if (!clone_map)
		return (NULL);
	i = 0;
	while (i < all->h)
	{
		clone_map[i] = ft_strdup(all->map[i]);
		if (!clone_map[i])
		{
			ft_free_matrix(clone_map, i);
			return (NULL);
		}
		i++;
	}
	return (clone_map);
}

/**
 * This function uses a flood fill algorithm to fill the map with '*'
 * starting from the player position. If the exit is reached, the map
 * is solvable.
 */
static void	ft_flood_fill(char **map, int x, int y, t_all *all)
{
	if (x < 0 || x >= all->w || y < 0 || y >= all->h || map[y][x] == '1'
		|| map[y][x] == '*')
		return ;
	map[y][x] = '*';
	ft_flood_fill(map, x + 1, y, all);
	ft_flood_fill(map, x - 1, y, all);
	ft_flood_fill(map, x, y + 1, all);
	ft_flood_fill(map, x, y - 1, all);
}

/**
 * This function checks if the map is solvable by using a flood fill algorithm
 */
int	is_map_solvable(t_all *all)
{
	char	**clone_map;

	clone_map = ft_clone_map(all);
	if (!clone_map)
		ft_error_map("Error\nMalloc failed\n", all);
	ft_flood_fill(clone_map, all->player_x, all->player_y, all);
	return (no_coins(clone_map, all)
		&& clone_map[all->exit_y][all->exit_x] == '*');
}
