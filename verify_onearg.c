/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:59:46 by mhernand          #+#    #+#             */
/*   Updated: 2019/08/29 15:59:47 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

int		verifyanglebrackets_one(t_env *e)
{
	e->p.l = -1;
	e->p.e1 = 0;
	e->p.e2  = 0;
	e->p.t = ft_strtrim(e->p.gnl_line);
	if (e->p.t[0] != '<' || e->p.t[ft_strlen(e->p.t) - 1] != '>')
	{
		free(e->p.t);
		e->p.t = NULL;
		return (-1);
	}
	while (e->p.t[++e->p.l])
	{
		if (e->p.t[e->p.l] == '<' && e->p.l == 0)
			e->p.e1 ++;
		if (e->p.t[e->p.l] == '>' && e->p.t[e->p.l + 1] != '\0' && e->p.e1 == 1)
			e->p.e1 ++;
		if (e->p.t[e->p.l] == '<' && e->p.t[e->p.l + 1] == '/')
			e->p.e2 ++;
		if (e->p.t[e->p.l] == '>' && e->p.t[e->p.l + 1] == '\0' && e->p.e2 == 1)
			e->p.e2 ++;
	}
	if (e->p.e1 != 2 || e->p.e2 != 2)
		return (-1);
	free(e->p.t);
	e->p.t = NULL;
	return (0);
}

int		verifyvocab_one(t_env *e) // /! string needs to be freed before returning error message /!
{
	e->p.voc_i = -1;
	e->p.voc_check = -1;
	e->p.i = ft_strclen(e->p.gnl_line, '<') + 1;
	e->p.j = ft_strclen(e->p.gnl_line, '>');
	e->p.k = ft_strclen(e->p.gnl_line, '/') + 1;
	e->p.strone = ft_strsub(e->p.gnl_line, e->p.i, (e->p.j - e->p.i));
	e->p.i = ft_strlen(e->p.gnl_line) - 1;
	if (e->p.gnl_line[e->p.i] != '>')
		return (-1);
	e->p.strtwo = ft_strsub(e->p.gnl_line, e->p.k, (e->p.i - e->p.k));
	if (ft_strcmp(e->p.strone, e->p.strtwo) != 0)
		return (-1);
	else
		while (++e->p.voc_i < 16) // could be seg faulting here ... ! ! !
			if (ft_strcmp(e->p.strone, e->p.vocab_two[e->p.voc_i]) == 0)
				e->p.voc_check++;
	if ((e->p.ret_p = verify_tag_to_argument(e, e->p.strone, 1)) != 0)
		return (e->p.ret_p);
	free(e->p.strone);
	e->p.strone = NULL;
	free(e->p.strtwo);
	e->p.strtwo = NULL;
	return (e->p.voc_check);
}

int		verifyargs_one(t_env *e, t_ll **l_head, t_ol **o_head)
{
	int		i;
	int		num_check;
	int		fake_check;

	i = 0;
	num_check = 0;
	fake_check = 0;
	e->p.strone = ft_strsub(e->p.gnl_line, e->p.j + 1, ((e->p.k - 3) - e->p.j));
	e->p.strtwo = ft_strsub(e->p.gnl_line, 4, ft_strclen(e->p.gnl_line, '>') - 4);
	if (e->p.strone[i] == '-')
		i++;
	while (e->p.strone[i])
	{
		if (ft_isdigit(e->p.strone[i]) == 1)
			num_check++;
		if (ft_isdigit(e->p.strone[i]) == 0)
			fake_check++;
		i++;
	}
	if ((e->p.ret_p = verify_numbers_one(e, *l_head, *o_head)) != 0)
		return (e->p.ret_p); // working here, last verification ( & store data here ) !
	if (fake_check > 0 || num_check == 0)
		return (18);
	ft_strfree(e->p.strone);
	ft_strfree(e->p.strtwo);
	return (0);
}