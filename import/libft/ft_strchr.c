/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 10:21:41 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/18 17:50:25 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = (char *)str;
	while (tab[i] != c)
	{
		if (tab[i] == '\0')
			return (NULL);
		i++;
	}
	return (tab + i);
}
