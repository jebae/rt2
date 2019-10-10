/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charfreq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:46:02 by mhernand          #+#    #+#             */
/*   Updated: 2019/08/07 18:50:25 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_charfreq(char *str, int c)
{
	size_t	freq;
	size_t	i;

	freq = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			freq++;
		i++;
	}
	return (freq);
}
