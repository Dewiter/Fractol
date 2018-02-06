/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:36:06 by rolevy            #+#    #+#             */
/*   Updated: 2018/02/06 05:55:28 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_display_void				*get_disptab_void(void)
{
	static t_display_void	tab[DISPLAY_MAX] =
	{{&exit_fract, EXIT},
	{&fract_select, FRACTAL_CHOSEN},
	{&not_supported, NOT_SUPPORT}};

	return (tab);
}

void			exit_fract(void)
{
	ft_putstr(BLUE"["MAG"FRACTOL"BLUE"] ");
	ft_putstr(BLUE"[ ✓ ] ");
	ft_putstr(RED"Quiting Fract'ol\n");
}

void			fract_select(void *name)
{
	ft_putstr(BLUE"["MAG"FRACTOL"BLUE"]");
	ft_putstr(BLUE" [ ✓ ]");
	ft_putstr(" Fractal chosen ==> "GREEN);
	ft_putendl(name);
}

void			not_supported(void *name)
{
	ft_putstr(BLUE"["MAG"FRACTOL"BLUE"]");
	ft_putstr(BLUE" [ "RED"✘ "BLUE"] " RED);
	ft_putstr(name);
	ft_putstr(" is not supported\n");
}
