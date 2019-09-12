/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:37:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/01/12 16:38:18 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*freshstring;
	int		s_len;
	int		i;
	int		j;

	i = 0;
	if ((!s1) && (!s2))
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s_len = ft_strlen(s1) + ft_strlen(s2);
	freshstring = (char*)malloc(sizeof(char) * (s_len + 1));
	if (!freshstring)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
		freshstring[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		freshstring[i++] = s2[j++];
	freshstring[i] = '\0';
	return (freshstring);
}
