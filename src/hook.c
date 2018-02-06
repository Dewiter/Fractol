/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:08:58 by rolevy            #+#    #+#             */
/*   Updated: 2018/02/06 04:24:23 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
*** - Hook functions to peripherals -
*/

void		hook(t_env *env)
{
	mlx_hook(env->win, MotionNotify, PointerMotionMask, &set_mouse_pos, env);
	mlx_hook(env->win, KeyPress, KeyPressMask, &hook_keyboard, env);
	mlx_hook(env->win, ButtonPress, ButtonPressMask, &hook_mouse, env);
	mlx_hook(env->win, DestroyNotify, BUTTON1, &quit, env);
}
