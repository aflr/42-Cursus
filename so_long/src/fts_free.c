/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:02:54 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/10 01:45:16 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
* This function frees all the allocated memory
* It is important to free images before textures
*/
void	free_all(t_all *all)
{
	free_map(all);
	free_images(all);
	free_textures(all);
	mlx_terminate(all->mlx);
}

/**
* This function frees the map matrix
*/
void	free_map(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->h)
		free(all->map[i++]);
	free(all->map);
}

/**
* This function frees the images
*/
void	free_images(t_all *all)
{
	mlx_delete_image(all->mlx, all->i01);
	mlx_delete_image(all->mlx, all->i02);
	mlx_delete_image(all->mlx, all->i03);
	mlx_delete_image(all->mlx, all->i04);
	mlx_delete_image(all->mlx, all->i05);
	mlx_delete_image(all->mlx, all->i06);
	mlx_delete_image(all->mlx, all->i07);
	mlx_delete_image(all->mlx, all->i08);
	mlx_delete_image(all->mlx, all->i09);
	mlx_delete_image(all->mlx, all->i10);
	mlx_delete_image(all->mlx, all->i11);
	mlx_delete_image(all->mlx, all->i12);
	mlx_delete_image(all->mlx, all->i13);
	mlx_delete_image(all->mlx, all->i14);
	mlx_delete_image(all->mlx, all->i15);
	mlx_delete_image(all->mlx, all->i16);
	mlx_delete_image(all->mlx, all->i17);
	mlx_delete_image(all->mlx, all->i18);
	mlx_delete_image(all->mlx, all->i19);
	mlx_delete_image(all->mlx, all->i20);
}

/**
* This function frees the textures
*/
void	free_textures(t_all *all)
{
	mlx_delete_texture(all->t01);
	mlx_delete_texture(all->t02);
	mlx_delete_texture(all->t03);
	mlx_delete_texture(all->t04);
	mlx_delete_texture(all->t05);
	mlx_delete_texture(all->t06);
	mlx_delete_texture(all->t07);
	mlx_delete_texture(all->t08);
	mlx_delete_texture(all->t09);
	mlx_delete_texture(all->t10);
	mlx_delete_texture(all->t11);
	mlx_delete_texture(all->t12);
	mlx_delete_texture(all->t13);
	mlx_delete_texture(all->t14);
	mlx_delete_texture(all->t15);
	mlx_delete_texture(all->t16);
	mlx_delete_texture(all->t17);
	mlx_delete_texture(all->t18);
	mlx_delete_texture(all->t19);
	mlx_delete_texture(all->t20);
}
