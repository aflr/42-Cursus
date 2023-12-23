/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 02:25:21 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/10 17:21:35 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
* Checks the arguments, opens the file and parses the map,
* checks if the map is solvable and then starts the game.
*/
int	main(int ac, char **av)
{
	int		fd;
	t_all	all;

	if (ac == 1)
		ft_error("Error\nNo map provided\n");
	if (ac > 2)
		ft_error("Error\nToo many maps provided\n");
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		ft_error("Error\nMap must be .ber\n");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error("Error\nMap not found\n");
	ft_bzero(&all, sizeof(t_all));
	parse_map(fd, &all);
	if (!is_map_solvable(&all))
		ft_error_map("Error\nMap is not solvable\n", &all);
	all.mlx = mlx_init(TILE_W * all.w, TILE_H * all.h, "so_long", false);
	ft_load_textures(&all);
	start_game(&all);
	free_all(&all);
	return (0);
}
