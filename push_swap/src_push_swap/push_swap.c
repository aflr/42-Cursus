/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:57:29 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/30 13:39:06 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	int		error;

	if (ac == 1)
		return (0);
	error = 0;
	a = NULL;
	if (ac == 2)
		a = parse_stack(ft_split(av[1], ' '), &error, 1);
	else if (ac > 2)
		a = parse_stack(av + 1, &error, 0);
	if (error || !a)
		ft_safe_error(&a, NULL);
	else if (!ft_is_sorted(a))
		init_sort(&a);
	ft_free(&a);
	return (0);
}

/**
 * Initiates the sorting process by creating stack b,
 * then calling ft_sort for stack sizes >= 3.
 * 
 * @param a		Stack a, which is unsorted.
 */
void	init_sort(t_stack **a)
{
	t_stack	**b;
	int		size;

	b = malloc(sizeof(t_stack *));
	if (!b)
		ft_safe_error(a, NULL);
	*b = NULL;
	size = ft_stack_size(*a);
	if (size == 2)
		sa(a, 1);
	else
		ft_sort(a, b, size);
	ft_free(b);
	free(b);
}
