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

#include "rtv1.h"

int		verifyobjecttags_openings_two(t_env *e, t_parser *p)
{
	if (ft_strcmp("cylinder", p->tmp) == 0)
	{
		p->p_obj.cyn += 1;
		e->cs = 3;
		if (ft_iseven(p->p_obj.cyn) == 0)
			return (32);
	}
	else if (ft_strcmp("plane", p->tmp) == 0)
	{
		p->p_obj.plane += 1;
		e->cs = 4;
		if (ft_iseven(p->p_obj.plane) == 0)
			return (33);
	}
	else
	{
		ft_strfree(p->tmp);
		return (20);
	}
	return (0);
}

int		verifyobjecttags_openings(t_env *e, t_parser *p, char **split, t_ol **o_head)
{
	if (add_link_obj(e, o_head) != 0)
		return (71);
	p->tmp = ft_strsub(split[0], 3, (ft_strlen(split[0]) - 3));
	if (ft_strcmp("sphere", p->tmp) == 0)
	{
		p->p_obj.sphere += 1;
		e->cs = 1;
		if (ft_iseven(p->p_obj.sphere) == 0)
			return (30);
	}
	else if (ft_strcmp("cone", p->tmp) == 0)
	{
		p->p_obj.cone += 1;
		e->cs = 2;
		if (ft_iseven(p->p_obj.cone) == 0)
			return (31);
	}
	else
	{
		if ((p->ret_p = verifyobjecttags_openings_two(e, p)) != 0)
			return (p->ret_p);
	}
	ft_strfree(p->tmp);
	return (0);
}

int		verifyobjecttags_closings_bks(t_parser *p, char *str)
{
	if (str[2] != '<' && str[3] != '/' && str[ft_strlen(str) - 1] != '>')
		return (21);
	p->close_obj_i = -1;
	p->good_obj_brack = 0;
	p->bad_obj_brack = 0;
	while (str[++p->close_obj_i])
	{
		if (str[p->close_obj_i] == '<' && str[p->close_obj_i + 1] == '/')
			p->good_obj_brack++;
		if (str[p->close_obj_i] == '>' && str[p->close_obj_i + 1] == '\0')
			p->good_obj_brack++;
		if (str[p->close_obj_i] == '<' && str[p->close_obj_i + 1] != '/')
			p->bad_obj_brack++;
		if (str[p->close_obj_i] == '>' && str[p->close_obj_i + 1] != '\0')
			p->bad_obj_brack++;
	}
	if (p->good_obj_brack != 2 || p->bad_obj_brack > 0)
		return (21);
	return (0);
}

int		checkforopenobjecttags(t_parser *p)
{
	if (ft_strcmp("sphere", p->tmp) == 0)
	{
		if (ft_iseven(p->p_obj.cone) == -1 || ft_iseven(p->p_obj.cyn) == -1
				|| ft_iseven(p->p_obj.plane) == -1)
			return (-1);
	}
	else if (ft_strcmp("cone", p->tmp) == 0)
	{
		if (ft_iseven(p->p_obj.sphere) == -1 || ft_iseven(p->p_obj.cyn) \
				== -1 || ft_iseven(p->p_obj.plane) == -1)
			return (-1);
	}
	else if (ft_strcmp("cylinder", p->tmp) == 0)
	{
		if (ft_iseven(p->p_obj.sphere) == -1 || ft_iseven(p->p_obj.cone) \
				== -1 || ft_iseven(p->p_obj.plane) == -1)
			return (-1);
	}
	else if (ft_strcmp("plane", p->tmp) == 0)
	{
		if (ft_iseven(p->p_obj.sphere) == -1 || ft_iseven(p->p_obj.cone) \
				== -1 || ft_iseven(p->p_obj.cyn) == -1)
			return (-1);
	}
	return (0);
}

int		twotab_verifications(t_env *e, t_parser *p, t_ol **o_head)
{
	if (p->str_count == 4)
	{
		if ((p->ret_p = verifyobjecttags_openings(e, p, p->split, o_head)) != 0)
			return (p->ret_p);
		if ((p->ret_p = two_angle_brackets(p)) != 2)
			return (9);
		if ((p->ret_p = extract_status(p)) != 0)
			return (p->ret_p);
	}
	else if (p->str_count == 1)
	{
		if ((p->ret_p = verifyobjecttags_closings_bks(p, p->split[0])) != 0)
			return (p->ret_p);
		if ((p->ret_p = verifyobjecttags_closings(e, p, p->split[0])) != 0)
			return (p->ret_p);
		count_shapes(p, p->split[0]);
	}
	else if (p->str_count != 1 || p->str_count != 4)
		return (13);
	return (0);
}
