/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:58:11 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/27 19:56:43 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Sends one element from stack b to stack a, so that
 * stack a remains sorted in ascending order.
 * 
 * Stack b is always sorted in descending order.
*/
void	ft_send_to_a(t_stack **a, t_stack **b)
{
	t_c		ops;

	ft_memset(&ops, 0, sizeof(t_c));
	ops.size_a = ft_stack_size(*a);
	ops.size_b = ft_stack_size(*b);
	ops.cost = INT_MAX;
	ft_compute_rot_btoa(a, b, &ops);
	ft_exec_ops(a, b, &ops, 'a');
}
