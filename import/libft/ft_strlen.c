/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 09:51:37 by rolevy            #+#    #+#             */
/*   Updated: 2017/10/07 14:58:03 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t counter;
	size_t i;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		counter++;
		i++;
	}
	return (counter);
}
