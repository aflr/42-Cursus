/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:36:49 by aflorido          #+#    #+#             */
/*   Updated: 2023/10/08 02:36:51 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>

# define COLOR_SERVER "\x1b[32m"
# define COLOR_CLIENT "\x1b[36m"
# define COLOR_END "\x1b[0m"

void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		ft_atoi(char *str);

#endif
