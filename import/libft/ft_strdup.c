/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 04:30:07 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/15 22:43:59 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *cpy;

	cpy = NULL;
	cpy = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (cpy != NULL)
		ft_strcpy(cpy, src);
	return (cpy);
}
