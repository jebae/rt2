/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:49:16 by mhernand          #+#    #+#             */
/*   Updated: 2018/12/05 02:16:08 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	unsigned int index;

	index = 0;
	if ((!s) || (!f))
		return ;
	while (s[index] != '\0')
	{
		f(index, &s[index]);
		index++;
	}
}
