/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcontains.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:07:38 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/09 17:08:44 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
