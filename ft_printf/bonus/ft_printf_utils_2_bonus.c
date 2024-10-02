/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:20:06 by aflorido          #+#    #+#             */
/*   Updated: 2024/10/02 17:54:36 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_printf_bonus.h"

/**
 * Calculate the length of a signed number N in base BASE.
 * The length is only the number of digits in the number, not the sign.
 */
int	ft_get_sn_length(int n, int base)
{
	int	len;

	len = 1;
	while (n >= base || n <= -base)
	{
		n /= base;
		len++;
	}
	return (len);
}

/**
 * Calculate the length of an unsigned number N in base BASE.
 */
int	ft_get_un_length(unsigned int n, int base)
{
	int	len;

	len = 1;
	while (n >= (unsigned int)base)
	{
		n /= base;
		len++;
	}
	return (len);
}

/**
 * Write a string to stdout, return number of bytes written.
 * Write at most n bytes.
 * If write fails, set error to 1.
 */
int	ft_putnstr_safe(char *s, int n, int *error)
{
	int	ret;
	int	len;

	len = ft_strlen(s);
	if (n < 0 || n > len)
		n = len;
	ret = write(STDOUT_FILENO, s, n);
	if (ret == -1)
		return (*error = 1, 0);
	return (ret);
}

/**
 * Write an unsigned integer to stdout, return number of bytes written.
 * If write fails, set error to 1.
 */
int	ft_putunbr_safe(unsigned int n, int *error)
{
	int		count;
	char	digit;

	count = 0;
	if (n >= 10)
		count += ft_putunbr_safe(n / 10, error);
	digit = n % 10 + '0';
	count += ft_putchar_safe(digit, error);
	return (count);
}

/**
 * Write an integer to stdout, return number of bytes written.
 * If write fails, set error to 1.
 * @param print_sign: true to print the possible negative sign of the number.
 */
int	ft_putnbr_safe(int n, bool print_sign, int *error)
{
	int		count;
	char	digit;

	count = 0;
	if (n < 0)
	{
		if (print_sign)
			count += ft_putchar_safe('-', error);
		if (n == INT_MIN)
			return (count + ft_putnstr_safe("2147483648", 10, error));
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_safe(n / 10, false, error);
	digit = n % 10 + '0';
	count += ft_putchar_safe(digit, error);
	return (count);
}
