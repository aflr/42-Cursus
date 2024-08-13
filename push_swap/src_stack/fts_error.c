/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:02:35 by aflorido          #+#    #+#             */
/*   Updated: 2023/11/26 16:11:18 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * Prints "Error\n" to the standard output and exits with status 1.
 */
void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

/**
 * Frees the two stacks, prints "Error\n", and exits with status 1.
 */
void	ft_safe_error(t_stack **a, t_stack **b)
{
	ft_free_all(a, b);
	ft_error();
}
