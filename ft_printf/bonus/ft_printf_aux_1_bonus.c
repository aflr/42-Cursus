/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux_1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:41:45 by aflorido          #+#    #+#             */
/*   Updated: 2024/09/17 20:11:37 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_printf_bonus.h"

/**
 * Calculate the leading spaces, sign, leading zeros, number length and trailing
 * spaces for a signed integer, given the format specifier structure.
 * The structure comes initialized to all zeros.
 */
void	ft_set_widths_sint(t_print_sint *p, t_format *fs)
{
	const int	n = fs->data.sint;
	int			width;

	p->number_len = ft_get_sn_length(n, 10);
	if (n == 0 && fs->flags.dot && fs->precision == 0)
		p->number_len = 0;
	width = p->number_len;
	if (n < 0 || fs->flags.plus || fs->flags.space)
		width++;
	if (n < 0)
		p->sign = '-';
	else if (fs->flags.plus)
		p->sign = '+';
	else if (fs->flags.space)
		p->sign = ' ';
	if (fs->flags.dot && fs->precision > p->number_len)
		width += (p->leading_zeros = fs->precision - p->number_len);
	if (fs->width <= width)
		return ;
	if (fs->flags.zero)
		p->leading_zeros = fs->width - width;
	else if (!fs->flags.minus)
		p->leading_spaces = fs->width - width;
	else
		p->trailing_spaces = fs->width - width;
}

/**
 * Print a signed integer. Return the number of bytes written.
 */
int	ft_print_sint_safe(t_print_sint *p, t_format *fs, int *error)
{
	int	count;

	count = 0;
	while (!*error && p->leading_spaces-- > 0)
		count += ft_putchar_safe(' ', error);
	if (!*error && p->sign)
		count += ft_putchar_safe(p->sign, error);
	while (!*error && p->leading_zeros-- > 0)
		count += ft_putchar_safe('0', error);
	if (!*error && p->number_len > 0)
		count += ft_putnbr_safe(fs->data.sint, false, error);
	while (!*error && p->trailing_spaces-- > 0)
		count += ft_putchar_safe(' ', error);
	return (count);
}

/**
 * Calculate the leading spaces, leading zeros, number length and trailing
 * spaces for an unsigned integer, given the format specifier structure.
 * The structure comes initialized to all zeros.
 */
void	ft_set_widths_uint(t_print_uint *p, t_format *fs)
{
	const unsigned int	n = fs->data.uint;
	int					width;

	p->number_len = ft_get_un_length(n, 10);
	if (n == 0U && fs->flags.dot && fs->precision == 0)
		p->number_len = 0;
	width = p->number_len;
	if (fs->flags.dot && fs->precision > p->number_len)
		width += (p->leading_zeros = fs->precision - p->number_len);
	if (fs->width <= width)
		return ;
	if (fs->flags.zero)
		p->leading_zeros = fs->width - width;
	else if (!fs->flags.minus)
		p->leading_spaces = fs->width - width;
	else
		p->trailing_spaces = fs->width - width;
}

int	ft_print_uint_safe(t_print_uint *p, t_format *fs, int *error)
{
	int	count;

	count = 0;
	while (!*error && p->leading_spaces-- > 0)
		count += ft_putchar_safe(' ', error);
	while (!*error && p->leading_zeros-- > 0)
		count += ft_putchar_safe('0', error);
	if (!*error && p->number_len > 0)
		count += ft_putunbr_safe(fs->data.uint, error);
	while (!*error && p->trailing_spaces-- > 0)
		count += ft_putchar_safe(' ', error);
	return (count);
}
