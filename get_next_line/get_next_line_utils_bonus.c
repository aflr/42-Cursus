/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:16:51 by aflorido          #+#    #+#             */
/*   Updated: 2023/09/13 23:12:27 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != '\0')
		++len;
	return (len);
}

int	ft_strcontains(char *s, char c)
{
	unsigned int	i;

	if (s == NULL)
		return (0);
	if (c == '\0')
		return (1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strcpy_nl(char *dest, char *src, int nl_stop)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		if (nl_stop && src[i] == '\n')
		{
			++i;
			break ;
		}
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin_special(char *s1, char *s2)
{
	char	*join;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) + (len + 1));
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		join[i] = s1[i];
		++i;
	}
	if (s1 != NULL)
		free(s1);
	j = 0;
	while (s2 != NULL && s2[j] != '\0')
		join[i++] = s2[j++];
	join[len] = '\0';
	return (join);
}
