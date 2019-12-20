/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_parser_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:32:07 by mhernand          #+#    #+#             */
/*   Updated: 2019/12/20 13:33:51 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_brackets(char *line)
{
	int i;
	int b1s;
	int b2s;

	i = 0;
	b1s = 0;
	b2s = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '<' && i == 0)
			b1s++;
		if (line[i] == '<' && line[i + 1] == '/')
			b1s++;
		if (line[i] == '>' && b1s == 1)
			b2s++;
		if (line[i] == '>' && line[i + 1] == '\0')
			b2s++;
		i++;
	}
	if (b1s != 2 || b2s != 2)
		return (0);
	return (1);
}

int		ft_one_bracket(char *line, int b_ret)
{
	int	i;
	int	bs;

	i = 0;
	bs = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '<' && i == 0)
		{
			if (line[i + 1] != '/' && b_ret == 1)
				bs++;
			else if (line[i + 1] == '/' && b_ret == 2)
				bs++;
		}
		if (line[i] == '>' && line[i + 1] == '\0' && bs == 1)
			bs++;
		i++;
	}
	if (bs != 2)
		return (0);
	return (1);
}

int		ft_check_spec_bytes_opening(int *op_cl)
{
	int	i;

	i = 1;
	while (++i < 10)
	{
		if (i % 2 == 0)
		{
			if ((*op_cl & 1UL << i) && !(*op_cl & 1UL << (i + 1)))
				return (0);
			else if (!(*op_cl & 1UL << i) && (*op_cl & 1UL << (i + 1)))
				return (0);
		}
	}
	return (1);
}

int		ft_check_spec_bytes_closing(int *op_cl, int num)
{
	int	i;

	i = 1;
	if (!(*op_cl & 1UL << num))
		return (0);
	while (++i < 10)
	{
		if (i % 2 == 0 && i != num)
		{
			if ((*op_cl & 1UL << i) && !(*op_cl & 1UL << (i + 1)))
				return (0);
			else if (!(*op_cl & 1UL << i) && (*op_cl & 1UL << (i + 1)))
				return (0);
		}
	}
	return (1);
}
