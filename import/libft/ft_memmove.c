/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 21:20:10 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/24 16:50:20 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *)str1;
	src = (unsigned char *)str2;
	if (str1 < str2)
		return (ft_memcpy(str1, str2, n));
	else
	{
		while (n > 0)
		{
			n--;
			dest[n] = src[n];
		}
		return (dest);
	}
}
