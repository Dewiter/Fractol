/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 04:56:48 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/18 13:42:18 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && ((unsigned char)s1[i] || (unsigned char)s2[i]) &&
	((unsigned char)s1[i] == (unsigned char)s2[i]))
		i++;
	if (i == n)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
