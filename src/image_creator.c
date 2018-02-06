/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:42:36 by rolevy            #+#    #+#             */
/*   Updated: 2018/01/13 15:32:42 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*** - Creating Images -
*/

#include "../includes/header.h"

t_img		*create_img(t_env *env, int x, int y)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		exit(EXIT_FAILURE);
	if (!(img->img_ptr = mlx_new_image(env->mlx, x, y)))
		exit(EXIT_FAILURE);
	if (!(img->img_str = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->l),
					&(img->endian))))
		exit(EXIT_FAILURE);
	img->x = x;
	img->y = y;
	return (img);
}

void		set_pixel(int x, int y, t_img *img, t_color col)
{
	((int*)img->img_str)[(x + (y * img->x))] = col.color;
}
