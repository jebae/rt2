/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:20:36 by mhernand          #+#    #+#             */
/*   Updated: 2018/12/04 20:42:41 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	long	neg;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' ||
			str[i] == '\r' || str[i] == ' ' || str[i] == '\f')
		i++;
	neg = (str[i] == '-' ? neg * -1 : neg * 1);
	i = (str[i] == '+' ? i + 1 : i);
	if (neg == -1)
		i = i + 1;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || '9' < str[i])
			return (res * neg);
		else
			res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * neg);
}
