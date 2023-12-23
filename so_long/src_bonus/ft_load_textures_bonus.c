/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:27:52 by aflorido          #+#    #+#             */
/*   Updated: 2023/12/16 21:45:21 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	fill_black(mlx_image_t *img)
{
	unsigned int	x;
	unsigned int	y;

	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
			mlx_put_pixel(img, x, y, 0x000000FF);
	}
}

static void	load_images(t_all *all)
{
	all->i_bg = mlx_new_image(all->mlx, TILE_W, TILE_H / 2);
	fill_black(all->i_bg);
	all->i01 = mlx_texture_to_image(all->mlx, all->t01);
	all->i02 = mlx_texture_to_image(all->mlx, all->t02);
	all->i03 = mlx_texture_to_image(all->mlx, all->t03);
	all->i04 = mlx_texture_to_image(all->mlx, all->t04);
	all->i05 = mlx_texture_to_image(all->mlx, all->t05);
	all->i06 = mlx_texture_to_image(all->mlx, all->t06);
	all->i07 = mlx_texture_to_image(all->mlx, all->t07);
	all->i08 = mlx_texture_to_image(all->mlx, all->t08);
	all->i09 = mlx_texture_to_image(all->mlx, all->t09);
	all->i10 = mlx_texture_to_image(all->mlx, all->t10);
	all->i11 = mlx_texture_to_image(all->mlx, all->t11);
	all->i12 = mlx_texture_to_image(all->mlx, all->t12);
	all->i13 = mlx_texture_to_image(all->mlx, all->t13);
	all->i14 = mlx_texture_to_image(all->mlx, all->t14);
	all->i15 = mlx_texture_to_image(all->mlx, all->t15);
	all->i16 = mlx_texture_to_image(all->mlx, all->t16);
	all->i17 = mlx_texture_to_image(all->mlx, all->t17);
	all->i18 = mlx_texture_to_image(all->mlx, all->t18);
	all->i19 = mlx_texture_to_image(all->mlx, all->t19);
	all->i20 = mlx_texture_to_image(all->mlx, all->t20);
	all->i21 = mlx_texture_to_image(all->mlx, all->t21);
}

void	ft_load_textures(t_all *all)
{
	all->t01 = mlx_load_png("textures/wall.png");
	all->t02 = mlx_load_png("textures/path.png");
	all->t03 = mlx_load_png("textures/brendan-south-64x64.png");
	all->t04 = mlx_load_png("textures/brendan-north-64x64.png");
	all->t05 = mlx_load_png("textures/brendan-east-64x64.png");
	all->t06 = mlx_load_png("textures/brendan-west-64x64.png");
	all->t07 = mlx_load_png("textures/exit-1-64x64.png");
	all->t08 = mlx_load_png("textures/exit-2-64x64.png");
	all->t09 = mlx_load_png("textures/exit-3-64x64.png");
	all->t10 = mlx_load_png("textures/giovanni.png");
	all->t11 = mlx_load_png("textures/arcanine.png");
	all->t12 = mlx_load_png("textures/blastoise.png");
	all->t13 = mlx_load_png("textures/charizard.png");
	all->t14 = mlx_load_png("textures/chopper.png");
	all->t15 = mlx_load_png("textures/deoxys-normal.png");
	all->t16 = mlx_load_png("textures/gengar.png");
	all->t17 = mlx_load_png("textures/lugia.png");
	all->t18 = mlx_load_png("textures/mawile.png");
	all->t19 = mlx_load_png("textures/rayquaza.png");
	all->t20 = mlx_load_png("textures/snorlax.png");
	all->t21 = mlx_load_png("textures/venusaur.png");
	load_images(all);
}
