/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:40:36 by aflorido          #+#    #+#             */
/*   Updated: 2023/11/26 15:05:46 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * Take the first element at the top of x2 and put it at the top of x1.
 * Do nothing if x2 is empty.
 * 
 * @param x1 Pointer to the stack X1.
 * @param x2 Pointer to the stack X2.
 */
void	px(t_stack **x1, t_stack **x2)
{
	t_stack	*tmp;

	if (!*x2)
		return ;
	tmp = *x2;
	*x2 = (*x2)->next;
	tmp->next = *x1;
	*x1 = tmp;
}

/**
 * Take the first element at the top of b and put it at the top of a.
 * Do nothing if b is empty.
 * 
 * @param a Pointer to the stack A.
 * @param b Pointer to the stack B.
 * @param print If true, write "pa\n" on stdout.
 */
void	pa(t_stack **a, t_stack **b, int print)
{
	px(a, b);
	if (print)
		write(1, "pa\n", 3);
}

/**
 * Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 * 
 * @param a Pointer to the stack A.
 * @param b Pointer to the stack B.
 * @param print If true, write "pb\n" on stdout.
 */
void	pb(t_stack **a, t_stack **b, int print)
{
	px(b, a);
	if (print)
		write(1, "pb\n", 3);
}
