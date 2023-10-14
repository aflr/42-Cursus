/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:38:06 by aflorido          #+#    #+#             */
/*   Updated: 2023/10/14 05:24:54 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_lock;

static void	count(int print)
{
	static int	count = 0;

	if (print)
	{
		ft_putstr(COLOR_CLIENT);
		ft_putnbr(count / 8);
		ft_putstr(" bytes acknowledged\n" COLOR_END);
		exit(0);
	}
	++count;
}

/*
** Sends a char (8 bits) from least to most significant bit
** Waits for the server to acknowledge every message (bit)
*/
static void	send_char(int pid, char c)
{
	int	i;

	i = CHAR_BIT - 1;
	while (i >= 0)
	{
		g_lock = 0;
		usleep(70);
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_lock)
			write(1, "", 1);
		--i;
	}
}

// Sends a string by sending its chars
static void	send_string(int pid, char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		send_char(pid, str[i]);
	send_char(pid, '\0');
	count(1);
}

/*
** Counts bits acknowledged by the server, then displays the count
** SIGUSR1 -> end of transmission. SIGUSR2 -> bit received by server
*/
static void	handle_signal(int signal, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	g_lock = 1;
	if (signal == SIGUSR2)
		count(0);
	if (signal == SIGUSR1)
		count(1);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 3)
	{
		ft_putstr(COLOR_CLIENT "Error with arguments\n" COLOR_END);
		return (1);
	}
	sa.sa_sigaction = handle_signal;
	sigemptyset(&(sa.sa_mask));
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
	{
		ft_putstr("Client error: sigaction failed");
		return (1);
	}
	send_string(ft_atoi(av[1]), av[2]);
	return (0);
}
