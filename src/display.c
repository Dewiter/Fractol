/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 05:55:59 by rolevy            #+#    #+#             */
/*   Updated: 2018/02/06 06:15:58 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_display       *get_disptab(void)
{
    static t_display tab[FRACT_DISP_MAX] =
    {{change, D_CHANGE},
    {mouse_state, D_MOUSE_STATE}};
    
    return (tab);
}

void			change(t_env *env)
{
	ft_putstr(BLUE"["MAG"FRACTOL"BLUE"] ");
	ft_putstr(BLUE"[ ✓ ]");
	ft_putstr(" Changing to ==> "GREEN);
	ft_putendl(get_tab()[env->type].name);
}

void            mouse_state(t_env *env)
{
    if (env->mouse_state == MOUSE_LOCK)
    {
        ft_putstr(BLUE"["MAG"FRACTOL"BLUE"] ");
	    ft_putstr(BLUE"[ ✓ ]");
        ft_putendl(GREEN" Mouse locked");
    }
    else if (env->mouse_state == MOUSE_UNLOCK)
    {
        ft_putstr(BLUE"["MAG"FRACTOL"BLUE"] ");
	    ft_putstr(BLUE"[ ✓ ]");
        ft_putendl(GREEN" Mouse unlocked");
    }
}