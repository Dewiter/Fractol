/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 03:15:01 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/22 08:14:08 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int		digit_size(int n)
{
	size_t digits;

	digits = 1;
	while ((n /= 10))
		digits++;
	return (digits);
}

char			*ft_itoa(int n)
{
	size_t	digits;
	int		sign;
	char	*tab;

	sign = n >= 0 ? 0 : 1;
	digits = digit_size(n) + sign;
	if ((tab = (char *)malloc(digits + 1)) == NULL)
		return (NULL);
	tab[digits] = '\0';
	while (digits--)
	{
		tab[digits] = n >= 0 ? '0' + n % 10 : '0' - n % 10;
		n /= 10;
	}
	if (sign)
		*tab = '-';
	return (tab);
}
