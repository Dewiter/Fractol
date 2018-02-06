/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 01:33:06 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/27 15:29:52 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*tab;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!(tab))
		return (NULL);
	tab = ft_strcpy(tab, s1);
	tab = ft_strcat(tab, s2);
	return (tab);
}
