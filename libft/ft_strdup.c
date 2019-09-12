/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 20:52:28 by mhernand          #+#    #+#             */
/*   Updated: 2018/11/26 17:40:32 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*cpy_str;
	int		i;
	int		str_len;

	i = 0;
	str_len = ft_strlen(s1);
	cpy_str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!cpy_str)
		return (NULL);
	while (i < str_len)
	{
		cpy_str[i] = s1[i];
		i++;
	}
	cpy_str[i] = '\0';
	return (cpy_str);
}
