/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:40:44 by mhernand          #+#    #+#             */
/*   Updated: 2018/11/20 13:46:28 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new_s;
	size_t			index;
	void			*ptr;

	new_s = (unsigned char*)s;
	index = 0;
	while (index < n)
	{
		if (new_s[index] == (unsigned char)c)
		{
			ptr = (void*)&new_s[index];
			return (ptr);
		}
		index++;
	}
	return (NULL);
}
