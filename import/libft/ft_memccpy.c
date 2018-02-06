/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 12:10:21 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/24 16:25:53 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void				*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	*dest;
	size_t			i;

	i = 0;
	dest = (unsigned char *)str1;
	src = (unsigned char *)str2;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
