/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:19:42 by aflorido          #+#    #+#             */
/*   Updated: 2024/09/22 10:22:29 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_printf_bonus.h"

/**
 * Print a character. Return the number of bytes written.
 * 
 * Relevant flags:
 * - width (minimum field width)
 * - '-' (left align)
 * 
 * Other flags are ignored.
 */
int	ft_print_char(t_format *fs, int *error)
{
	int	count;

	count = 0;
	if (fs->flags.minus)
		count += ft_putchar_safe(fs->data.c, error);
	while (--fs->width > 0)
		count += ft_putchar_safe(' ', error);
	if (!fs->flags.minus)
		count += ft_putchar_safe(fs->data.c, error);
	return (count);
}

/**
 * Print a string. Return the number of bytes written.
 * 
 * Relevant flags:
 * - width (minimum field width)
 * - '-' (left align)
 * - '.' (precision)
 * 
 * Other flags are ignored.
 * 
 * When the string is NULL, NULL_STR is printed,
 * unless the precision is less than length of NULL_STR, in which case
 * the string is not printed (only the width is respected).
 */
int	ft_print_str(t_format *fs, int *error)
{
	int	count;
	int	len;

	if (fs->data.s == NULL && fs->flags.dot
		&& fs->precision < (int)ft_strlen(NULL_STR))
		fs->data.s = "";
	else if (fs->data.s == NULL)
		fs->data.s = NULL_STR;
	len = ft_strlen(fs->data.s);
	if (fs->flags.dot && fs->precision < len)
		len = fs->precision;
	count = 0;
	if (fs->flags.minus)
		count += ft_putnstr_safe(fs->data.s, len, error);
	while (fs->width-- > len)
		count += ft_putchar_safe(' ', error);
	if (!fs->flags.minus)
		count += ft_putnstr_safe(fs->data.s, len, error);
	return (count);
}

/**
 * Print a signed integer. Return the number of bytes written.
 * The integer is always of the form:
 * [leading spaces][sign(+,-, )][leading zeros][number][trailing spaces]
 * 
 * Relevant flags:
 * - width (minimum field width)
 * - '-' (left align)
 * - '0' (zero padding)
 * - '.' (precision)
 * - ' ' (space)
 * - '+' (plus sign)
 * 
 * Other flags are ignored.
 * 
 * If precision is zero and the integer is zero, nothing is printed.
 * If flags space and plus are both present, space is ignored.
 * If flags zero and minus or dot are present, zero is ignored.
 */
int	ft_print_sint(t_format *fs, int *error)
{
	t_print_sint	p;

	fs->flags.space = fs->flags.space && !fs->flags.plus;
	fs->flags.zero = fs->flags.zero && !fs->flags.minus && !fs->flags.dot;
	ft_memset(&p, 0, sizeof(t_print_sint));
	ft_set_widths_sint(&p, fs);
	return (ft_print_sint_safe(&p, fs, error));
}

/**
 * Print an unsigned integer. Return the number of bytes written.
 * The integer is always of the form:
 * [leading spaces][leading zeros][number][trailing spaces]
 * 
 * Relevant flags:
 * - width (minimum field width)
 * - '-' (left align)
 * - '0' (zero padding)
 * - '.' (precision)
 * 
 * Other flags are ignored.
 * 
 * If precision is zero and the integer is zero, nothing is printed.
 * If flags zero and minus or dot are present, zero is ignored.
 */
int	ft_print_uint(t_format *fs, int *error)
{
	t_print_uint	p;

	fs->flags.zero = fs->flags.zero && !fs->flags.minus && !fs->flags.dot;
	ft_memset(&p, 0, sizeof(t_print_uint));
	ft_set_widths_uint(&p, fs);
	return (ft_print_uint_safe(&p, fs, error));
}
