/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_threeargs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:13:32 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/24 14:24:16 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		verifyvocab_three(t_parser *p)
{
	int		end1;
	int		end2;

	p->voc_i = -1;
	p->voc_check = -1;
	end1 = (ft_strclen(p->split[0], '>') - ft_strclen(p->split[0], '<')) - 1;
	end2 = (ft_strclen(p->split[2], '>') - ft_strclen(p->split[2], '/')) - 1;
	p->strone = ft_strsub(p->split[0], ft_strclen(p->split[0], '<') + 1, end1);
	p->strtwo = ft_strsub(p->split[2], ft_strclen(p->split[2], '/') + 1, end2);
	if (ft_strcmp(p->strone, p->strtwo) != 0)
		return (-1);
	else
		while (++p->voc_i < 16)
			if (ft_strcmp(p->strone, p->vocab_two[p->voc_i]) == 0)
				p->voc_check++;
	if ((p->ret_p = verify_tag_to_argument(p, p->strone, 3)) != 0)
		return (p->ret_p);
	ft_strfree(p->strone);
	ft_strfree(p->strtwo);
	return (p->voc_check);
}

int		verifyanglebrackets_three(t_parser *p)
{
	int		i;

	i = -1;
	p->set_one = 0;
	p->set_two = 0;
	while (p->split[0][++i])
	{
		if (p->split[0][i] == '<')
			p->set_one++;
		if (p->split[0][i] == '>')
			p->set_one++;
	}
	i = -1;
	while (p->split[2][++i])
	{
		if (p->split[2][i] == '<' && p->split[2][i + 1] == '/')
			p->set_two++;
		if (p->split[2][i] == '>')
			p->set_two++;
	}
	if (p->set_one != 2 || p->set_two != 2)
		return (-1);
	return (0);
}

int		verifyendings_three(t_parser *p)
{
	if ((ft_strclen(p->split[0], ',') + 1) != ft_strlen(p->split[0]))
		return (-1);
	if ((ft_strclen(p->split[1], ',') + 1) != ft_strlen(p->split[1]))
		return (-1);
	return (0);
}

int		verifyargs_three_numbers(char *string, int letter)
{
	int		num_check;
	int		fake_check;
	int		i;

	i = 0;
	num_check = 0;
	fake_check = 0;
	if (string[i] == '-')
		i++;
	while (string[i] != letter)
	{
		if (ft_isdigit(string[i]) == 1)
			num_check++;
		if (ft_isdigit(string[i]) == 0)
			fake_check++;
		i++;
	}
	if (fake_check > 0 || num_check == 0)
		return (-1);
	if (num_check > 0)
		return (0);
	return (0);
}

int		verifyargs_three(t_env *e, t_parser *p, t_ll **l_head, t_ol **o_head)
{
	if (verifyendings_three(p) == -1)
		return (18);
	p->comma = 0;
	p->comma += ft_charfreq(p->split[0], ',');
	p->comma += ft_charfreq(p->split[1], ',');
	p->comma += ft_charfreq(p->split[2], ',');
	if (p->comma != 2)
		return (19);
	p->strone = ft_strsub(p->split[0], ft_strclen(p->split[0], '>') + 1, \
			(ft_strclen(p->split[0], ',') - ft_strclen(p->split[0], '>')));
	p->strtwo = ft_strsub(p->gnl_line, 4, ft_strclen(p->gnl_line, '>') - 4);
	if ((verifyargs_three_numbers(p->strone, ',') != 0))
		return (18);
	if ((verifyargs_three_numbers(p->split[1], ',') != 0))
		return (18);
	if ((verifyargs_three_numbers(p->split[2], '<') != 0))
		return (18);
	p->v1 = ft_atoi(p->strone);
	p->v2 = ft_atoi(p->split[1]);
	p->v3 = ft_atoi(p->split[2]);
	if ((p->ret_p = verify_numbers_three(e, p, *l_head, *o_head)) != 0)
		return (p->ret_p); // something here ?
	ft_strfree(p->strone);
	ft_strfree(p->strtwo);
	return (0);
}
