/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:44:33 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/24 16:28:59 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*tab;
	size_t			i;

	i = 0;
	tab = (unsigned char *)str;
	while (i < n)
	{
		if (tab[i] == (unsigned char)c)
			return (tab + i);
		i++;
	}
	return (0);
}
