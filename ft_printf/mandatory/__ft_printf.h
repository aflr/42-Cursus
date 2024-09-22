/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:26:31 by aflorido          #+#    #+#             */
/*   Updated: 2024/09/19 15:39:41 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * This acts as a private header file for the ft_printf project.
 */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

// Standard libraries
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

// Constants
# define INTMIN -2147483648
# define XDIGITUC "0123456789ABCDEF"
# define XDIGITLC "0123456789abcdef"
# define NULL_STR "(null)"
# define NULL_PTR "(nil)"

// Function prototypes
int	ft_fs(char c, va_list av);

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(long nbr);
int	ft_puthex(unsigned long long hex, int upper);
int	ft_putptr(unsigned long long ptr);

#endif