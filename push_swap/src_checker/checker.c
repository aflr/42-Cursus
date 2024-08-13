/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:07:39 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/30 13:39:02 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * Reads the instructions from the standard input (fd = 0) and executes them.
 * If the instructions are valid, it prints "OK\n" to the standard output.
 * If the instructions are invalid, it prints "KO\n" to the standard output.
 * If there is an error, it prints "Error\n" to the standard error output.
 */
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		error;

	if (ac == 1)
		return (0);
	error = 0;
	if (ac == 2)
		a = parse_stack(ft_split(av[1], ' '), &error, 1);
	else
		a = parse_stack(av + 1, &error, 0);
	b = NULL;
	while (!error)
	{
		line = get_next_line(0);
		if (!line || !*line || !ft_strcmp(line, "\n"))
			break ;
		do_op(line, &a, &b, &error);
		free(line);
	}
	ft_write_result(a, b, error);
	ft_free_all(&a, &b);
	return (0);
}

/**
 * Executes the operation specified by the string op.
 */
void	do_op(char *op, t_stack **a, t_stack **b, int *error)
{
	if (!ft_strcmp(op, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(op, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(op, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(op, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(op, "pb\n"))
		pb(a, b, 0);
	else if (!ft_strcmp(op, "ra\n"))
		ra(a, NULL, 0);
	else if (!ft_strcmp(op, "rb\n"))
		rb(NULL, b, 0);
	else if (!ft_strcmp(op, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(op, "rra\n"))
		rra(a, NULL, 0);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(NULL, b, 0);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(a, b, 0);
	else
		*error = 1;
}

/**
 * Writes the result of the checker program.
 * The result is "Error\n" if there is an error
 * with the input numbers or instructions.
 * The result is "OK\n" if the stack a is sorted and the stack b is empty.
 * The result is "KO\n" otherwise.
 */
void	ft_write_result(t_stack *a, t_stack *b, int error)
{
	if (error)
		write(2, "Error\n", 6);
	else if (ft_is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
