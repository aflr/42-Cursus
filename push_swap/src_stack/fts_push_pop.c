/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_push_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:12:57 by aflorido          #+#    #+#             */
/*   Updated: 2023/11/26 19:26:35 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * Pushes a new node to the top of the stack.
 * Returns 0 if successful, 1 if malloc failed.
 */
int	ft_push(t_stack **stack, int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (1);
	new->num = num;
	new->next = *stack;
	*stack = new;
	return (0);
}

/**
 * Pops the top node from the stack and returns its value.
 * DANGER! If the stack is empty, calls ft_error().
 */
int	ft_pop(t_stack **stack)
{
	int		num;
	t_stack	*tmp;

	if (!*stack)
		ft_error();
	num = (*stack)->num;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	return (num);
}
