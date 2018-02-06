/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:20:18 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/24 17:21:26 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int nb, int power)
{
	int tmp;

	tmp = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	while (power > 1)
	{
		nb *= tmp;
		power--;
	}
	return (nb);
}
