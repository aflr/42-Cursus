/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:20:18 by aflorido          #+#    #+#             */
/*   Updated: 2024/10/02 17:53:53 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_printf_bonus.h"

void	ft_parse_flags(char *format, int *i, t_format *fs)
{
	while (ft_strchr(FLAGS, format[*i]))
	{
		if (format[*i] == '-')
			fs->flags.minus = 1;
		else if (format[*i] == '0')
			fs->flags.zero = 1;
		else if (format[*i] == '#')
			fs->flags.hash = 1;
		else if (format[*i] == ' ')
			fs->flags.space = 1;
		else if (format[*i] == '+')
			fs->flags.plus = 1;
		*i += 1;
	}
}

/**
 * Parse the minimum width field of the format specifier.
 * The asterisk character '*' is NOT supported.
 */
void	ft_parse_width(char *format, int *i, t_format *fs)
{
	long	width;

	width = 0;
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		width = width * 10 + format[*i] - '0';
		*i += 1;
	}
	fs->width = (int)width;
}

/**
 * Parse the precision field of the format specifier.
 */
void	ft_parse_precision(char *format, int *i, t_format *fs)
{
	long	precision;

	precision = 0;
	if (format[*i] == '.')
	{
		fs->flags.dot = 1;
		*i += 1;
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			precision = precision * 10 + format[*i] - '0';
			*i += 1;
		}
		fs->precision = (int)precision;
	}
}

/**
 * Parse the type field of the format specifier.
 * Supported types are csdiuXxp.
 */
void	ft_parse_type(char *format, int *i, t_format *fs)
{
	if (format[*i] == '%')
		fs->type = PERCENT;
	else if (format[*i] == 'c')
		fs->type = CHAR;
	else if (format[*i] == 's')
		fs->type = STR;
	else if (format[*i] == 'd' || format[*i] == 'i')
		fs->type = SINT;
	else if (format[*i] == 'u')
		fs->type = UINT;
	else if (format[*i] == 'X')
		fs->type = UC_HEX;
	else if (format[*i] == 'x')
		fs->type = LC_HEX;
	else if (format[*i] == 'p')
		fs->type = PTR;
	else
		return ;
	*i += 1;
}
