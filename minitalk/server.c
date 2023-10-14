/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:37:20 by aflorido          #+#    #+#             */
/*   Updated: 2023/10/08 12:46:01 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pid_message(int pid)
{
	ft_putstr(COLOR_SERVER "My PID is: ");
	ft_putnbr(pid);
	ft_putstr("\n" COLOR_END);
}

void	handle_signal(int signal)
{
	static char	byte = 0;
	static int	i = CHAR_BIT - 1;

	if (signal == SIGUSR2)
		byte |= (1 << i);
	if (--i < 0)
	{
		write(1, &byte, 1);
		if (byte == '\0')
			write(1, "\n", 1);
		byte = 0;
		i = CHAR_BIT - 1;
	}
}

int	main(void)
{
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	print_pid_message(getpid());
	while (42)
		;
}
