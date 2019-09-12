/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:22:34 by mhernand          #+#    #+#             */
/*   Updated: 2018/11/26 19:18:37 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int cmp;

	if ((!s1) || (!s2))
		return (0);
	cmp = ft_strcmp(s1, s2);
	if (cmp == 0)
		return (1);
	else
		return (0);
}
