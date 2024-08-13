/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:35:07 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/27 19:44:25 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_rarb(t_c *ops, t_c *tmp)
{
	tmp->f1 = ra;
	tmp->f2 = rb;
	tmp->f1_count = ops->idx_a;
	tmp->f2_count = ops->idx_b;
	tmp->cost = ft_imax(tmp->f1_count, tmp->f2_count);
}

void	ft_update_rrarrb(t_c *ops, t_c *tmp)
{
	tmp->f1 = rra;
	tmp->f2 = rrb;
	tmp->f1_count = ops->size_a - ops->idx_a;
	tmp->f2_count = ops->size_b - ops->idx_b;
	tmp->cost = ft_imax(tmp->f1_count, tmp->f2_count);
}

void	ft_update_rarrb(t_c *ops, t_c *tmp)
{
	tmp->f1 = ra;
	tmp->f2 = rrb;
	tmp->f1_count = ops->idx_a;
	tmp->f2_count = ops->size_b - ops->idx_b;
	tmp->cost = tmp->f1_count + tmp->f2_count;
}

void	ft_update_rrarb(t_c *ops, t_c *tmp)
{
	tmp->f1 = rra;
	tmp->f2 = rb;
	tmp->f1_count = ops->size_a - ops->idx_a;
	tmp->f2_count = ops->idx_b;
	tmp->cost = tmp->f1_count + tmp->f2_count;
}
