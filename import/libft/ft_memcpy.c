/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:34:55 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/18 13:03:46 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned char	*src;
	unsigned char	*dest;
	size_t			i;

	dest = (unsigned char *)str1;
	src = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (str1);
}
