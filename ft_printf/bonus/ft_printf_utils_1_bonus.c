/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:07:50 by aflorido          #+#    #+#             */
/*   Updated: 2024/09/16 16:19:56 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__ft_printf_bonus.h"

/**
 * Return the length of a string.
 * The string must not be NULL.
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * Write a char to stdout, return number of bytes written.
 * If write fails, set error to 1.
 */
int	ft_putchar_safe(int c, int *error)
{
	if (write(STDOUT_FILENO, &c, 1) == -1)
		return (*error = 1, 0);
	return (1);
}

/**
 * Write a string to stdout, return number of bytes written.
 * If write fails, set error to 1.
 */
int	ft_putstr_safe(char *s, int *error)
{
	int	ret;

	ret = write(STDOUT_FILENO, s, ft_strlen(s));
	if (ret == -1)
		return (*error = 1, 0);
	return (ret);
}

/**
 * Find the first occurrence of a character in a string.
 * Return a pointer to the character or NULL if not found.
 */
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		++i;
	}
	return (NULL);
}

/**
 * Set all bytes of a memory area to a specific value.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = c;
	return (s);
}
