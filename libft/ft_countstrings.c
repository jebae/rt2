/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countstrings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:14:37 by mhernand          #+#    #+#             */
/*   Updated: 2019/08/07 19:30:24 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_countstrings(char **strings)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	while (strings[++i])
		count++;
	return (count);
}
