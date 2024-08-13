/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:58:17 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/27 19:57:30 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sends one element from stack a to stack b, so that
 * stack b remains sorted in descending order.
 * 
 * First, the minimum operations to send the element are calculated
 * and stored in the ops structure.
 * Then, the rotations are executed.
*/
void	ft_send_to_b(t_stack **a, t_stack **b)
{
	t_c		ops;

	ft_memset(&ops, 0, sizeof(t_c));
	ops.size_a = ft_stack_size(*a);
	ops.size_b = ft_stack_size(*b);
	ops.cost = INT_MAX;
	ft_compute_rot_atob(a, b, &ops);
	ft_exec_ops(a, b, &ops, 'b');
}
