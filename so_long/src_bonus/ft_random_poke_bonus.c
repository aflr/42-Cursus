/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_poke_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:39:12 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/16 21:00:54 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

mlx_image_t	*ft_random_poke(t_all *all)
{
	int			i;

	i = rand() % 11;
	if (i == 0)
		return (all->i11);
	else if (i == 1)
		return (all->i12);
	else if (i == 2)
		return (all->i13);
	else if (i == 3)
		return (all->i14);
	else if (i == 4)
		return (all->i15);
	else if (i == 5)
		return (all->i16);
	else if (i == 6)
		return (all->i17);
	else if (i == 7)
		return (all->i18);
	else if (i == 8)
		return (all->i19);
	else if (i == 9)
		return (all->i20);
	else
		return (all->i21);
}
