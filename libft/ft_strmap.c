/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:37:54 by mhernand          #+#    #+#             */
/*   Updated: 2018/11/26 18:16:49 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	int		index;
	int		len;
	char	*ptr;

	if (!s)
		return (0);
	index = 0;
	len = ft_strlen(s);
	ptr = (char*)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (s[index] != '\0')
	{
		ptr[index] = (*f)(s[index]);
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}
