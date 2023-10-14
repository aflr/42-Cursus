/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:37:48 by aflorido          #+#    #+#             */
/*   Updated: 2023/10/08 12:47:40 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, str + i, 1);
		++i;
	}
}

// Only correctly prints non-negative numbers
void	ft_putnbr(int nbr)
{
	if (nbr < 0)
		return ;
	if (nbr == 0)
		write(1, "0", 1);
	else if (nbr < 10)
		write(1, &"0123456789"[nbr], 1);
	else
	{
		ft_putnbr(nbr / 10);
		write(1, &"0123456789"[nbr % 10], 1);
	}
}

// Only correctly parses strings made entirely of decimal digits
int	ft_atoi(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	return (res);
}
