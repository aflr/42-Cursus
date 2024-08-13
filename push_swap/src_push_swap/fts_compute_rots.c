/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_compute_rots.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:49:07 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/27 19:57:57 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_update_num(t_c *ops, int num, int idx_a, int idx_b)
{
	ops->num = num;
	ops->idx_a = idx_a;
	ops->idx_b = idx_b;
}

static void	ft_update_fun_cost(t_c *ops)
{
	t_c	tmp;

	ft_memset(&tmp, 0, sizeof(t_c));
	tmp.cost = INT_MAX;
	if (ft_imax(ops->idx_a, ops->idx_b) < tmp.cost)
		ft_update_rarb(ops, &tmp);
	if (ft_imax(ops->size_a - ops->idx_a, ops->size_b - ops->idx_b) < tmp.cost)
		ft_update_rrarrb(ops, &tmp);
	if (ops->idx_a + ops->size_b - ops->idx_b < tmp.cost)
		ft_update_rarrb(ops, &tmp);
	if (ops->size_a - ops->idx_a + ops->idx_b < tmp.cost)
		ft_update_rrarb(ops, &tmp);
	if (tmp.cost < ops->cost)
	{
		ops->cost = tmp.cost;
		ops->f1 = tmp.f1;
		ops->f2 = tmp.f2;
		ops->f1_count = tmp.f1_count;
		ops->f2_count = tmp.f2_count;
	}
}

void	ft_compute_rot_atob(t_stack **a, t_stack **b, t_c *ops)
{
	int		i;
	t_stack	*tmp;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		ft_update_num(ops, tmp->num, i, ft_dest_in_b(*b, tmp->num));
		ft_update_fun_cost(ops);
		tmp = tmp->next;
		i++;
	}
}

void	ft_compute_rot_btoa(t_stack **a, t_stack **b, t_c *ops)
{
	int		i;
	t_stack	*tmp;

	tmp = *b;
	i = 0;
	while (tmp)
	{
		ft_update_num(ops, tmp->num, ft_dest_in_a(*a, tmp->num), i);
		ft_update_fun_cost(ops);
		tmp = tmp->next;
		i++;
	}
}
