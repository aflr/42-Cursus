/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 02:37:35 by aflorido          #+#    #+#             */
/*   Updated: 2023/10/14 05:34:51 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	print_pid_message(int pid)
{
	ft_putstr(COLOR_SERVER "My PID is: ");
	ft_putnbr(pid);
	ft_putstr("\n" COLOR_END);
}

static void	handle_signal(int signal, siginfo_t *info, void *ucontext)
{
	static char	byte = 0;
	static int	i = CHAR_BIT - 1;

	(void)ucontext;
	if (i < 0)
		i = CHAR_BIT - 1;
	if (signal == SIGUSR2)
		byte |= (1 << i);
	--i;
	if (i < 0)
		write(1, &byte, 1);
	if (i < 0 && byte == '\0')
	{
		write(1, "\n", 1);
		kill(info->si_pid, SIGUSR1);
		return ;
	}
	if (i < 0)
	{
		i = CHAR_BIT - 1;
		byte = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

/*
** Sets up sigaction, prints PID, then awaits signals.
** To quit, send termination signal
*/
int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sigemptyset(&(sa.sa_mask));
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
	{
		ft_putstr("Server error: sigaction failed");
		return (1);
	}
	print_pid_message(getpid());
	while (42)
		;
	return (0);
}
