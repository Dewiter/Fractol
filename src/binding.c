/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:03:39 by rolevy            #+#    #+#             */
/*   Updated: 2018/01/31 16:09:24 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*** - Binding keys and mouse buttons to fucntions -
*/

#include "../includes/header.h"

void				bind(t_env *env)
{
	mlx_hook(env->win, MotionNotify, PointerMotionMask, &get_mouse, env);
	mlx_hook(env->win, KeyPress, KeyPressMask, &check_key, &env);
	mlx_hook(env->win, DestroyNotify, ButtonPressMask, &quit, env);
	mlx_hook(env->win, ButtonPress, ButtonPressMask, &check_button, env);
}
