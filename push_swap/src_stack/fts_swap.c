/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:31:08 by aflorido          #+#    #+#             */
/*   Updated: 2023/11/26 15:05:51 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * Swaps the top two nodes of the stack.
 * Does nothing if there is only one or no nodes.
 */
void	sx(t_stack **x)
{
	int	tmp;

	if (!*x || !(*x)->next)
		return ;
	tmp = (*x)->num;
	(*x)->num = (*x)->next->num;
	(*x)->next->num = tmp;
}

/**
 * Swaps the top two nodes of stack a.
 * Does nothing if there is only one or no nodes.
 * 
 * @param a The stack to swap.
 * @param print If true, write "sa\n" on stdout.
 */
void	sa(t_stack **a, int print)
{
	sx(a);
	if (print)
		write(1, "sa\n", 3);
}

/**
 * Swaps the top two nodes of stack b.
 * Does nothing if there is only one or no nodes.
 * 
 * @param b The stack to swap.
 * @param print If true, write "sb\n" on stdout.
 */
void	sb(t_stack **b, int print)
{
	sx(b);
	if (print)
		write(1, "sb\n", 3);
}

/**
 * Swaps the top two nodes of stack a and b.
 * Does nothing if there is only one or no nodes.
 * 
 * @param a The stack to swap.
 * @param b The stack to swap.
 * @param print If true, write "ss\n" on stdout.
 */
void	ss(t_stack **a, t_stack **b, int print)
{
	sx(a);
	sx(b);
	if (print)
		write(1, "ss\n", 3);
}
