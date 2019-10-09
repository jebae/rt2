/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_shapes_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:31:35 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/24 14:15:00 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	count_shapes(t_parser *p, char *split)
{
	p->tmp = ft_strsub(split, 4, (ft_strlen(split) - 5));
	if (ft_strcmp("sphere", p->tmp) == 0)
		p->count.spheres++;
	else if (ft_strcmp("cone", p->tmp) == 0)
		p->count.cones++;
	else if (ft_strcmp("cylinder", p->tmp) == 0)
		p->count.cylinders++;
	else if (ft_strcmp("plane", p->tmp) == 0)
		p->count.planes++;
	ft_strfree(p->tmp);
}

int		verifyobjecttags_closings_four(t_env *e, t_parser *p)
{
	if (ft_strcmp("plane", p->tmp) == 0)
	{
		open_close(&p->p_obj.plane);
		if (ft_iseven(p->p_obj.plane) != 0)
			return (34);
		if ((checkforopenobjecttags(p)) != 0)
			return (38);
		if ((p->ret_p = shapevocab_checker_partwo(e, p)) != 0)
			return (p->ret_p);
		reset_shape_atb(p);
	}
	else
		return (20);
	return (0);
}

int		verifyobjecttags_closings_three(t_env *e, t_parser *p)
{
	if (ft_strcmp("cylinder", p->tmp) == 0)
	{
		open_close(&p->p_obj.cyn);
		if (ft_iseven(p->p_obj.cyn) != 0)
			return (34);
		if ((checkforopenobjecttags(p)) != 0)
			return (38);
		if ((p->ret_p = shapevocab_checker_partwo(e, p)) != 0)
			return (p->ret_p);
		reset_shape_atb(p);
	}
	else
	{
		if ((p->ret_p = verifyobjecttags_closings_four(e, p)) != 0)
			return (p->ret_p);
	}
	return (0);
}

int		verifyobjecttags_closings_two(t_env *e, t_parser *p)
{
	if (ft_strcmp("cone", p->tmp) == 0)
	{
		open_close(&p->p_obj.cone);
		if (ft_iseven(p->p_obj.cone) != 0)
			return (34);
		if ((checkforopenobjecttags(p)) != 0)
			return (38);
		if ((p->ret_p = shapevocab_checker_partwo(e, p)) != 0)
			return (p->ret_p);
		reset_shape_atb(p);
	}
	else
	{
		if ((p->ret_p = verifyobjecttags_closings_three(e, p)) != 0)
			return (p->ret_p);
	}
	return (0);
}

int		verifyobjecttags_closings(t_env *e, t_parser *p, char *split)
{
	p->tmp = ft_strsub(split, 4, (ft_strlen(split) - 5));
	if (ft_strcmp("sphere", p->tmp) == 0)
	{
		open_close(&p->p_obj.sphere);
		if (ft_iseven(p->p_obj.sphere) != 0)
			return (34);
		if ((checkforopenobjecttags(p)) != 0)
			return (38);
		if ((p->ret_p = shapevocab_checker_partwo(e, p)) != 0)
			return (p->ret_p);
		reset_shape_atb(p);
	}
	else
	{
		if ((p->ret_p = verifyobjecttags_closings_two(e, p)) != 0)
			return (p->ret_p);
	}
	ft_strfree(p->tmp);
	return (0);
}
