/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:01:43 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/27 20:08:56 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

// Standard libraries
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// My libraries
# include "../src_stack/stack.h"
# include "../src_get_next_line/get_next_line.h"

// --- Function prototypes ---

void	do_op(char *op, t_stack **a, t_stack **b, int *error);
void	ft_write_result(t_stack *a, t_stack *b, int error);

#endif
