/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:59:23 by rolevy            #+#    #+#             */
/*   Updated: 2018/02/06 02:13:52 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
***  - Creating environement -
*/

t_env	*create_env(t_env *env)
{
	if ((env = (t_env *)malloc(sizeof(t_env))) == NULL)
		exit(EXIT_FAILURE);
	env->width = WIDTH;
	env->height = HEIGHT;
	env->mlx = mlx_init();
	env->mouse_pos = (t_complex){0, 0};
	env->mouse_lock = (t_complex){0, 0};
	env->mouse_state = MOUSE_UNLOCK;
	env->win = mlx_new_window(env->mlx, env->width, env->height, "Fractol");
	env->img = create_img(env, env->width, env->height);
	return (env);
}
