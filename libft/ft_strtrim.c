/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:40:37 by mhernand          #+#    #+#             */
/*   Updated: 2018/12/02 17:40:39 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ptr;
	int		i;
	int		len;

	i = 0;
	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return ((char*)s);
	while (s[i] && (s[i] == '\n' || s[i] == '\t' || s[i] == ' '))
		i++;
	len = ft_strlen(s);
	if (len == 0)
		return (ft_strnew(len));
	while (s[len - 1] == '\n' || s[len - 1] == '\t' || s[len - 1] == ' ')
		len--;
	if (len == 0 && len + 1 == 0 && len - i == 0)
		return (0);
	if (!(ptr = ft_strsub(s, i, len - i)))
		return (NULL);
	ptr[len] = '\0';
	return (ptr);
}
