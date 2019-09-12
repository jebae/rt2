/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:45:36 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/10 17:41:24 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

int		verifyobjecttags_openings_two(t_env *e)
{
	if (ft_strcmp("cylinder", e->p.tmp) == 0)
	{
		e->p.p_obj.cyn += 1;
		e->cs = 3;
		if (ft_iseven(e->p.p_obj.cyn) == 0)
			return (32);
	}
	else if (ft_strcmp("plane", e->p.tmp) == 0)
	{
		e->p.p_obj.plane += 1;
		e->cs = 4;
		if (ft_iseven(e->p.p_obj.plane) == 0)
			return (33);
	}
	else
	{
		ft_strfree(e->p.tmp);
		return (20);
	}
	return (0);
}

int		verifyobjecttags_openings(t_env *e, char **split, t_ol **o_head)
{
	if (add_link_obj(e, o_head) != 0)
		return (71);
	e->p.tmp = ft_strsub(split[0], 3, (ft_strlen(split[0]) - 3));
	if (ft_strcmp("sphere", e->p.tmp) == 0)
	{
		e->p.p_obj.sphere += 1;
		e->cs = 1;
		if (ft_iseven(e->p.p_obj.sphere) == 0)
			return (30);
	}
	else if (ft_strcmp("cone", e->p.tmp) == 0)
	{
		e->p.p_obj.cone += 1;
		e->cs = 2;
		if (ft_iseven(e->p.p_obj.cone) == 0)
			return (31);
	}
	else
	{
		if ((e->p.ret_p = verifyobjecttags_openings_two(e)) != 0)
			return (e->p.ret_p);
	}
	ft_strfree(e->p.tmp);
	return (0);
}

int		verifyobjecttags_closings_bks(t_env *e, char *str)
{
	if (str[2] != '<' && str[3] != '/' && str[ft_strlen(str) - 1] != '>')
		return (21);
	e->p.close_obj_i = -1;
	e->p.good_obj_brack = 0;
	e->p.bad_obj_brack = 0;
	while (str[++e->p.close_obj_i])
	{
		if (str[e->p.close_obj_i] == '<' && str[e->p.close_obj_i + 1] == '/')
			e->p.good_obj_brack++;
		if (str[e->p.close_obj_i] == '>' && str[e->p.close_obj_i + 1] == '\0')
			e->p.good_obj_brack++;
		if (str[e->p.close_obj_i] == '<' && str[e->p.close_obj_i + 1] != '/')
			e->p.bad_obj_brack++;
		if (str[e->p.close_obj_i] == '>' && str[e->p.close_obj_i + 1] != '\0')
			e->p.bad_obj_brack++;
	}
	if (e->p.good_obj_brack != 2 || e->p.bad_obj_brack > 0)
		return (21);
	return (0);
}

int		checkforopenobjecttags(t_env *e)
{
	if (ft_strcmp("sphere", e->p.tmp) == 0)
	{
		if (ft_iseven(e->p.p_obj.cone) == -1 || ft_iseven(e->p.p_obj.cyn) == -1
				|| ft_iseven(e->p.p_obj.plane) == -1)
			return (-1);
	}
	else if (ft_strcmp("cone", e->p.tmp) == 0)
	{
		if (ft_iseven(e->p.p_obj.sphere) == -1 || ft_iseven(e->p.p_obj.cyn) \
				== -1 || ft_iseven(e->p.p_obj.plane) == -1)
			return (-1);
	}
	else if (ft_strcmp("cylinder", e->p.tmp) == 0)
	{
		if (ft_iseven(e->p.p_obj.sphere) == -1 || ft_iseven(e->p.p_obj.cone) \
				== -1 || ft_iseven(e->p.p_obj.plane) == -1)
			return (-1);
	}
	else if (ft_strcmp("plane", e->p.tmp) == 0)
	{
		if (ft_iseven(e->p.p_obj.sphere) == -1 || ft_iseven(e->p.p_obj.cone) \
				== -1 || ft_iseven(e->p.p_obj.cyn) == -1)
			return (-1);
	}
	return (0);
}

int		twotab_verifications(t_env *e, t_ol **o_head)
{
	if (e->str_count == 4)
	{
		if ((e->p.ret_p = verifyobjecttags_openings(e, e->p.split, o_head)) != 0)
			return (e->p.ret_p);
		if ((e->p.ret_p = two_angle_brackets(e)) != 2)
			return (9);
		if ((e->p.ret_p = extract_status(e)) != 0)
			return (e->p.ret_p);
	}
	else if (e->str_count == 1)
	{
		if ((e->p.ret_p = verifyobjecttags_closings_bks(e, e->p.split[0])) != 0)
			return (e->p.ret_p);
		if ((e->p.ret_p = verifyobjecttags_closings(e, e->p.split[0])) != 0)
			return (e->p.ret_p);
		count_shapes(e, e->p.split[0]);
	}
	else if (e->str_count != 1 || e->str_count != 4)
		return (13);
	return (0);
}
