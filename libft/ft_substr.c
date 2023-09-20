/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:49:12 by aflorido          #+#    #+#             */
/*   Updated: 2023/09/11 21:27:48 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t n1, size_t n2)
{
	if (n1 <= n2)
		return (n1);
	else
		return (n2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	real_len;
	unsigned int	i;

	real_len = ft_strlen(s);
	if (start > real_len)
		return (ft_strdup(""));
	substr = malloc(sizeof(char) * (ft_min(len, real_len - start) + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && i < len)
	{
		substr[i] = s[start + i];
		++i;
	}
	substr[i] = '\0';
	return (substr);
}
