/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:10:56 by rolevy            #+#    #+#             */
/*   Updated: 2018/02/06 06:18:32 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
*** - Keyboard related functions -
*/

t_key				*get_key_tab(void)
{
	static t_key	key_tab[KEY_MAX] =
	{{KEY_ESCAPE, &quit, QUIT},
	{KEY_N, &next, NEXT}};

	return (key_tab);
}

int					next(int input, t_env *env)
{
	if (env->type >= FRACT_MAX - 1)
		env->type = MANDELBROT;
	else if (env->type <= FRACT_MAX - 1)
		env->type++;
	get_disptab()[D_CHANGE].function(env);
	get_tab()[env->type].function(env);
	return (0);
}

int					hook_keyboard(int input, t_env *env)
{
	int				i;

	i = 0;
	while (i < KEY_MAX)
	{
		if (get_key_tab()[i].input == input)
			get_key_tab()[i].function(env);
		i++;
	}
	return (0);
}
