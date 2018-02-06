/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 19:44:51 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/22 04:32:14 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char *cpy;

	cpy = NULL;
	cpy = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (cpy != NULL)
		ft_strncpy(cpy, src, n);
	return (cpy);
}
