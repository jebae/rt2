/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_four.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:13:32 by mhernand          #+#    #+#             */
/*   Updated: 2019/08/29 16:13:34 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		verifyvocab_three(t_env *e) // /! string needs to be freed before returning error message /!
{
	int		end1;
	int		end2;

	e->p.voc_i = -1;
	e->p.voc_check = -1;
	end1 = (ft_strclen(e->p.split[0], '>') - ft_strclen(e->p.split[0], '<')) - 1;
	end2 = (ft_strclen(e->p.split[2], '>') - ft_strclen(e->p.split[2], '/')) - 1;
	e->p.strone = ft_strsub(e->p.split[0], ft_strclen(e->p.split[0], '<') + 1, end1);
	e->p.strtwo = ft_strsub(e->p.split[2], ft_strclen(e->p.split[2], '/') + 1, end2);
	if (ft_strcmp(e->p.strone, e->p.strtwo) != 0)
		return (-1);
	else
		while (++e->p.voc_i < 16)
			if (ft_strcmp(e->p.strone, e->p.vocab_two[e->p.voc_i]) == 0)
				e->p.voc_check++;
	if ((e->p.ret_p = verify_tag_to_argument(e, e->p.strone, 3)) != 0)
		return (e->p.ret_p);
	free(e->p.strone);
	e->p.strone = NULL;
	free(e->p.strtwo);
	e->p.strtwo = NULL;
	return (e->p.voc_check);
}

int		verifyanglebrackets_three(t_env *e)
{
	int		i;

	i = -1;
	e->p.set_one = 0;
	e->p.set_two = 0;
	while (e->p.split[0][++i])
	{
		if (e->p.split[0][i] == '<')
			e->p.set_one++;
		if (e->p.split[0][i] == '>')
			e->p.set_one++;
	}
	i = -1;
	while (e->p.split[2][++i])
	{
		if (e->p.split[2][i] == '<' && e->p.split[2][i + 1] == '/')
			e->p.set_two++;
		if (e->p.split[2][i] == '>')
			e->p.set_two++;
	}
	if (e->p.set_one != 2 || e->p.set_two != 2)
		return (-1);
	return (0);
}

int		verifyendings_three(t_env *e)
{
	if ((ft_strclen(e->p.split[0], ',') + 1) != ft_strlen(e->p.split[0]))
		return (-1);
	if ((ft_strclen(e->p.split[1], ',') + 1) != ft_strlen(e->p.split[1]))
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

int		verifyargs_three(t_env *e, t_ll **l_head, t_ol **o_head)
{
	(void)l_head;
	(void)o_head;
	if (verifyendings_three(e) == -1)
		return (18);
	e->p.comma = 0;
	e->p.comma += ft_charfreq(e->p.split[0], ',');
	e->p.comma += ft_charfreq(e->p.split[1], ',');
	e->p.comma += ft_charfreq(e->p.split[2], ',');
	if (e->p.comma != 2)
		return (19);
	e->p.strone = ft_strsub(e->p.split[0], ft_strclen(e->p.split[0], '>') + 1, \
		(ft_strclen(e->p.split[0], ',') - ft_strclen(e->p.split[0], '>')));
	e->p.strtwo = ft_strsub(e->p.gnl_line, 4, ft_strclen(e->p.gnl_line, '>') - 4);	
	if ((verifyargs_three_numbers(e->p.strone, ',') != 0))
		return (18);
	if ((verifyargs_three_numbers(e->p.split[1], ',') != 0)) 
		return (18);
	if ((verifyargs_three_numbers(e->p.split[2], '<') != 0))
		return (18);
	e->p.v1 = ft_atoi(e->p.strone);
	e->p.v2 = ft_atoi(e->p.split[1]); 
	e->p.v3 = ft_atoi(e->p.split[2]); 
	if ((e->p.ret_p = verify_numbers_three(e, *l_head, *o_head)) != 0) // working here 
		return (e->p.ret_p);  // working here, last verification (store data here)!
	ft_strfree(e->p.strone);
	ft_strfree(e->p.strtwo);
	return (0);
}