/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:49:44 by rolevy            #+#    #+#             */
/*   Updated: 2018/02/06 04:55:46 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
*** - Color Mangement -
*/

int				interpolate(uint32_t start, uint32_t end, double p)
{
	uint32_t	c;
	double		p1;

	p1 = 1.0 - p;
	c = 0;
	c += ((uint32_t)((start & 0xFF) * p + (end & 0xFF) * p1)) & 0xFF;
	c += ((uint32_t)((start & 0xFF00) * p + (end & 0xFF00) * p1)) & 0xFF00;
	c += ((uint32_t)((start & 0xFF0000) * p + (end & 0xFF0000) * p1)) & 0xFF0000;
	c += ((uint32_t)((start & 0xFF000000) * p + (end & 0xFF000000) * p1)) & 0xFF000000;
	return (c);
}

int				get_color_argb(char a, char r, char g, char b)
{
	t_color		c;

	c.a = a;
	c.r = r;
	c.g = g;
	c.b = b;
	return (c.color);
}

t_color			set_color(int r, int g, int b, int a)
{
	t_color		color;

	color.color = (r << 16) + (g << 8) + (b) + ((a << 24) * -1);
	return (color);
}

int				*get_palette(void)
{
	uint32_t	i;
	static int	*p = NULL;

	if (!p)
	{
		p = malloc((ITER_MAX + 1) * sizeof(int));
		i = ~0U;
		while (++i <= ITER_MAX)
			p[i] = get_color_argb((int)(0x15 * (double)i / ITER_MAX)
								, (int)(0x8c * ((double)i / ITER_MAX))
								, (int)(0xFF * (double)i / ITER_MAX)
								, (int)(0x0 * (double)i / ITER_MAX));
	}
	return (p);
}
