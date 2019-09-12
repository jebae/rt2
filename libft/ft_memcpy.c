/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:13:48 by mhernand          #+#    #+#             */
/*   Updated: 2018/11/22 20:36:56 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*new_dst;
	unsigned const char	*new_src;
	size_t				i;

	new_dst = dst;
	new_src = src;
	i = 0;
	if (n == 0 || new_src == new_dst)
		return (new_dst);
	while (i < n)
	{
		new_dst[i] = new_src[i];
		i++;
	}
	return (new_dst);
}
