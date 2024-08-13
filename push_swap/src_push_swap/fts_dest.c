/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_dest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:39:30 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/28 01:09:43 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Initializes the aux struct with the min, max, min_pos and max_pos values.
 * Also inits the variables i and node.
 */
static void	ft_init_vars(t_aux *aux, t_stack *s, int *i, t_stack **node)
{
	aux->min = ft_min(s);
	aux->max = ft_max(s);
	aux->min_pos = ft_find_pos_min(s);
	aux->max_pos = ft_find_pos_max(s);
	*i = 0;
	*node = s;
}

/**
 * Returns the position the value should be in stack a.
 * It is assumed that A is sorted in ascending order, but
 * not necessarily rotated so that the minimum value is at the top,
 * and the value is not already in the stack.
 * 
 * There are 2 edge cases:
 * Value is less than the top and greater than the bottom -> 0
 * Value is less than the min or greater than the max -> idx of min
 */
int	ft_dest_in_a(t_stack *a, int val)
{
	t_stack	*node;
	t_aux	*aux;
	int		i;

	aux = malloc(sizeof(t_aux));
	if (!aux)
		return (-1);
	ft_init_vars(aux, a, &i, &node);
	if (val < a->num && val > ft_lstlast(a)->num)
		return (free(aux), 0);
	if (val < aux->min || val > aux->max)
	{
		i = aux->min_pos;
		return (free(aux), i);
	}
	while (node->next)
	{
		i++;
		if (val > node->num && val < node->next->num)
			break ;
		node = node->next;
	}
	return (free(aux), i);
}

/**
 * Returns the position the value should be in stack b.
 * It is assumed that B is sorted in descending order,
 * not necessarily rotated so that the maximum value is at the top,
 * and the value is not already in the stack.
 * 
 * There are 2 edge cases:
 * Value is greater than the top and less than the bottom -> 0
 * Value is less than the min or greater than the max -> idx of max
 */
int	ft_dest_in_b(t_stack *b, int val)
{
	t_stack	*node;
	t_aux	*aux;
	int		i;

	aux = malloc(sizeof(t_aux));
	if (!aux)
		return (-1);
	ft_init_vars(aux, b, &i, &node);
	if (val > b->num && val < ft_lstlast(b)->num)
		return (free(aux), 0);
	if (val < aux->min || val > aux->max)
	{
		i = aux->max_pos;
		return (free(aux), i);
	}
	while (node->next)
	{
		i++;
		if (val < node->num && val > node->next->num)
			break ;
		node = node->next;
	}
	return (free(aux), i);
}
