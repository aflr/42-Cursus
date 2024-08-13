/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:54:31 by aflorido          #+#    #+#             */
/*   Updated: 2024/07/30 13:47:18 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static char	**ft_free_split(char **split, int j, int free_av)
{
	if (!free_av || !split)
		return (NULL);
	if (j < 0)
	{
		j = 0;
		while (split[j])
			free(split[j++]);
	}
	else
	{
		while (--j)
			free(split[j]);
	}
	free(split);
	return (NULL);
}

/**
 * Parses the given arguments and returns a stack with the numbers
 * in the same order as the arguments.
 * If any of the arguments is not a number, it returns NULL.
 * 
 * @param av The argument list to parse. It is assumed to be NULL terminated.
 * @param error It is set to 1 if an argument is not an integer, is bigger
 * 	than an integer, or there are duplicate integers.
 * @param free_av If set to 1, it will free the argument list.
 */
t_stack	*parse_stack(char **av, int *error, int free_av)
{
	t_stack	*a;
	int		i;

	if (!av || !*av)
		return (ft_free_split(av, -1, free_av), NULL);
	a = NULL;
	i = -1;
	while (av[++i])
		;
	while (i--)
	{
		if (!ft_isnumber(av[i]) || ft_push(&a, ft_atoi(av[i])))
		{
			*error = 1;
			return (ft_free(&a), ft_free_split(av, -1, free_av), NULL);
		}
	}
	if (ft_has_duplicates(a))
	{
		*error = 1;
		return (ft_free(&a), ft_free_split(av, -1, free_av), NULL);
	}
	return (ft_free_split(av, -1, free_av), a);
}

/*
 * Explanation for parse_stack:
 * Since the beginning of the list is the top of the stack,
 * we start pushing the numbers from the end of the arguments list.
*/

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	if (!s)
		return (0);
	if (s[0] && s[0] != c)
		count++;
	i = -1;
	while (s[++i])
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			count++;
	return (count);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	substr[len] = '\0';
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}

/**
 * Splits the string s using the character c as a delimiter.
*/
char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	split = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		k = 0;
		while (s[i + k] && s[i + k] != c)
			k++;
		if (k)
			split[j] = ft_substr(s, i, k);
		if (k && !split[j++])
			return (ft_free_split(split, j - 1, 1));
		i += k;
	}
	split[j] = NULL;
	return (split);
}
