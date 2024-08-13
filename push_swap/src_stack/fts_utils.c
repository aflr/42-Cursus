/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:07:32 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/24 16:18:34 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * Returns 1 if the given string is a valid integer, 0 otherwise.
 * It must work for any string, no matter how big the number is.
 * This function should always be used before calling ft_atoi.
 */
int	ft_isnumber(char *str)
{
	int				i;
	int				sign;
	unsigned long	num;

	i = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	num = 0;
	while (str[i] && num < 2147483648)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = num * 10 + (str[i++] - '0');
	}
	if ((sign == 1 && num > 2147483647)
		|| (sign == -1 && num > 2147483648))
		return (0);
	return (1);
}

/**
 * Converts the given string to an integer.
 * The string is guaranteed to be a valid integer.
 */
int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	num;

	i = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	num = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		num = num * 10 + (str[i++] - '0');
	return (num * sign);
}

/**
 * Compares two strings, returns 0 if they are equal,
 * a negative number if s1 is less than s2,
 * or a positive number if s1 is greater than s2.
 * 
 * Since we only care about equality, we return -1
 * if any of the strings is NULL.
*/
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
