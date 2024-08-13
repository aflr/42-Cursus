/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:28:39 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/27 20:33:45 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_find_pos_val(t_stack *stack, int val)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->num == val)
			return (i);
		stack = stack->next;
	}
	return (-1);
}

int	ft_find_pos_min(t_stack *stack)
{
	int	i;
	int	min;
	int	pos;

	if (!stack)
		return (-1);
	i = 0;
	min = stack->num;
	pos = 0;
	while (stack)
	{
		if (stack->num < min)
		{
			min = stack->num;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

int	ft_find_pos_max(t_stack *stack)
{
	int	i;
	int	max;
	int	pos;

	if (!stack)
		return (-1);
	i = 0;
	max = stack->num;
	pos = 0;
	while (stack)
	{
		if (stack->num > max)
		{
			max = stack->num;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

int	ft_min(t_stack *stack)
{
	int	min;

	min = stack->num;
	while (stack)
	{
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

int	ft_max(t_stack *stack)
{
	int	max;

	max = stack->num;
	while (stack)
	{
		if (stack->num > max)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}
