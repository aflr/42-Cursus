/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:32:13 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/28 00:33:49 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sorts stack a using stack b. The sort is done in 3 steps:
 * 1. Send from stack a to stack b until 3 elements remain in stack a.
 * 2. Sort the 3 elements in stack a.
 * 3. Send from stack b to stack a until stack b is empty.
 * 
 * @param a		Stack a, which is unsorted.
 * @param b		Stack b, which is empty.
 * @param size	Size of stack a.
 */
void	ft_sort(t_stack **a, t_stack **b, int size)
{
	const int	total_size = size;

	if (size > 3)
	{
		pb(a, b, 1);
		if (size > 4 && size--)
			pb(a, b, 1);
		size--;
		while (!ft_is_sorted(*a) && size-- > 3)
			ft_send_to_b(a, b);
	}
	if (!ft_is_sorted(*a))
		ft_sort_three(a);
	while (*b)
		ft_send_to_a(a, b);
	ft_center(a, total_size);
}

/**
 * Sorts the stack (ascending) when it has 3 elements.
 * It is assumed that the stack is not sorted.
 */
void	ft_sort_three(t_stack **a)
{
	int	min;
	int	max;

	min = ft_min(*a);
	max = ft_max(*a);
	if ((*a)->num == max)
	{
		ra(a, NULL, 1);
		if ((*a)->num != min)
			sa(a, 1);
	}
	else if ((*a)->num == min)
	{
		sa(a, 1);
		ra(a, NULL, 1);
	}
	else if ((*a)->next->num == max)
		rra(a, NULL, 1);
	else if ((*a)->next->num == min)
		sa(a, 1);
}

/*
 * Explanation of ft_sort_three:
 * Remember that the stack is out of order.
 * + If the top is the max (3 1 2 or 3 2 1), rotate (1 2 3 or 2 1 3).
 *		- If the new top is not the min (2 1 3), swap (1 2 3).
 * + If the top is the min (1 3 2), swap (3 1 2) and rotate (1 2 3).
 * + If the top is the middle (2 3 1 or 2 1 3):
 * 		- If (2 3 1), reverse rotate (1 2 3).
 * 		- If (2 1 3), swap (1 2 3).
 */