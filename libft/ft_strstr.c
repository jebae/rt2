/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:25:10 by mhernand          #+#    #+#             */
/*   Updated: 2018/12/07 13:32:16 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int				i;
	int				j;
	unsigned char	*hay;
	unsigned char	*ned;

	i = 0;
	hay = (unsigned char*)haystack;
	ned = (unsigned char*)needle;
	if (ned[0] == '\0')
		return ((char*)haystack);
	else
	{
		while (i < hay[i])
		{
			j = 0;
			while (ned[j] == hay[i + j])
			{
				if (ned[j + 1] == '\0')
					return ((char*)haystack + i);
				j++;
			}
			i++;
		}
	}
	return (NULL);
}
