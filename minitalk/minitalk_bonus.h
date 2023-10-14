/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:37:05 by aflorido          #+#    #+#             */
/*   Updated: 2023/10/12 19:43:39 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>
# include <stdio.h>

# define COLOR_SERVER "\x1b[32m"
# define COLOR_CLIENT "\x1b[36m"
# define COLOR_END "\x1b[0m"

void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		ft_atoi(char *str);

#endif
