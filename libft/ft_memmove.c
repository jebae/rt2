/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:51:35 by mhernand          #+#    #+#             */
/*   Updated: 2018/11/26 17:57:26 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_src;
	unsigned char	*new_dst;
	size_t			index;
	size_t			overlap;

	new_src = (unsigned char*)src;
	new_dst = (unsigned char*)dst;
	index = -1;
	overlap = (size_t)(dst - src);
	if (overlap > 0 && overlap < len)
	{
		while (len--)
			new_dst[len] = new_src[len];
	}
	else
	{
		while (++index < len)
			new_dst[index] = new_src[index];
	}
	return (new_dst);
}
