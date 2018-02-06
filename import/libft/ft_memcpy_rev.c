/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:34:55 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/24 16:38:22 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memcpy_rev(void *str1, const void *str2, size_t n)
{
	unsigned char	*src;
	unsigned char	*dest;

	dest = (unsigned char *)str1;
	src = (unsigned char *)str2;
	if (src[0] == '\0' || n == 0)
		return (str1);
	while (n--)
		dest[n] = src[n];
	return (str1);
}
