/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:41:48 by aflorido          #+#    #+#             */
/*   Updated: 2024/10/02 17:53:59 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_printf_bonus.h"

/**
 * Print an unsigned integer in uppercase hexadecimal format.
 * Return the number of bytes written.
 * 
 * Relevant flags:
 * - width (minimum field width)
 * - '-' (left align)
 * - '0' (zero padding)
 * - '.' (precision)
 * - '#' (prefix with "0X")
 * 
 * Other flags are ignored.
 * 
 * If precision is zero and the integer is zero, nothing is printed.
 * If flags zero and minus or dot are present, zero is ignored.
 * If the integer is zero, the hash flag is (silently) ignored.
 */
int	ft_print_uc_hex(t_format *fs, int *error)
{
	t_print_hex	p;

	fs->flags.zero = fs->flags.zero && !fs->flags.minus && !fs->flags.dot;
	fs->flags.hash = fs->flags.hash && fs->data.uint != 0;
	ft_memset(&p, 0, sizeof(t_print_hex));
	ft_set_widths_hex(&p, fs);
	return (ft_print_uc_hex_safe(&p, fs, error));
}

/**
 * Print an unsigned integer in lowercase hexadecimal format.
 * Return the number of bytes written.
 * 
 * Relevant flags:
 * - width (minimum field width)
 * - '-' (left align)
 * - '0' (zero padding)
 * - '.' (precision)
 * - '#' (prefix with "0X")
 * 
 * Other flags are ignored.
 * 
 * If precision is zero and the integer is zero, nothing is printed.
 * If flags zero and minus or dot are present, zero is ignored.
 * If the integer is zero, the hash flag is (silently) ignored.
 */
int	ft_print_lc_hex(t_format *fs, int *error)
{
	t_print_hex	p;

	fs->flags.zero = fs->flags.zero && !fs->flags.minus && !fs->flags.dot;
	fs->flags.hash = fs->flags.hash && fs->data.uint != 0;
	ft_memset(&p, 0, sizeof(t_print_hex));
	ft_set_widths_hex(&p, fs);
	return (ft_print_lc_hex_safe(&p, fs, error));
}

/**
 * Print a pointer address in lowercase hexadecimal format.
 * Return the number of bytes written.
 * 
 * Relevant flags:
 * - width (minimum field width)
 * - '-' (left align)
 * 
 * Other flags are ignored.
 * 
 * The pointer is always prefixed with "0x".
 * A NULL pointer is printed as the string NULL_PTR without a prefix.
 */
int	ft_print_ptr(t_format *fs, int *error)
{
	t_print_hex	p;
	int			width;

	ft_memset(&p, 0, sizeof(t_print_hex));
	p.number_len = ft_get_ptr_length((unsigned long long)fs->data.p);
	width = p.number_len + 2;
	if (fs->data.p == NULL)
		width = ft_strlen(NULL_PTR);
	if (fs->width <= width)
		return (ft_print_ptr_safe(&p, fs, error));
	if (!fs->flags.minus)
		p.leading_spaces = fs->width - width;
	else
		p.trailing_spaces = fs->width - width;
	return (ft_print_ptr_safe(&p, fs, error));
}
