/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:40:36 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/19 17:22:37 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tab;

	tab = (t_list *)malloc(sizeof(tab) * content_size);
	if (!(tab))
		return (NULL);
	if (content == NULL)
	{
		tab->content = NULL;
		tab->content_size = 0;
	}
	else
	{
		if ((tab->content = malloc(content_size)) == NULL)
		{
			free(tab->content);
			return (NULL);
		}
		ft_memcpy(tab->content, content, content_size);
		tab->content_size = content_size;
	}
	tab->next = NULL;
	return (tab);
}
