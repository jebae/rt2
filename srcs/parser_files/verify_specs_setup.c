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

int		verify_light(t_env *e, t_ll **l_head)
{
	int		ret;

	ret = 0;
	e->p.p_spec.light += 1;
	// add add_link_light here !!! 
	if ((add_link_light(e, l_head)) == -1)
		return (71);
	if (ft_iseven(e->p.p_spec.light) == 0)
		return (12);
	if ((ret = extract_status(e)) != 0)
		return (ret);
	return (ret);
}

int		verifyspectags_openings(t_env *e, t_ll **l_head)
{
	e->p.tmp = ft_strsub(e->p.split[0], 2, (ft_strlen(e->p.split[0]) - 2));
	if (ft_strcmp("<cam>", e->p.tmp) == 0)
	{
		if (e->p.p_spec.amb_cl > 0)
			return (28);
		e->p.p_spec.cam += 1;
	}
	else if (ft_strcmp("<amb>", e->p.tmp) == 0)
	{
		if (e->p.p_spec.cam_cl != 1)
			return (28);
		e->p.p_spec.amb += 1;
	}
	else if (ft_strcmp("<light", e->p.tmp) == 0)
	{
		if ((e->p.ret_p = verify_light(e, l_head)) != 0)
			return (e->p.ret_p);
	}
	else
		return (8);
	free(e->p.tmp);
	e->p.tmp = NULL;
	return (0);
}

int		verifyspectags_closing_light(t_env *e)
{
	if ((e->p.ret_p = ft_strcmp("\t\t</light>", e->p.split[0])) != 0)
		return (12);
	open_close(&e->p.p_spec.light);
	if (ft_iseven(e->p.p_spec.light) == -1)
		return (29);
	if ((e->p.ret_p = verify_spec_atb_partwo(e)) != 0)
		return (e->p.ret_p);
	reset_spec_atb(e);

	return (0);
}

int		verifyspectags_closing(t_env *e)
{
	if (e->p.p_spec.cam == 1)
	{
		if ((e->p.ret_p = ft_strcmp("\t\t</cam>", e->p.split[0]) != 0))
			return (10);
		open_close(&e->p.p_spec.cam);
		e->p.p_spec.cam_cl++;
		if ((e->p.ret_p = verify_spec_atb_partwo(e)) != 0)
			return (e->p.ret_p);
		reset_spec_atb(e);
	}
	else if (e->p.p_spec.amb == 1)
	{
		if ((e->p.ret_p = ft_strcmp("\t\t</amb>", e->p.split[0])) != 0)
			return (11);
		open_close(&e->p.p_spec.amb);
		e->p.p_spec.amb_cl++;
		if ((e->p.ret_p = verify_spec_atb_partwo(e)) != 0)
			return (e->p.ret_p);
		reset_spec_atb(e);
	}
	else if (e->p.p_spec.light >= 1)
		if ((e->p.ret_p = verifyspectags_closing_light(e)) != 0)
			return (e->p.ret_p);
	return (0);
}

int		two_tabs_specs(t_env *e, t_ll **l_head)
{
	e->p.ret_p = 0; // need this ?
	if ((e->p.ret_p = two_angle_brackets(e)) != 2)
		return (9);
	if (ft_strclen(e->p.gnl_line, '/') == 0)
	{
		if ((e->p.ret_p = verifyspectags_openings(e, l_head)) != 0)
			return (e->p.ret_p);
	}
	else if (ft_strclen(e->p.gnl_line, '/') > 0)
	{
		if ((e->p.ret_p = verifyspectags_closing(e)) != 0)
			return (e->p.ret_p);
	}
	else if (e->str_count != 1 || e->str_count != 4)
		return (13);
	return (0);
}
