/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 09:50:00 by rolevy            #+#    #+#             */
/*   Updated: 2017/04/11 12:12:57 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int s;
	int number;

	s = 1;
	number = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		s *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + (*str - '0');
		str++;
	}
	return ((number * s));
}
