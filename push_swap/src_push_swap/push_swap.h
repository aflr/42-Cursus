/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:04:11 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/27 20:27:38 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Standard libraries
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

// My libraries
# include "../src_stack/stack.h"

typedef struct s_aux
{
	int				min;
	int				max;
	int				min_pos;
	int				max_pos;	
}	t_aux;

/**
 * f1, f2, f1_count, f2_count are what is going to be executed.
 * f1 must be ra or rra, f2 must be rb or rrb. Cost is the minimum cost found,
 * corresponding to the operations f1 and f2.
 * 
 * Variables num, idx_x, size_x are used to help compute the cost without
 * repeating the same calculations.
 * 
 * The cost is correct, it takes into account rr or rrr operations.
 * @see ft_compute_rot_atob, ft_compute_rot_btoa, ft_exec_ops
 */
typedef struct s_compute
{
	void	(*f1)(t_stack **, t_stack **, int);
	void	(*f2)(t_stack **, t_stack **, int);
	int		f1_count;
	int		f2_count;
	int		cost;
	int		num;
	int		idx_a;
	int		idx_b;
	int		size_a;
	int		size_b;
}	t_c;

// --- Function prototypes ---

// Main sorting functions

void	init_sort(t_stack **a);
void	ft_sort(t_stack **a, t_stack **b, int size);
void	ft_sort_three(t_stack **a);
void	ft_send_to_a(t_stack **a, t_stack **b);
void	ft_send_to_b(t_stack **a, t_stack **b);
void	ft_center(t_stack **a, const int size);

// Sorting helper functions

void	ft_compute_rot_atob(t_stack **a, t_stack **b, t_c *ops);
void	ft_compute_rot_btoa(t_stack **a, t_stack **b, t_c *ops);
void	ft_exec_ops(t_stack **a, t_stack **b, t_c *ops, char dest);
int		ft_dest_in_a(t_stack *stack, int val);
int		ft_dest_in_b(t_stack *stack, int val);

void	ft_update_rarb(t_c *ops, t_c *tmp);
void	ft_update_rrarrb(t_c *ops, t_c *tmp);
void	ft_update_rarrb(t_c *ops, t_c *tmp);
void	ft_update_rrarb(t_c *ops, t_c *tmp);

// Basically libft functions

void	ft_memset(void *b, int c, size_t len);
int		ft_imin(int a, int b);
int		ft_imax(int a, int b);

#endif