/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:08:37 by rolevy            #+#    #+#             */
/*   Updated: 2018/01/29 14:27:46 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_mouse				*get_mouse_tab(void)
{
	static t_mouse	mouse_tab[MOUSE_MAX] =
	{{BUTTON5, &zoom, ZOOM_PLUS},
	{BUTTON4, &dezoom, ZOOM_MIN},
	{BUTTON1, &lock_mouse, JULIA_SET}};

	return (mouse_tab);
}
