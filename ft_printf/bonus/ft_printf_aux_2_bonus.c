/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:24:13 by aflorido          #+#    #+#             */
/*   Updated: 2024/09/19 19:26:30 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_printf_bonus.h"

/**
 * Calculate the length of a pointer in base 16.
 */
int	ft_get_ptr_length(unsigned long long ptr)
{
	int	len;

	len = 1;
	while (ptr >= 16ULL)
	{
		ptr /= 16ULL;
		len++;
	}
	return (len);
}

/**
 * Calculate the leading spaces, possible prefix, leading zeros, number length
 * and trailing spaces for an unsigned integer in hexadecimal format, given the
 * format specifier structure.
 * The structure comes initialized to all zeros.
 */
void	ft_set_widths_hex(t_print_hex *p, t_format *fs)
{
	const unsigned int	n = fs->data.uint;
	int					width;

	p->number_len = ft_get_un_length(n, 16);
	if (n == 0 && fs->flags.dot && fs->precision == 0)
		p->number_len = 0;
	width = p->number_len;
	if (fs->flags.hash)
		width += 2;
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
 * Print an unsigned integer in uppercase hexadecimal format.
 * Return the number of bytes written.
 * 
 * The printing of the hexadecimal number uses byte operations:
 * - The number is shifted right by 4 bits per hex digit (-1) to print
 *  digits one at a time from left (most significant) to right.
 *  We move the bits in groups of 4 because each hex digit is 4 bits (2^4 = 16).
 * - After applying a mask to select the rightmost 4 bits (0xF == 0b1111),
 *  the values (0-15) are used as indices to the XDIGITUC string.
 * - The characters are printed left to right because of number_len
 *  decrementing, moving the "window" less to the left each time.
 */
int	ft_print_uc_hex_safe(t_print_hex *p, t_format *fs, int *error)
{
	int	count;

	count = 0;
	while (!*error && p->leading_spaces-- > 0)
		count += ft_putchar_safe(' ', error);
	if (!*error && fs->flags.hash)
		count += ft_putstr_safe("0X", error);
	while (!*error && p->leading_zeros-- > 0)
		count += ft_putchar_safe('0', error);
	while (!*error && p->number_len-- > 0)
		count += ft_putchar_safe(XDIGITUC[fs->data.uint
				>> (p->number_len << 2) & 0xF], error);
	while (!*error && p->trailing_spaces-- > 0)
		count += ft_putchar_safe(' ', error);
	return (count);
}

/**
 * Print an unsigned integer in lowercase hexadecimal format.
 * Return the number of bytes written.
 */
int	ft_print_lc_hex_safe(t_print_hex *p, t_format *fs, int *error)
{
	int	count;

	count = 0;
	while (!*error && p->leading_spaces-- > 0)
		count += ft_putchar_safe(' ', error);
	if (!*error && fs->flags.hash)
		count += ft_putstr_safe("0x", error);
	while (!*error && p->leading_zeros-- > 0)
		count += ft_putchar_safe('0', error);
	while (!*error && p->number_len-- > 0)
		count += ft_putchar_safe(XDIGITLC[fs->data.uint
				>> (p->number_len << 2) & 0xF], error);
	while (!*error && p->trailing_spaces-- > 0)
		count += ft_putchar_safe(' ', error);
	return (count);
}

/**
 * Print a pointer address in lowercase hexadecimal format.
 * Return the number of bytes written.
 * 
 * If the pointer is NULL, the string NULL_STR is printed without a prefix.
 */
int	ft_print_ptr_safe(t_print_hex *p, t_format *fs, int *error)
{
	int	count;

	count = 0;
	while (!*error && p->leading_spaces-- > 0)
		count += ft_putchar_safe(' ', error);
	if (!*error && fs->data.p == NULL)
		count += ft_putstr_safe(NULL_PTR, error);
	else if (!*error)
	{
		count += ft_putstr_safe("0x", error);
		while (!*error && p->number_len-- > 0)
			count += ft_putchar_safe(XDIGITLC[(unsigned long long)fs->data.p
					>> (p->number_len << 2) & 0xF], error);
	}
	while (!*error && p->trailing_spaces-- > 0)
		count += ft_putchar_safe(' ', error);
	return (count);
}
