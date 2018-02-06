/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 21:08:11 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/11 13:05:27 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t j;

	j = 0;
	while (j < n && src[j])
	{
		dest[j] = src[j];
		j++;
	}
	while (j < n && dest[j])
	{
		dest[j] = '\0';
		j++;
	}
	return (dest);
}
