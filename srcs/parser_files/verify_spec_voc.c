/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_eight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:29:56 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/05 15:16:15 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	reset_spec_atb(t_env *e)
{
	e->p.ca_atb.position = 0;
	e->p.ca_atb.direction = 0;
	e->p.ca_atb.rotation = 0;
	e->p.ca_atb.translation = 0;
	e->p.a_atb.power = 0;
	e->p.a_atb.color = 0;
	e->p.l_atb.position = 0;
	e->p.l_atb.intensity = 0;
	e->p.l_atb.rotate = 0;
	e->p.l_atb.translate = 0;
}

int		verify_spec_atb_light(t_env *e)
{
	if (ft_strcmp("position", e->p.s_tmp) == 0)
		e->p.l_atb.position++;
	else if (ft_strcmp("intensity", e->p.s_tmp) == 0)
		e->p.l_atb.intensity++;
	else if (ft_strcmp("rotate", e->p.s_tmp) == 0)
		e->p.l_atb.rotate++;
	else if (ft_strcmp("translate", e->p.s_tmp) == 0)
		e->p.l_atb.translate++;
	else
		return (68);
	return (0);
}

int		verify_spec_atb(t_env *e) // /! string needs to be freed before returning error message /!
{
	e->p.s_tmp = ft_strsub(e->p.split[0], 4, (ft_strclen(e->p.split[0], '>') - 4));
	if (e->p.p_spec.cam == 1)
	{
		if (ft_strcmp("position", e->p.s_tmp) == 0)
			e->p.ca_atb.position++;
		else if (ft_strcmp("direction", e->p.s_tmp) == 0)
			e->p.ca_atb.direction++;
		else
			return (62);
	}
	if (e->p.p_spec.amb == 1)
	{
		if (ft_strcmp("specpower", e->p.s_tmp) == 0)
			e->p.a_atb.power++;
		else if (ft_strcmp("color", e->p.s_tmp) == 0)
			e->p.a_atb.color++;
		else
			return (65);
	}
	if (e->p.p_spec.light >= 1)
		if ((e->p.ret_p = verify_spec_atb_light(e)) != 0)
			return (e->p.ret_p);
	free(e->p.s_tmp);
	e->p.s_tmp = NULL;
	return (0);
}

int		verify_spec_atb_partwo_light(t_env *e)
{
	if (e->p.l_atb.position < 1 || e->p.l_atb.intensity < 1)
		return (66);
	if (e->p.l_atb.position > 1 || e->p.l_atb.intensity > 1)
		return (67);
	if (e->p.status == 1)
		if (e->p.l_atb.rotate != 0 || e->p.l_atb.translate != 0)
			return (69);
	if (e->p.status == 2)
		if (e->p.l_atb.rotate != 1 || e->p.l_atb.translate != 1)
			return (70);
	return (0);
}

int		verify_spec_atb_partwo(t_env *e)
{
	if (e->p.p_spec.cam_cl == 1 && e->p.p_spec.amb_cl == 0 && e->p.p_spec.light == 0)
	{
		if (e->p.ca_atb.position < 1 || e->p.ca_atb.direction < 1)
			return (60);
		if (e->p.ca_atb.position > 1 || e->p.ca_atb.direction > 1)
			return (61);
	}
	else if (e->p.p_spec.cam_cl == 1 && e->p.p_spec.amb_cl == 1
		&& e->p.p_spec.light == 0)
	{
		if (e->p.a_atb.power < 1 || e->p.a_atb.color < 1)
			return (63);
		if (e->p.a_atb.power > 1 || e->p.a_atb.color > 1)
			return (64);
	}
	if (e->p.p_spec.cam_cl == 1 && e->p.p_spec.amb_cl == 1 && e->p.p_spec.light >= 1)
		if ((e->p.ret_p = verify_spec_atb_partwo_light(e)) != 0)
			return (e->p.ret_p);
	return (0);
}
