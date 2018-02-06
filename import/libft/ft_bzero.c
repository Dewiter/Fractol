/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:19:44 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/22 01:44:37 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*tab;

	tab = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		tab[i] = (unsigned char)NULL;
		i++;
	}
}
