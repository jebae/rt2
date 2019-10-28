/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:01:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/24 14:00:54 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		threetab_verify(t_env *e, t_parser *p, t_ll **l_head, t_ol **o_head)
{
	if (p->str_count == 3)
	{
		if ((p->ret_p = verifyanglebrackets_three(p)) == -1)
			return (17);
		if ((p->ret_p = verifyvocab_three(p)) != 0)
			return (p->ret_p);
		if ((p->ret_p = verifyargs_three(e, p, l_head, o_head)) != 0)
			return (p->ret_p);
	}
	else if (p->str_count == 1)
	{
		if ((p->ret_p = verifyanglebrackets_one(p)) == -1)
			return (17);
		if ((p->ret_p = verifyvocab_one(p)) != 0)
			return (p->ret_p);
		if ((p->ret_p = verifyargs_one(e, p, l_head, o_head)) != 0)
			return (p->ret_p);
	}
	else
		return (17);
	return (0);
}

int		verify_line_seg1(t_env *e, t_parser *p, t_ll **l_head, t_ol **o_head)
{
	if (ft_charfreq(p->gnl_line, '\t') < 2
			|| ft_charfreq(p->gnl_line, '\t') > 3)
		return (5);
	if (ft_charfreq(p->gnl_line, '\t') == 2)
		if ((p->ret_p = two_tabs_specs(e, p, l_head)) != 0)
			return (p->ret_p);
	if (ft_charfreq(p->gnl_line, '\t') == 3)
	{
		if ((p->ret_p = verify_spec_atb(p)) != 0)
			return (p->ret_p);
		if ((p->ret_p = threetab_verify(e, p, l_head, o_head)) != 0)
			return (p->ret_p);
	}
	return (0);
}

int		verify_line_seg2(t_env *e, t_parser *p, t_ll **l_head, t_ol **o_head)
{
	if (ft_charfreq(p->gnl_line, '\t') < 2
			|| ft_charfreq(p->gnl_line, '\t') > 3)
		return (5);
	if (ft_charfreq(p->gnl_line, '\t') == 2)
	{
		if ((p->ret_p = twotab_verifications(e, p, o_head)) != 0)
			return (p->ret_p);
	}
	if (ft_charfreq(p->gnl_line, '\t') == 3)
	{
		if ((p->ret_p = shapevocab_checker(e, p)) != 0)
			return (p->ret_p);
		if ((p->ret_p = threetab_verify(e, p, l_head, o_head)) != 0)
			return (p->ret_p);
	}
	return (0);
}

int		verify_line(t_env *e, t_parser *p, t_ll **l_head, t_ol **o_head)
{
	p->split = ft_strsplit(p->gnl_line, ' ');
	p->str_count = ft_countstrings(p->split);
	if (p->specs == 1 && p->scene == 1 && p->objects == 0)
	{
		if ((p->ret_p = verify_line_seg1(e, p, l_head, o_head)) != 0)
			return (p->ret_p);
	}
	else if (p->specs == 1 && (p->scene != 1 || p->objects != 0))
		return (4);
	if (p->objects == 1 && p->specs == 2 && p->scene == 1)
	{
		if ((p->ret_p = verify_line_seg2(e, p, l_head, o_head)) != 0)
			return (p->ret_p);
	}
	else if (p->objects == 1 && (p->scene != 1 || p->specs != 2))
		return (4);
	ft_delsplit(p->split);
	return (0);
}

int		parser(t_env *e, t_parser *p, int fd)
{
	t_ll		*l_head;
	t_ol		*o_head;

	l_head = NULL;
	o_head = NULL;
	set_vocab(p);
	while ((p->ret.gnl = get_next_line(fd, &p->gnl_line)) > 0)
	{
		p->gnl_i++;
		if ((p->ret.glo = globals(p, p->gnl_line)) != 0)
			return (p->ret.glo);
		if ((p->objects == 1 || p->specs == 1) && !p->skip
				&& ((p->ret.tag = verify_line(e, p, &l_head, &o_head)) != 0))
			return (p->ret.tag);
		if (p->gnl_line)
			ft_strfree(p->gnl_line);
	}
	e->s_count = p->count.spheres + p->count.planes + p->count.cones
		+ p->count.cylinders;
	e->ll_lit = l_head;
	e->ll_obj = o_head;
	return (last_checks(p));
}
