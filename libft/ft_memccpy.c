/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:52:16 by mhernand          #+#    #+#             */
/*   Updated: 2018/11/22 20:37:31 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	size_t			index;

	new_dst = (unsigned char*)dst;
	new_src = (unsigned char*)src;
	index = 0;
	while (index < n)
	{
		new_dst[index] = new_src[index];
		if (new_src[index] == (unsigned char)c)
			return (new_dst + (index + 1));
		index++;
	}
	return (NULL);
}
