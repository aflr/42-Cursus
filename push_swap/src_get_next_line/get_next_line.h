/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:51:45 by aflorido          #+#    #+#             */
/*   Updated: 2023/11/26 19:17:46 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// BUFFER_SIZE set to 1, no longer stores data between calls.
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// Standard libraries
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

// --- Function prototypes ---

char	*get_next_line(int fd);

size_t	ft_strlen(char *s);
int		ft_strcontains(char *s, char c);
char	*ft_strcpy_nl(char *dest, char *src, int nl_stop);
char	*ft_strjoin_special(char *s1, char *s2);

#endif