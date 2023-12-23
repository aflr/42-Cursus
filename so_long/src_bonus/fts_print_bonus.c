/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_print_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:10:56 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/16 21:43:20 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
* This function prints the current number of moves top left of the window
* It first sets the background color to black
*/
void	print_moves(t_all *all)
{
	char	*str;

	mlx_image_to_window(all->mlx, all->i_bg, 0, 0);
	str = ft_itoa(all->moves);
	mlx_put_string(all->mlx, str, 10, 5);
	free(str);
}

void	print_winlose(t_all *all)
{
	if (all->game_state == 1)
		ft_putstr("YOU WIN!\n");
	else if (all->game_state == 2)
		ft_putstr("GAME OVER!\n");
	free_all(all);
	exit(0);
}
