/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:40:14 by mhernand          #+#    #+#             */
/*   Updated: 2018/12/05 04:53:08 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;

	i = 0;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (size == 0)
	{
		while (len_s > i++)
		{
			if (dst[len_d + i] == '\0')
				dst[len_d + i] = '\0';
		}
		return (len_s);
	}
	while (src[i] && ((len_d + i) < (size - 1)))
	{
		dst[len_d + i] = src[i];
		++i;
	}
	dst[len_d + i] = '\0';
	if (len_d < size)
		return (len_d + len_s);
	return (len_s + size);
}
