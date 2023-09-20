/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:33:18 by aflorido          #+#    #+#             */
/*   Updated: 2023/09/12 00:40:49 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Standard libraries
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

// Constants
# define INTMIN -2147483648
# define XDIGITUC "0123456789ABCDEF"
# define XDIGITLC "0123456789abcdef"

// Function prototypes
int	ft_printf(const char *format, ...);
int	ft_fs(char c, va_list av);

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(long nbr);
int	ft_puthex(unsigned long long hex, int upper);
int	ft_putptr(unsigned long long ptr);

#endif
