/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:39:07 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/22 03:09:39 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;

	tab = (char *)malloc(sizeof(char) * (size + 1));
	if (!(tab))
		return (NULL);
	ft_bzero(tab, size + 1);
	return (tab);
}
