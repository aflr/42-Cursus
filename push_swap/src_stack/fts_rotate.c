/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:18:47 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/26 13:13:26 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * Shift up all elements of stack x by 1.
 * The first element becomes the last one.
 * 
 * @param x The stack to shift up.
 */
void	rx(t_stack **x)
{
	t_stack	*last;

	if (!*x || !(*x)->next)
		return ;
	last = *x;
	while (last->next)
		last = last->next;
	last->next = *x;
	*x = (*x)->next;
	last->next->next = NULL;
}

/**
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 * 
 * @param a The stack to shift up.
 * @param print If true, write "ra\n" on stdout.
 */
void	ra(t_stack **a, t_stack **b, int print)
{
	(void)b;
	rx(a);
	if (print)
		write(1, "ra\n", 3);
}

/**
 * Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 * 
 * @param b The stack to shift up.
 * @param print If true, write "rb\n" on stdout.
 */
void	rb(t_stack **a, t_stack **b, int print)
{
	(void)a;
	rx(b);
	if (print)
		write(1, "rb\n", 3);
}

/**
 * Shift up all elements of stack a and b by 1.
 * The first element becomes the last one.
 * 
 * @param a The stack to shift up.
 * @param b The stack to shift up.
 * @param print If true, write "rr\n" on stdout.
 */
void	rr(t_stack **a, t_stack **b, int print)
{
	rx(a);
	rx(b);
	if (print)
		write(1, "rr\n", 3);
}
