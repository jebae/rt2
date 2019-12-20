/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_parser_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:32:54 by mhernand          #+#    #+#             */
/*   Updated: 2019/12/20 13:34:07 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_turn_byte_on(int *op_cl, int num)
{
	int	i;

	i = 9;
	if ((*op_cl & 1UL << 8) == 0 || (*op_cl & 1UL << num))
		return (0);
	while (++i < 19)
		if ((*op_cl & 1UL << i))
			return (0);
	*op_cl |= 1UL << num;
	return (1);
}

int		ft_turn_byte_off(int *op_cl, int num)
{
	int	i;

	i = 10;
	if ((*op_cl & 1UL << 8) == 0 || !(*op_cl & 1UL << num))
		return (0);
	while (++i < 19)
		if ((*op_cl & 1UL << i) == 1)
			return (0);
	*op_cl &= ~(1UL << num);
	return (1);
}
