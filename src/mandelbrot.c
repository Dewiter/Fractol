/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:54:06 by rolevy            #+#    #+#             */
/*   Updated: 2018/02/06 05:44:59 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static inline int	get_iteration(t_complex status_complex)
{
	int				iter;
	double			tmp;
	t_complex		complex;

	iter = 0;
	complex = (t_complex){0, 0};
	while (complex.real * complex.real
			+ complex.imaginary * complex.imaginary < 4 && iter < ITER_MAX)
	{
		tmp = complex.real * complex.real
			- complex.imaginary * complex.imaginary + status_complex.real;
		complex.imaginary = (2 * complex.real * complex.imaginary)
							+ status_complex.imaginary;
		complex.real = tmp;
		iter++;
	}
	return (iter);
}

int					mandelbrot(t_env *env)
{
	t_complex		pixel;
	t_complex		complex;
	t_color			color;
	t_delta			delta;

	delta.x = (get_tab()[env->type].quadrant.end.real
			- get_tab()[env->type].quadrant.origin.real) / (double)WIDTH;
	delta.y = (get_tab()[env->type].quadrant.end.imaginary
			- get_tab()[env->type].quadrant.origin.imaginary) / (double)HEIGHT;
	complex.imaginary = get_tab()[env->type].quadrant.origin.imaginary;
	pixel.imaginary = 0;
	while (pixel.imaginary < HEIGHT)
	{
		pixel.real = 0;
		complex.real = get_tab()[env->type].quadrant.origin.real;
		while (pixel.real < WIDTH)
		{
			color.color = interpolate(env->start_col, env->end_col, (double)get_iteration(complex) / (double)ITER_MAX);
			if (get_iteration(complex) < ITER_MAX)
				set_pixel(pixel.real, pixel.imaginary, env->img, color);
			else
				set_pixel(pixel.real, pixel.imaginary,
							env->img, set_color(BLACK));
			pixel.real++;
			complex.real += delta.x;
		}
		complex.imaginary += delta.y;
		pixel.imaginary++;
	}
	return (0);
}
