/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:31:47 by aflorido          #+#    #+#             */
/*   Updated: 2024/09/19 20:02:21 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
		str = NULL_STR;
	i = 0;
	while (str[i] != '\0')
		write(1, str + i++, 1);
	return (i);
}

int	ft_putnbr(long nbr)
{
	int	len;

	if (nbr == 0)
		return (write(1, "0", 1));
	len = 0;
	if (nbr < 0)
	{
		len += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
		len += ft_putnbr(nbr / 10);
	len += write(1, &"0123456789"[nbr % 10], 1);
	return (len);
}

int	ft_puthex(unsigned long long hex, int upper)
{
	char	*xdigit;

	if (upper)
		xdigit = XDIGITUC;
	else
		xdigit = XDIGITLC;
	if (hex < 16)
		return (write(1, xdigit + hex, 1));
	return (ft_puthex(hex / 16, upper) + write(1, xdigit + (hex % 16), 1));
}

int	ft_putptr(unsigned long long ptr)
{
	if (ptr == 0ULL)
		return (ft_putstr(NULL_PTR));
	return (write(1, "0x", 2) + ft_puthex(ptr, 0));
}
