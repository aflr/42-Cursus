/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:58:02 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/28 00:45:00 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_join_rarb(t_c *ops)
{
	if (ops->f1_count < ops->f2_count)
	{
		ops->f1 = rr;
		ops->f2_count -= ops->f1_count;
	}
	else if (ops->f1_count > ops->f2_count)
	{
		ops->f2 = rr;
		ops->f1_count -= ops->f2_count;
	}
	else
	{
		ops->f1 = rr;
		ops->f2_count = 0;
	}
}

static void	ft_join_rrarrb(t_c *ops)
{
	if (ops->f1_count < ops->f2_count)
	{
		ops->f1 = rrr;
		ops->f2_count -= ops->f1_count;
	}
	else if (ops->f1_count > ops->f2_count)
	{
		ops->f2 = rrr;
		ops->f1_count -= ops->f2_count;
	}
	else
	{
		ops->f1 = rrr;
		ops->f2_count = 0;
	}
}

void	ft_exec_ops(t_stack **a, t_stack **b, t_c *ops, char dest)
{
	if (ops->f1 == ra && ops->f2 == rb)
		ft_join_rarb(ops);
	else if (ops->f1 == rra && ops->f2 == rrb)
		ft_join_rrarrb(ops);
	while (ops->f1_count--)
		ops->f1(a, b, 1);
	while (ops->f2_count--)
		ops->f2(a, b, 1);
	if (dest == 'a')
		pa(a, b, 1);
	else if (dest == 'b')
		pb(a, b, 1);
}
