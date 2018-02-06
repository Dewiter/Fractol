/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:35:48 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/27 15:27:33 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*tab;
	size_t	size;

	if (!s || !f)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	tab = ft_strnew(size);
	if (!(tab))
		return (NULL);
	while (s[i])
	{
		tab[i] = f(i, s[i]);
		i++;
	}
	return (tab);
}
