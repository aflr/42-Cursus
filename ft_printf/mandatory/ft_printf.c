/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:31:52 by aflorido          #+#    #+#             */
/*   Updated: 2024/09/16 10:31:52 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_printf.h"

int	ft_fs(char c, va_list av)
{
	if (c == 'c')
		return (ft_putchar(va_arg(av, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(av, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(av, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(av, int)));
	else if (c == 'u')
		return (ft_putnbr(va_arg(av, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(av, unsigned int), c == 'X'));
	else if (c == '%')
		return (ft_putchar('%'));
	return (INTMIN);
}

int	ft_printf(const char *format, ...)
{
	va_list	av;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(av, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			count += ft_fs(format[++i], av);
		else
			count += ft_putchar(format[i]);
		++i;
	}
	va_end(av);
	return (count);
}
