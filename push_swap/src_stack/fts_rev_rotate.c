/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:39:20 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/26 13:13:53 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * Shifts down all elements of the stack by 1.
 * The last element becomes the first one.
 */
void	rrx(t_stack **x)
{
	t_stack	*penultimate;

	if (!*x || !(*x)->next)
		return ;
	penultimate = *x;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	penultimate->next->next = *x;
	*x = penultimate->next;
	penultimate->next = NULL;
}

/**
 * Shifts down all elements of stack a by 1.
 * The last element becomes the first one.
 * 
 * @param a The stack to shift down.
 * @param print If true, write "rra\n" on stdout.
 */
void	rra(t_stack **a, t_stack **b, int print)
{
	(void)b;
	rrx(a);
	if (print)
		write(1, "rra\n", 4);
}

/**
 * Shifts down all elements of stack b by 1.
 * The last element becomes the first one.
 * 
 * @param b The stack to shift down.
 * @param print If true, write "rrb\n" on stdout.
 */
void	rrb(t_stack **a, t_stack **b, int print)
{
	(void)a;
	rrx(b);
	if (print)
		write(1, "rrb\n", 4);
}

/**
 * Shifts down all elements of stack a and b by 1.
 * The last element becomes the first one.
 * 
 * @param a The stack to shift down.
 * @param b The stack to shift down.
 * @param print If true, write "rrr\n" on stdout.
 */
void	rrr(t_stack **a, t_stack **b, int print)
{
	rrx(a);
	rrx(b);
	if (print)
		write(1, "rrr\n", 4);
}
