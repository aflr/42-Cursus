/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:17:15 by aflorido          #+#    #+#             */
/*   Updated: 2023/09/13 23:37:48 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define MAX_FD 12288

char	*ft_fill(int fd, char *data);
char	*ft_extract_line(char *data);
char	*ft_update_data(char *old_data);
char	*get_next_line(int fd);

size_t	ft_strlen(char *s);
int		ft_strcontains(char *s, char c);
char	*ft_strcpy_nl(char *dest, char *src, int nl_stop);
char	*ft_strjoin_special(char *s1, char *s2);

#endif
