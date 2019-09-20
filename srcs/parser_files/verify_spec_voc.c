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

void	reset_spec_atb(t_parser *p)
{
	p->ca_atb.position = 0;
	p->ca_atb.direction = 0;
	p->ca_atb.rotation = 0;
	p->ca_atb.translation = 0;
	p->a_atb.power = 0;
	p->a_atb.color = 0;
	p->l_atb.position = 0;
	p->l_atb.intensity = 0;
	p->l_atb.rotate = 0;
	p->l_atb.translate = 0;
}

int		verify_spec_atb_light(t_parser *p)
{
	if (ft_strcmp("position", p->s_tmp) == 0)
		p->l_atb.position++;
	else if (ft_strcmp("intensity", p->s_tmp) == 0)
		p->l_atb.intensity++;
	else if (ft_strcmp("rotate", p->s_tmp) == 0)
		p->l_atb.rotate++;
	else if (ft_strcmp("translate", p->s_tmp) == 0)
		p->l_atb.translate++;
	else
		return (68);
	return (0);
}

int		verify_spec_atb(t_parser *p) // /! string needs to be freed before returning error message /!
{
	p->s_tmp = ft_strsub(p->split[0], 4, (ft_strclen(p->split[0], '>') - 4));
	if (p->p_spec.cam == 1)
	{
		if (ft_strcmp("position", p->s_tmp) == 0)
			p->ca_atb.position++;
		else if (ft_strcmp("direction", p->s_tmp) == 0)
			p->ca_atb.direction++;
		else
			return (62);
	}
	if (p->p_spec.amb == 1)
	{
		if (ft_strcmp("specpower", p->s_tmp) == 0)
			p->a_atb.power++;
		else if (ft_strcmp("color", p->s_tmp) == 0)
			p->a_atb.color++;
		else
			return (65);
	}
	if (p->p_spec.light >= 1)
		if ((p->ret_p = verify_spec_atb_light(p)) != 0)
			return (p->ret_p);
	ft_strfree(p->s_tmp);
	return (0);
}

int		verify_spec_atb_partwo_light(t_parser *p)
{
	if (p->l_atb.position < 1 || p->l_atb.intensity < 1)
		return (66);
	if (p->l_atb.position > 1 || p->l_atb.intensity > 1)
		return (67);
	if (p->status == 1)
		if (p->l_atb.rotate != 0 || p->l_atb.translate != 0)
			return (69);
	if (p->status == 2)
		if (p->l_atb.rotate != 1 || p->l_atb.translate != 1)
			return (70);
	return (0);
}

int		verify_spec_atb_partwo(t_parser *p)
{
	if (p->p_spec.cam_cl == 1 && p->p_spec.amb_cl == 0 && p->p_spec.light == 0)
	{
		if (p->ca_atb.position < 1 || p->ca_atb.direction < 1)
			return (60);
		if (p->ca_atb.position > 1 || p->ca_atb.direction > 1)
			return (61);
	}
	else if (p->p_spec.cam_cl == 1 && p->p_spec.amb_cl == 1
		&& p->p_spec.light == 0)
	{
		if (p->a_atb.power < 1 || p->a_atb.color < 1)
			return (63);
		if (p->a_atb.power > 1 || p->a_atb.color > 1)
			return (64);
	}
	if (p->p_spec.cam_cl == 1 && p->p_spec.amb_cl == 1 && p->p_spec.light >= 1)
		if ((p->ret_p = verify_spec_atb_partwo_light(p)) != 0)
			return (p->ret_p);
	return (0);
}
