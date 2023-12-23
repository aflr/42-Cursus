/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:31:22 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/10 17:10:41 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

	len = 0;
	if (s1 != NULL)
		len += ft_strlen(s1);
	if (s2 != NULL)
		len += ft_strlen(s2);
	join = malloc(sizeof(char) + (len + 1));
	if (join == NULL)
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		join[i] = s1[i];
		++i;
	}
	free(s1);
	j = 0;
	while (s2 != NULL && s2[j] != '\0')
		join[i++] = s2[j++];
	join[len] = '\0';
	return (join);
}
