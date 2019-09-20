/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:21:07 by mhernand          #+#    #+#             */
/*   Updated: 2019/08/29 16:21:09 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rtv1.h"

int		open_close(int *check_me)
{
	if (*check_me == 0)
		return (7);
	*check_me += 1;
	return (0);
}

int		two_angle_brackets(t_parser *p)
{
	int	brackets;
	int	bad_brackets;
	int	i;
	int	j;

	brackets = 0;
	bad_brackets = 0;
	i = 0;
	j = -1;
	while (p->gnl_line[i] == '\t')
		i++;
	j = i;
	while (p->gnl_line[j])
	{
		if (j == i && p->gnl_line[j] == '<')
			brackets++;
		if (p->gnl_line[j] == '>' && p->gnl_line[j + 1] == '\0')
			brackets++;
		if (j != i && p->gnl_line[j + 1] != '\0' && (p->gnl_line[j] == '<'
			|| p->gnl_line[j] == '>'))
			bad_brackets++;
		j++;
	}
	return (brackets + bad_brackets);
}

int		extract_status(t_parser *p)
{
	int	i;

	i = 0;
	if (ft_strcmp("status", p->split[1]) != 0)
		return (14);
	if (ft_strcmp("=", p->split[2]) != 0)
		return (15);
	if (ft_strcmp("\"basic\">", p->split[3]) == 0)
		p->status = 1;
	else if (ft_strcmp("\"extra\">", p->split[3]) == 0)
		p->status = 2;
	else
		return (16);
	return (0);
}

int		verify_tag_to_argument_three(char *string)
{
	if (ft_strcmp("direction", string) == 0)
		return (0);
	else if (ft_strcmp("center", string) == 0)
		return (0);
	else if (ft_strcmp("normal", string) == 0)
		return (0);
	else if (ft_strcmp("diffusion", string) == 0)
		return (0);
	else if (ft_strcmp("rotate", string) == 0)
		return (0);
	else if (ft_strcmp("translate", string) == 0)
		return (0);
	else if (ft_strcmp("position", string) == 0)
		return (0);
	else if (ft_strcmp("color", string) == 0)
		return (0);
	else if (ft_strcmp("intensity", string) == 0)
		return (0);	
	else	
		return (82);
	return (0);
}

int		verify_tag_to_argument(t_parser *p, char *string, int args)
{
	p->tmp = ft_strdup(string);
	if (args == 1)
	{
		if (ft_strcmp("radius", string) == 0)
			return (0);
		else if (ft_strcmp("angle", string) == 0)
			return (0);
		else if (ft_strcmp("d", string) == 0)
			return (0);
		else if (ft_strcmp("specpower", string) == 0)
			return (0);
		else if (ft_strcmp("specvalue", string) == 0)
			return (0);
		else if (ft_strcmp("reflection", string) == 0)
			return (0);
		else
			return (81);
	}
	else
		if ((p->ret_p = verify_tag_to_argument_three(string)) != 0)
			return (p->ret_p);
	return (0);
}
