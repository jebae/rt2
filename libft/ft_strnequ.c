/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:38:52 by mhernand          #+#    #+#             */
/*   Updated: 2018/12/04 21:53:56 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int n_cmp;

	if ((!s1) || (!s2))
		return (0);
	n_cmp = ft_strncmp(s1, s2, n);
	if (n_cmp == 0)
		return (1);
	else
		return (0);
}
