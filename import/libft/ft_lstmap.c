/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:32:08 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/24 15:38:17 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tab;

	tab = (t_list *)malloc(sizeof(t_list));
	if (!tab)
		return (NULL);
	if (lst)
	{
		tab = f(lst);
		tab->next = ft_lstmap(lst->next, f);
		return (tab);
	}
	return (NULL);
}
