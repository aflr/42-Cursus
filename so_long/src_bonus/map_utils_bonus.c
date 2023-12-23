/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 22:41:37 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/16 21:01:07 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_resize_map(t_all *all, int new_size)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * new_size);
	if (!new_map)
		ft_error_map("Error\nMalloc failed\n", all);
	i = -1;
	while (++i < all->h)
		new_map[i] = all->map[i];
	free(all->map);
	all->map = new_map;
}
