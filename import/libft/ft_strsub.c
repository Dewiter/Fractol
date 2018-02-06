/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 03:23:05 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/27 16:06:31 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	if (!s)
		return (NULL);
	tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!(tab))
		return (NULL);
	i = 0;
	while (i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
