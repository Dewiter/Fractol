/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:32:13 by rolevy            #+#    #+#             */
/*   Updated: 2018/02/06 06:14:16 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
*** - Mouse related functions -
*/


int                     zoom(t_env *env, t_complex c)
{
    t_complex           quad;

    quad = get_tab()[env->type].quadrant.origin;
    quad.real = (ZOOM_P * (quad.real - c.real)) + c.real;
    quad.imaginary = (ZOOM_P * (quad.imaginary - c.imaginary)) + c.imaginary;
    get_tab()[env->type].quadrant.origin = quad;
    quad = get_tab()[env->type].quadrant.end;
    quad.real = (ZOOM_P * (quad.real - c.real)) + c.real;
    quad.imaginary = (ZOOM_P * (quad.imaginary - c.imaginary)) + c.imaginary;
    get_tab()[env->type].quadrant.end = quad;
    return (0);
}

int                     lock_mouse(t_env *env, t_complex c)
{
    if (env->mouse_state == MOUSE_UNLOCK)
    {
        c = env->mouse_pos;
        env->mouse_lock = c;
        env->mouse_state = MOUSE_LOCK;
        get_disptab()[D_MOUSE_STATE].function(env);
    }
    else
    {
        env->mouse_state = MOUSE_UNLOCK;
        get_disptab()[D_MOUSE_STATE].function(env);
    }
    return (0);
}

int                     dezoom(t_env *env, t_complex c)
{
    t_complex           quad;
    
    quad = get_tab()[env->type].quadrant.origin;
    quad.real = (ZOOM_M * (quad.real - c.real)) + c.real;
    quad.imaginary = (ZOOM_M * (quad.imaginary - c.imaginary)) + c.imaginary;
    get_tab()[env->type].quadrant.origin = quad;
    quad = get_tab()[env->type].quadrant.end;
    quad.real = (ZOOM_M * (quad.real - c.real)) + c.real;
    quad.imaginary = (ZOOM_M * (quad.imaginary - c.imaginary)) + c.imaginary;
    get_tab()[env->type].quadrant.end = quad;
    return (0);
}

int                     set_mouse_pos(int x, int y, t_env *env)
{
    t_complex           c;
    t_delta             delta;

    delta.x = (get_tab()[env->type].quadrant.end.real
                - get_tab()[env->type].quadrant.origin.real) / (double)WIDTH;
    delta.y = (get_tab()[env->type].quadrant.end.imaginary
            - get_tab()[env->type].quadrant.origin.imaginary) / (double)HEIGHT;
    c = (t_complex){((delta.x * x) + get_tab()[env->type].quadrant.origin.real),
        ((delta.y * y) + get_tab()[env->type].quadrant.origin.imaginary)};
    env->mouse_pos.real = c.real;
    env->mouse_pos.imaginary = c.imaginary;
    return (0);
}

int                     hook_mouse(int input, int x, int y, t_env *env)
{
    t_delta             delta;
    t_complex           c;
    int i;

    delta.x = (get_tab()[env->type].quadrant.end.real
            - get_tab()[env->type].quadrant.origin.real) / (double)WIDTH;
    delta.y = (get_tab()[env->type].quadrant.end.imaginary
            - get_tab()[env->type].quadrant.origin.imaginary) / (double)HEIGHT;
    c = (t_complex){((delta.x * x) + get_tab()[env->type].quadrant.origin.real),
                ((delta.y * y) + get_tab()[env->type].quadrant.origin.imaginary)};

    i = 0;
    while (i < MOUSE_MAX)
    {
        if (get_mouse_tab()[i].input == input)
            get_mouse_tab()[i].function(env, c);
        i++;
    }
    return (0);
}