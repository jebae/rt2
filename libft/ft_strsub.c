/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:40:15 by mhernand          #+#    #+#             */
/*   Updated: 2019/08/14 14:47:08 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		index;

	index = 0;
	if (!s)
		return (NULL);
	ptr = ft_strnew(len);
	if (!ptr)
		return (NULL);
	while (index < (int)len)
	{
		ptr[index++] = (unsigned char)s[start];
		start++;
	}
	return (ptr);
}
