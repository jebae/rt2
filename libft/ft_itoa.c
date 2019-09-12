/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:01:17 by mhernand          #+#    #+#             */
/*   Updated: 2018/12/05 02:21:17 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	myints(long nb, char *ptr, size_t *i)
{
	if (nb < 0)
	{
		ptr[(*i)++] = '-';
		myints(-nb, ptr, i);
	}
	else if (nb < 10)
		ptr[(*i)++] = nb + '0';
	else
	{
		myints(nb / 10, ptr, i);
		myints(nb % 10, ptr, i);
	}
}

char		*ft_itoa(int n)
{
	size_t	i;
	char	*ptr;
	int		n_tmp;

	i = 0;
	n_tmp = n;
	if ((n_tmp <= 0))
		i += 1;
	while (n_tmp)
	{
		n_tmp /= 10;
		i++;
	}
	ptr = ft_strnew(i);
	if (!ptr)
		return (NULL);
	i = 0;
	myints((long)n, ptr, &i);
	return (ptr);
}
