/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:35:49 by aflorido          #+#    #+#             */
/*   Updated: 2023/10/14 04:37:28 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	i;

	i = CHAR_BIT;
	while (--i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(60);
	}
}

void	send_string(int pid, char *str)
{
	int	i;

	if (pid <= 0)
	{
		ft_putstr(COLOR_CLIENT "Bad PID provided\n" COLOR_END);
		return ;
	}
	i = 0;
	while (str[i] != '\0')
		send_char(pid, str[i++]);
	send_char(pid, '\0');
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putstr(COLOR_CLIENT "Error with arguments\n" COLOR_END);
		return (1);
	}
	send_string(ft_atoi(av[1]), av[2]);
	return (0);
}
