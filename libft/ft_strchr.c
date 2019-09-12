/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:53:27 by mhernand          #+#    #+#             */
/*   Updated: 2018/11/20 16:04:40 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	new_c;

	index = 0;
	new_c = (char)c;
	if (new_c == '\0')
	{
		while (s[index] != '\0')
			index++;
		if (s[index] == new_c)
			return ((char*)s + index);
	}
	else
	{
		while (s[index] != '\0')
		{
			if (s[index] == new_c)
				return ((char*)s + index);
			index++;
		}
	}
	return (NULL);
}
