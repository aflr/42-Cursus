/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:44:47 by aflorido          #+#    #+#             */
/*   Updated: 2024/09/17 14:35:14 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list	av;
	int		count;
	int		error;
	int		i;

	count = 0;
	error = 0;
	i = 0;
	va_start(av, format);
	while (!error && format[i] != '\0')
	{
		if (format[i] == '%')
			count += ft_fs((char *)format, &i, av, &error);
		else
			count += ft_putchar_safe(format[i++], &error);
	}
	va_end(av);
	if (error)
		return (-1);
	return (count);
}
