/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fs_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:01:04 by aflorido          #+#    #+#             */
/*   Updated: 2024/09/22 10:27:50 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_printf_bonus.h"

/**
 * Parse the format specifier string and write the result to stdout.
 * Return the number of bytes written.
 * 
 * - format[*i] is the '%' character.
 * - i is updated to the next character after the format specifier.
 * - error is set to 1 if an error occurs.
 */
int	ft_fs(char *format, int *i, va_list av, int *error)
{
	t_format	fs;

	*i += 1;
	if (format[*i] == '\0')
		return (ft_putchar_safe('%', error));
	ft_parse_format(format, i, &fs);
	ft_read_data(&fs, av);
	return (ft_print_format(&fs, error));
}

void	ft_parse_format(char *format, int *i, t_format *fs)
{
	ft_memset(fs, 0, sizeof(t_format));
	ft_parse_flags(format, i, fs);
	ft_parse_width(format, i, fs);
	ft_parse_precision(format, i, fs);
	ft_parse_type(format, i, fs);
}

void	ft_read_data(t_format *fs, va_list av)
{
	if (fs->type == CHAR)
		fs->data.c = va_arg(av, int);
	else if (fs->type == STR)
		fs->data.s = va_arg(av, char *);
	else if (fs->type == SINT)
		fs->data.sint = va_arg(av, int);
	else if (fs->type == UINT || fs->type == UC_HEX || fs->type == LC_HEX)
		fs->data.uint = va_arg(av, unsigned int);
	else if (fs->type == PTR)
		fs->data.p = va_arg(av, void *);
}

int	ft_print_format(t_format *fs, int *error)
{
	if (fs->type == PERCENT)
		return (ft_putchar_safe('%', error));
	else if (fs->type == CHAR)
		return (ft_print_char(fs, error));
	else if (fs->type == STR)
		return (ft_print_str(fs, error));
	else if (fs->type == SINT)
		return (ft_print_sint(fs, error));
	else if (fs->type == UINT)
		return (ft_print_uint(fs, error));
	else if (fs->type == UC_HEX)
		return (ft_print_uc_hex(fs, error));
	else if (fs->type == LC_HEX)
		return (ft_print_lc_hex(fs, error));
	else if (fs->type == PTR)
		return (ft_print_ptr(fs, error));
	return (*error = 1, 0);
}
