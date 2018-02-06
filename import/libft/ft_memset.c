/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 09:55:46 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/11 20:11:05 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*tab;
	size_t			i;

	i = 0;
	if (n == 0)
		return (str);
	tab = (unsigned char *)str;
	while (i < n)
	{
		tab[i] = (unsigned char)c;
		i++;
	}
	return (tab);
}
