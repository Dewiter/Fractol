/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 23:15:08 by rolevy            #+#    #+#             */
/*   Updated: 2018/02/06 05:43:02 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static inline int	get_iteration(t_complex status_complex, t_env *env)
{
	int				iter;
	double			tmp;
	t_complex		complex;
	double			square[2];

	iter = 0;
	square[0] = status_complex.real * status_complex.real;
	square[1] = status_complex.imaginary * status_complex.imaginary;
	if (env->mouse_state == MOUSE_UNLOCK)
		complex = env->mouse_pos;
	else
		complex = env->mouse_lock;
	while (square[0] + square[1] < 4 && iter < ITER_MAX)
	{
		square[0] = status_complex.real * status_complex.real;
		square[1] = status_complex.imaginary * status_complex.imaginary;
		tmp = square[0] - square[1] + complex.real;
		status_complex.imaginary = (2 * status_complex.real *
									status_complex.imaginary)
									+ complex.imaginary;
		status_complex.real = tmp;
		iter++;
	}
	return (iter);
}

int					julia(t_env *env)
{
	t_complex		pixel;
	t_complex		complex;
	t_color			color;
	t_delta			delta;

	delta.x = (get_tab()[env->type].quadrant.end.real
			- get_tab()[env->type].quadrant.origin.real) / (double)WIDTH;
	delta.y = (get_tab()[env->type].quadrant.end.imaginary
			- get_tab()[env->type].quadrant.origin.imaginary) / (double)HEIGHT;
	pixel.imaginary = 0;
	complex.imaginary = get_tab()[env->type].quadrant.origin.imaginary;
	while (pixel.imaginary < HEIGHT)
	{
		pixel.real = 0;
		complex.real = get_tab()[env->type].quadrant.origin.real;
		while (pixel.real < WIDTH)
		{
			color.color = interpolate(env->start_col, env->end_col, (double)get_iteration(complex, env) / (double)ITER_MAX);
			if (get_iteration(complex, env) < ITER_MAX)
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
