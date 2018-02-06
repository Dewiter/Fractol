/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 10:32:24 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/18 18:02:34 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strrchr(const char *str, int c)
{
	char	*tab;

	tab = (char *)str + ft_strlen(str);
	while (*tab != c)
	{
		if (tab == str)
			return (NULL);
		tab--;
	}
	return (tab);
}
