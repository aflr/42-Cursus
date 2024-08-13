/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:02:58 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/30 13:39:13 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

// Standard libraries
# include <stdlib.h>
# include <unistd.h>

// My libraries
# include "../src_get_next_line/get_next_line.h"

// Stack structure implemented as a linked list
typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

// --- Function prototypes ---

// Parse functions

t_stack	*parse_stack(char **av, int *error, int free_av);
char	**ft_split(char const *s, char c);

// Error functions

void	ft_error(void);
void	ft_safe_error(t_stack **a, t_stack **b);

// Free functions

void	ft_free(t_stack **a);
void	ft_free_all(t_stack **a, t_stack **b);

// Swap functions

void	sx(t_stack **x);
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);

// Push functions

void	px(t_stack **x1, t_stack **x2);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);

// Rotate functions

void	rx(t_stack **x);
void	ra(t_stack **a, t_stack **b, int print);
void	rb(t_stack **a, t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);

// Reverse rotate functions

void	rrx(t_stack **x);
void	rra(t_stack **a, t_stack **b, int print);
void	rrb(t_stack **a, t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

// Generic push / pop functions

int		ft_push(t_stack **stack, int num);
int		ft_pop(t_stack **stack);

// Algorithm functions

int		ft_stack_size(t_stack *stack);
int		ft_find_pos_val(t_stack *stack, int val);
int		ft_find_pos_min(t_stack *stack);
int		ft_find_pos_max(t_stack *stack);
int		ft_min(t_stack *stack);
int		ft_max(t_stack *stack);
int		ft_is_sorted(t_stack *a);
int		ft_has_duplicates(t_stack *a);

// Utility functions

int		ft_isnumber(char *str);
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
t_stack	*ft_lstlast(t_stack *lst);

#endif
