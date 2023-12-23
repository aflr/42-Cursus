/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:10:54 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/10 01:17:49 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
* This function prints the error message and exits
*/
void	ft_error(char *str)
{
	ft_putstr(str);
	exit(1);
}

/**
* This function prints the error message, frees the map and exits
*/
void	ft_error_map(char *str, t_all *all)
{
	ft_putstr(str);
	free_map(all);
	exit(1);
}

/**
* This function prints the error message, frees all the memory and exits
*/
void	ft_error_free(char *str, t_all *all)
{
	ft_putstr(str);
	free_all(all);
	exit(1);
}
