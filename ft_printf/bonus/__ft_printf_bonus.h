/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_printf_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:41:56 by aflorido          #+#    #+#             */
/*   Updated: 2024/09/22 10:08:58 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * This acts as a private header file for the bonus part of ft_printf project.
 */

#ifndef __FT_PRINTF_BONUS_H
# define __FT_PRINTF_BONUS_H

// Standard libraries
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>

// Constants

// The string "(null)" is printed when a NULL pointer is passed as an argument.
# define NULL_STR "(null)"
// The string "(nil)" is printed when a NULL pointer is passed as an argument.
# define NULL_PTR "(nil)"

/**
 * The set of valid flags for the format specifier.
 * The dot flag is not included here, as it is not a flag per se,
 * but part of the precision field.
 */
# define FLAGS "-0# +"

# define XDIGITUC "0123456789ABCDEF"
# define XDIGITLC "0123456789abcdef"

// Structures

/**
 * Data type enum.
 */
typedef enum e_type
{
	NONE = 0,	// no type
	PERCENT,	// '%'
	CHAR,		// 'c'
	STR,		// 's'
	SINT,		// 'd', 'i'
	UINT,		// 'u'
	UC_HEX,		// 'X'
	LC_HEX,		// 'x'
	PTR,		// 'p'
}	t_type;

/**
 * Flags bit field structure.
 * 
 * - minus: left align the result within the given field width.
 * - zero: pad the result with zeros instead of spaces.
 * - dot: precision is given.
 * - hash: with x or X, prefix 0x or 0X.
 * - space: prefix positive numbers with a space.
 * - plus: prefix positive numbers with a '+'.
 */
typedef struct s_flags
{
	unsigned int	minus:	1; // '-'
	unsigned int	zero:	1; // '0'
	unsigned int	dot:	1; // '.'
	unsigned int	hash:	1; // '#'
	unsigned int	space:	1; // ' '
	unsigned int	plus:	1; // '+'
}	t_flags;

/**
 * Data union structure.
 * Holds the data fetched from the va_list.
 */
typedef union u_data
{
	char				c;
	char				*s;
	int					sint; // 'd', 'i'
	unsigned int		uint; // 'u', 'x', 'X'
	void				*p;
}	t_data;

/**
 * Format specifier structure.
 * 
 * A format specifier is a string of the form:
 *	%[flags][width][.precision]type
 */
typedef struct s_format
{
	t_flags	flags;
	int		width;
	int		precision;
	t_type	type;
	t_data	data;
}	t_format;

/**
 * Helper structure for printing signed integers %d, %i.
 */
typedef struct s_print_sint
{
	int		leading_spaces;		// width - sign - zeros - number
	char	sign;				// '\0', '+', '-', ' '
	int		leading_zeros;		// precision - (number_len + (sign != '\0'))
								// or width - (number_len + sign) when zero flag
	int		number_len;			// length of the number in base 10
	int		trailing_spaces;	// same as leading_spaces, when left aligned
}	t_print_sint;

/**
 * Helper structure for printing unsigned integers %u.
 */
typedef struct s_print_uint
{
	int		leading_spaces;		// width - zeros - number
	int		leading_zeros;		// precision - number_len
	int		number_len;			// length of the number in base 10
	int		trailing_spaces;	// same as leading_spaces, when left aligned
}	t_print_uint;

/**
 * Helper structure for printing hexadecimal integers %X, %x.
 */
typedef struct s_print_hex
{
	int		leading_spaces;		// width - prefix - zeros - number
	bool	prefix;				// true if the prefix (0X / 0x) is to be printed
	int		leading_zeros;		// precision - number_len
	int		number_len;			// length of the number in base 16
	int		trailing_spaces;	// same as leading_spaces, when left aligned
}	t_print_hex;

// Function prototypes

int		ft_fs(char *format, int *i, va_list av, int *error);

void	ft_parse_format(char *format, int *i, t_format *fs);
void	ft_read_data(t_format *fs, va_list av);
int		ft_print_format(t_format *fs, int *error);

/* --- Parse functions --- */

void	ft_parse_flags(char *format, int *i, t_format *fs);
void	ft_parse_width(char *format, int *i, t_format *fs);
void	ft_parse_precision(char *format, int *i, t_format *fs);
void	ft_parse_type(char *format, int *i, t_format *fs);

/* --- Printers functions --- */

int		ft_print_char(t_format *fs, int *error);
int		ft_print_str(t_format *fs, int *error);
int		ft_print_sint(t_format *fs, int *error);
int		ft_print_uint(t_format *fs, int *error);

int		ft_print_uc_hex(t_format *fs, int *error);
int		ft_print_lc_hex(t_format *fs, int *error);
int		ft_print_ptr(t_format *fs, int *error);

/* --- Utils functions --- */

size_t	ft_strlen(const char *s);
int		ft_putchar_safe(int c, int *error);
int		ft_putstr_safe(char *str, int *error);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);

int		ft_get_sn_length(int n, int base);
int		ft_get_un_length(unsigned int n, int base);
int		ft_putnstr_safe(char *s, int n, int *error);
int		ft_putunbr_safe(unsigned int n, int *error);
int		ft_putnbr_safe(int n, bool print_sign, int *error);

/* --- Aux functions --- */

void	ft_set_widths_sint(t_print_sint *p, t_format *fs);
int		ft_print_sint_safe(t_print_sint *p, t_format *fs, int *error);
void	ft_set_widths_uint(t_print_uint *p, t_format *fs);
int		ft_print_uint_safe(t_print_uint *p, t_format *fs, int *error);

int		ft_get_ptr_length(unsigned long long ptr);
void	ft_set_widths_hex(t_print_hex *p, t_format *fs);
int		ft_print_uc_hex_safe(t_print_hex *p, t_format *fs, int *error);
int		ft_print_lc_hex_safe(t_print_hex *p, t_format *fs, int *error);
int		ft_print_ptr_safe(t_print_hex *p, t_format *fs, int *error);

#endif