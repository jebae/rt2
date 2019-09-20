/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_specs_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:04:48 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/05 15:10:17 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		verify_light(t_env *e, t_ll **l_head, t_parser *p)
{
	int		ret;

	ret = 0;
	p->p_spec.light += 1;
	if ((add_link_light(e, l_head)) == -1)
		return (71);
	if (ft_iseven(p->p_spec.light) == 0)
		return (12);
	if ((ret = extract_status(p)) != 0)
		return (ret);
	return (ret);
}

int		verifyspectags_openings(t_env *e, t_ll **l_head, t_parser *p)
{
	p->tmp = ft_strsub(p->split[0], 2, (ft_strlen(p->split[0]) - 2));
	if (ft_strcmp("<cam>", p->tmp) == 0)
	{
		if (p->p_spec.amb_cl > 0)
			return (28);
		p->p_spec.cam += 1;
	}
	else if (ft_strcmp("<amb>", p->tmp) == 0)
	{
		if (p->p_spec.cam_cl != 1)
			return (28);
		p->p_spec.amb += 1;
	}
	else if (ft_strcmp("<light", p->tmp) == 0)
	{
		if ((p->ret_p = verify_light(e, l_head, p)) != 0)
			return (p->ret_p);
	}
	else
		return (8);
	ft_strfree(p->tmp);
	return (0);
}

int		verifyspectags_closing_light(t_env *e, t_parser *p)
{
	(void)e;
	if ((p->ret_p = ft_strcmp("\t\t</light>", p->split[0])) != 0)
		return (12);
	open_close(&p->p_spec.light);
	if (ft_iseven(p->p_spec.light) == -1)
		return (29);
	if ((p->ret_p = verify_spec_atb_partwo(p)) != 0)
		return (p->ret_p);
	reset_spec_atb(p);
	return (0);
}

int		verifyspectags_closing(t_env *e, t_parser *p)
{
	if (p->p_spec.cam == 1)
	{
		if ((p->ret_p = ft_strcmp("\t\t</cam>", p->split[0]) != 0))
			return (10);
		open_close(&p->p_spec.cam);
		p->p_spec.cam_cl++;
		if ((p->ret_p = verify_spec_atb_partwo(p)) != 0)
			return (p->ret_p);
		reset_spec_atb(p);
	}
	else if (p->p_spec.amb == 1)
	{
		if ((p->ret_p = ft_strcmp("\t\t</amb>", p->split[0])) != 0)
			return (11);
		open_close(&p->p_spec.amb);
		p->p_spec.amb_cl++;
		if ((p->ret_p = verify_spec_atb_partwo(p)) != 0)
			return (p->ret_p);
		reset_spec_atb(p);
	}
	else if (p->p_spec.light >= 1)
		if ((p->ret_p = verifyspectags_closing_light(e, p)) != 0)
			return (p->ret_p);
	return (0);
}

int		two_tabs_specs(t_env *e, t_parser *p, t_ll **l_head)
{
	p->ret_p = 0;
	if ((p->ret_p = two_angle_brackets(p)) != 2)
		return (9);
	if (ft_strclen(p->gnl_line, '/') == 0)
	{
		if ((p->ret_p = verifyspectags_openings(e, l_head, p)) != 0)
			return (p->ret_p);
	}
	else if (ft_strclen(p->gnl_line, '/') > 0)
	{
		if ((p->ret_p = verifyspectags_closing(e, p)) != 0)
			return (p->ret_p);
	}
	else if (p->str_count != 1 || p->str_count != 4)
		return (13);
	return (0);
}
