/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_center.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:09:27 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/27 20:49:32 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Centers the already sorted stack a,
 * so that the minimum value ends at the top.
 * 
 * If the minimum value is in the top half of the stack,
 * it rotates the stack up, otherwise it reverse rotates it.
*/
void	ft_center(t_stack **a, const int size)
{
	int	pos;

	pos = ft_find_pos_min(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, NULL, 1);
	}
	else
	{
		while (pos++ < size)
			rra(a, NULL, 1);
	}
}
