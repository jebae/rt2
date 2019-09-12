/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:46:45 by mhernand          #+#    #+#             */
/*   Updated: 2018/11/29 22:15:05 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			j;
	unsigned char	*hay;
	unsigned char	*ned;

	i = 0;
	hay = (unsigned char*)haystack;
	ned = (unsigned char*)needle;
	while (hay[i] != '\0')
	{
		j = 0;
		while (ned[j] == hay[i + j] && i < len)
		{
			if (ned[j + 1] == '\0' && i + j < len)
				return ((char*)haystack + i);
			j++;
		}
		i++;
	}
	return (ned[0] == '\0' ? (char*)haystack : NULL);
}
