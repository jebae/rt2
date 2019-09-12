/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:55:35 by mhernand          #+#    #+#             */
/*   Updated: 2018/12/05 02:26:13 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;

	index = 0;
	if ((char)c == '\0')
	{
		while (s[index] != '\0')
			index++;
		if (s[index] == (char)c)
			return ((char*)s + index);
	}
	else
	{
		while (s[index] != '\0')
			index++;
		while (index >= 0)
		{
			if (s[index] == (char)c)
				return ((char*)s + index);
			index--;
		}
	}
	return (NULL);
}
