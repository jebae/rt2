/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:01:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/30 14:43:03 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

int		threetab_verifications(t_env *e, t_ll **l_head, t_ol **o_head)
{
	if (e->str_count == 3)
	{
		if ((e->p.ret_p = verifyanglebrackets_three(e)) == -1)
			return (17);
		if ((e->p.ret_p = verifyvocab_three(e)) != 0)
			return (e->p.ret_p);
		if ((e->p.ret_p = verifyargs_three(e, l_head, o_head)) != 0) // store data here
			return (e->p.ret_p);
	}
	else if (e->str_count == 1)
	{
		if ((e->p.ret_p = verifyanglebrackets_one(e)) == -1)
			return (17);
		if ((e->p.ret_p = verifyvocab_one(e)) != 0)
			return (e->p.ret_p);
		if ((e->p.ret_p = verifyargs_one(e, l_head, o_head)) != 0) // store data here
			return (e->p.ret_p);
	}
	else
		return (17);
	return (0);
}

int		verify_line_seg_one(t_env *e, t_ll **l_head, t_ol **o_head)
{
	if (ft_charfreq(e->p.gnl_line, '\t') < 2 || ft_charfreq(e->p.gnl_line, '\t') > 3)
		return (5);
	if (ft_charfreq(e->p.gnl_line, '\t') == 2)
		if ((e->p.ret_p = two_tabs_specs(e, l_head)) != 0)
			return (e->p.ret_p);
	if (ft_charfreq(e->p.gnl_line, '\t') == 3)
	{
		if ((e->p.ret_p = verify_spec_atb(e)) != 0)
			return (e->p.ret_p);
		if ((e->p.ret_p = threetab_verifications(e, l_head, o_head)) != 0)  // will need to send main env *e here !
			return (e->p.ret_p);
	}
	return (0);
}

int		verify_line_seg_two(t_env *e, t_ll **l_head, t_ol **o_head)
{
	if (ft_charfreq(e->p.gnl_line, '\t') < 2 || ft_charfreq(e->p.gnl_line, '\t') > 3)
		return (5);
	if (ft_charfreq(e->p.gnl_line, '\t') == 2)
	{
		if ((e->p.ret_p = twotab_verifications(e, o_head)) != 0)
			return (e->p.ret_p);
	}
	if (ft_charfreq(e->p.gnl_line, '\t') == 3)
	{
		if ((e->p.ret_p = shapevocab_checker(e)) != 0)
			return (e->p.ret_p);
		if ((e->p.ret_p = threetab_verifications(e, l_head, o_head)) != 0) // will need to send main env *e here !
			return (e->p.ret_p);
	}
	return (0);
}

int		verify_line(t_env *e, t_ll **l_head, t_ol **o_head)
{
	e->p.split = ft_strsplit(e->p.gnl_line, ' ');
	e->str_count = ft_countstrings(e->p.split);
	if (e->p.specs == 1 && e->p.scene == 1 && e->p.objects == 0)
	{
		if ((e->p.ret_p = verify_line_seg_one(e, l_head, o_head)) != 0)
			return (e->p.ret_p);
	}
	else if (e->p.specs == 1 && (e->p.scene != 1 || e->p.objects != 0))
		return (4);
	if (e->p.objects == 1 && e->p.specs == 2 && e->p.scene == 1)
	{
		if ((e->p.ret_p = verify_line_seg_two(e, l_head, o_head)) != 0)
			return (e->p.ret_p);
	}
	else if (e->p.objects == 1 && (e->p.scene != 1 || e->p.specs != 2))
		return (4);
	ft_delsplit(e->p.split);
	return (0);
}

int		last_checks(t_env *e)
{
	if (e->p.objects != 2 || e->p.specs != 2)
		return (4);
	if (e->p.p_spec.cam_cl != 1 || e->p.p_spec.amb_cl != 1)
		return (26);
	if (e->p.scene != 2)
		return (6);
	if ((e->p.count.spheres + e->p.count.planes + e->p.count.cones + e->p.count.cylinders) == 0)
		return(59);
	if ((ft_iseven(e->p.p_spec.light)) == -1)
		return(27);
	if ((ft_iseven(e->p.p_obj.sphere)) == -1)
		return(34);
	if ((ft_iseven(e->p.p_obj.cone)) == -1)
		return(34);
	if ((ft_iseven(e->p.p_obj.cyn)) == -1)
		return(34);
	if ((ft_iseven(e->p.p_obj.plane)) == -1)
		return(34);
	if (e->p.p_spec.cam != 2 || e->p.p_spec.amb != 2)
		return (37);
	if (e->p.ret.gnl == -1)
		return (1);
	printf("VALID!\n");
	return (0);
}

int		parser(t_env *e, int fd)
{
	t_ll	*l_head;
	t_ol	*o_head;
	// t_parser		*p; // parser struct ! TO send parser everywhere ! --> (&p)

	l_head = NULL;
	o_head = NULL;
	set_vocab(e);
	while ((e->p.ret.gnl = get_next_line(fd, &e->p.gnl_line)) > 0)
	{

		e->p.gnl_i++;
		if ((e->p.ret.glo = globals(e, e->p.gnl_line)) != 0)
			return (e->p.ret.glo);
		if ((e->p.objects == 1 || e->p.specs == 1) && !e->p.skip 
			&& ((e->p.ret.tag = verify_line(e, &l_head, &o_head)) != 0))
			return (e->p.ret.tag);
		if (e->p.gnl_line)
		{
			free(e->p.gnl_line);
			e->p.gnl_line = NULL;
		}
	}
	e->s_count = e->p.count.spheres + e->p.count.planes + e->p.count.cones
		+ e->p.count.cylinders;
	e->ll_lit = l_head;
	e->ll_obj = o_head;
	return (last_checks(e));
}