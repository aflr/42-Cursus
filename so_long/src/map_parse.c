/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 03:25:32 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/14 19:23:58 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_map_char(char c)
{
	return (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E');
}

/**
 * This function counts the number of each entity in the map.
 * It also saves the position of the player and the exit.
 * It must always return 0
 */
static int	count_entities(char c, t_all *all, int j)
{
	if (c == 'P')
	{
		all->count_player++;
		all->player_x = j;
		all->player_y = all->h;
	}
	else if (c == 'C')
	{
		all->count_collect++;
		all->coins++;
	}
	else if (c == 'E')
	{
		all->count_exit++;
		all->exit_x = j;
		all->exit_y = all->h;
	}
	return (0);
}

/**
 * This function reads the map from the file and into all->map
 * It also checks for invalid chars and non-rectangular maps
 * Then it checks if it is enclosed in walls and the number of
 * each entity is correct.
 */
void	parse_map(int fd, t_all *all)
{
	char	*line;
	int		j;

	while (get_next_line(fd, &line) || close(fd))
	{
		if (all->h == 0)
			all->w = ft_linelen(line);
		else if (all->w != ft_linelen(line))
			(close(fd), ft_error_map("Error\nMap is not rectangular\n", all));
		j = 0;
		while (line[j] != '\0' && line[j] != '\n')
			if (!is_valid_map_char(line[j++])
				|| count_entities(line[j - 1], all, j - 1))
				(close(fd), ft_error_map("Error\nInvalid map char\n", all));
		ft_resize_map(all, all->h + 1);
		all->map[all->h++] = line;
	}
	if (all->h == 0)
		ft_error_map("Error\nEmpty map\n", all);
	if (!is_map_enclosed(all))
		ft_error_map("Error\nMap is not enclosed\n", all);
	if (!is_entities_correct(all))
		ft_error_map("Error\nMap is not correct\n", all);
}
