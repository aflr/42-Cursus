/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:05:23 by aflorido          #+#    #+#             */
/*   Updated: 2023/11/26 16:08:00 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * Frees the memory allocated for the given stack,
 * including all the nodes in the stack.
 */
void	ft_free(t_stack **x)
{
	t_stack	*tmp;

	if (!x)
		return ;
	while (*x)
	{
		tmp = *x;
		*x = (*x)->next;
		free(tmp);
	}
}

/**
 * Frees the memory allocated for the two given stacks,
 * including all the nodes in each stack.
 */
void	ft_free_all(t_stack **a, t_stack **b)
{
	ft_free(a);
	ft_free(b);
}
