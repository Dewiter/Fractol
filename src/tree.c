/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:10:01 by rolevy            #+#    #+#             */
/*   Updated: 2017/12/07 17:18:30 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static inline void		draw_branch(int len, t_env *env)
{
	double x;
	double y;

	x = WIDTH / 2;
	y = HEIGHT;
	while (y >= len)
	{
		set_pixel(x, y, env->img, set_color(WHITE));
		y--;
	}
}

static inline int		get_iteration(t_complex iter_complex)
{
	int					iter;
	double				tmp;
	t_complex			complex;

	iter = 0;
	complex = (t_complex){0, 0};
	while (complex.re * complex.re +
			complex.im * complex.im < 4 && iter < ITERATION_MDL)
	{
		tmp = complex.re * complex.re
			- complex.im * complex.im + iter_complex.re;
		complex.im = 2 * complex.re * complex.im + iter_complex.im;
		complex.re = tmp;
		iter++;
	}
	return (iter);
}

void					tree(t_env *env)
{
	// t_complex			complex;
	// t_complex			pixel;
	// t_color				color;
	// double				delta[2];

	// delta[0] = (GET_FTAB(env).end.re - GET_FTAB(env).origin.re) / (double)WIDTH;
	// delta[1] = (GET_FTAB(env).end.im - GET_FTAB(env).origin.im) /
	// 			(double)HEIGHT;
	// complex.im = GET_FTAB(env).origin.im;
	// pixel = (t_complex){0, 0};
	// while (pixel.im < HEIGHT)
	// {
	// 	pixel.re = 0;
	// 	complex.re = GET_FTAB(env).origin.re;
	// 	while (pixel.re < WIDTH)
	// 	{
	// 		color.color = get_palette()[(int)get_iteration(complex)];
	// 		set_pixel((int)pixel.re, (int)pixel.im, env->img, color);
	// 		pixel.re++;
	// 		complex.re += delta[0];
	// 	}
	// }
	// complex.im += delta[1];
	// pixel.im++;
}
