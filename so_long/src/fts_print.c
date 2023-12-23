/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:10:56 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/14 19:19:27 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_all *all)
{
	ft_putstr("Moves: ");
	ft_putnbr_fd(all->moves, 1);
	ft_putchar('\n');
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
