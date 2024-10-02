/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:30:42 by aflorido          #+#    #+#             */
/*   Updated: 2024/10/02 17:54:24 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * This acts as a public header file for the bonus part of ft_printf project.
 */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

/*
	The attribute format is used to tell the compiler to check the format string
	and the arguments passed to the function, giving a compile-time warning if
	the format string does not match the arguments.
	More information:
	-	https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html
*/

int	ft_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));

#endif
