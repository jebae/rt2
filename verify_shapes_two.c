/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_shapes_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:31:35 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/10 17:49:13 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

void	count_shapes(t_env *e, char *split)
{
	e->p.tmp = ft_strsub(split, 4, (ft_strlen(split) - 5));
	if (ft_strcmp("sphere", e->p.tmp) == 0)
		e->p.count.spheres++;
	else if (ft_strcmp("cone", e->p.tmp) == 0)
		e->p.count.cones++;
	else if (ft_strcmp("cylinder", e->p.tmp) == 0)
		e->p.count.cylinders++;
	else if (ft_strcmp("plane", e->p.tmp) == 0)
		e->p.count.planes++;
	free(e->p.tmp);
	e->p.tmp = NULL;
}

int		verifyobjecttags_closings_four(t_env *e)
{
	if (ft_strcmp("plane", e->p.tmp) == 0)
	{
		open_close(&e->p.p_obj.plane);
		if (ft_iseven(e->p.p_obj.plane) != 0)
			return (34);
		if ((checkforopenobjecttags(e)) != 0)
			return (38);
		if ((e->p.ret_p = shapevocab_checker_partwo(e)) != 0)
			return (e->p.ret_p);
		reset_shape_atb(e);
	}
	else
		return (20);
	return (0);
}

int		verifyobjecttags_closings_three(t_env *e)
{
	if (ft_strcmp("cylinder", e->p.tmp) == 0)
	{
		open_close(&e->p.p_obj.cyn);
		if (ft_iseven(e->p.p_obj.cyn) != 0)
			return (34);
		if ((checkforopenobjecttags(e)) != 0)
			return (38);
		if ((e->p.ret_p = shapevocab_checker_partwo(e)) != 0)
			return (e->p.ret_p);
		reset_shape_atb(e);
	}
	else
	{
		if ((e->p.ret_p = verifyobjecttags_closings_four(e)) != 0)
			return (e->p.ret_p);
	}
	return (0);
}

int		verifyobjecttags_closings_two(t_env *e)
{
	if (ft_strcmp("cone", e->p.tmp) == 0)
	{
		open_close(&e->p.p_obj.cone);
		if (ft_iseven(e->p.p_obj.cone) != 0)
			return (34);
		if ((checkforopenobjecttags(e)) != 0)
			return (38);
		if ((e->p.ret_p = shapevocab_checker_partwo(e)) != 0)
			return (e->p.ret_p);
		reset_shape_atb(e);
	}
	else
	{
		if ((e->p.ret_p = verifyobjecttags_closings_three(e)) != 0)
			return (e->p.ret_p);
	}
	return (0);
}

int		verifyobjecttags_closings(t_env *e, char *split)
{
	e->p.tmp = ft_strsub(split, 4, (ft_strlen(split) - 5));
	if (ft_strcmp("sphere", e->p.tmp) == 0)
	{
		open_close(&e->p.p_obj.sphere);
		if (ft_iseven(e->p.p_obj.sphere) != 0)
			return (34);
		if ((checkforopenobjecttags(e)) != 0)
			return (38);
		if ((e->p.ret_p = shapevocab_checker_partwo(e)) != 0)
			return (e->p.ret_p);
		reset_shape_atb(e);
	}
	else
	{
		if ((e->p.ret_p = verifyobjecttags_closings_two(e)) != 0)
			return (e->p.ret_p);
	}
	return (0);
}
