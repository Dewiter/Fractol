/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:16:34 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/27 15:26:27 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_striter(char *s, void (*f)(char *))
{
	int i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(&s[i]);
		i++;
	}
}
