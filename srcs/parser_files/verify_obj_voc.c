/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_six.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:23:02 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/03 12:52:23 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		shapevocab_checker_shpere(t_env *e)
{
	if (ft_strcmp("radius", e->p.s_tmp) == 0)
		e->p.s_atb.radius++;
	else if (ft_strcmp("center", e->p.s_tmp) == 0)
		e->p.s_atb.center++;
	else if (ft_strcmp("diffusion", e->p.s_tmp) == 0)
		e->p.s_atb.diffusion++;
	else if (ft_strcmp("reflection", e->p.s_tmp) == 0)
		e->p.s_atb.reflection++;
	else if (ft_strcmp("specvalue", e->p.s_tmp) == 0)
		e->p.s_atb.specvalue++;
	else if (ft_strcmp("specpower", e->p.s_tmp) == 0)
		e->p.s_atb.specpower++;
	else if (ft_strcmp("rotate", e->p.s_tmp) == 0)
		e->p.s_atb.rotate++;
	else if (ft_strcmp("translate", e->p.s_tmp) == 0)
		e->p.s_atb.translate++;
	else
		return (55);
	return (0);
}

int		shapevocab_checker_cone(t_env *e)
{
	if (ft_strcmp("radius", e->p.s_tmp) == 0)
		e->p.c_atb.radius++;
	else if (ft_strcmp("center", e->p.s_tmp) == 0)
		e->p.c_atb.center++;
	else if (ft_strcmp("diffusion", e->p.s_tmp) == 0)
		e->p.c_atb.diffusion++;
	else if (ft_strcmp("reflection", e->p.s_tmp) == 0)
		e->p.c_atb.reflection++;
	else if (ft_strcmp("specvalue", e->p.s_tmp) == 0)
		e->p.c_atb.specvalue++;
	else if (ft_strcmp("specpower", e->p.s_tmp) == 0)
		e->p.c_atb.specpower++;
	else if (ft_strcmp("angle", e->p.s_tmp) == 0)
		e->p.c_atb.angle++;
	else if (ft_strcmp("rotate", e->p.s_tmp) == 0)
		e->p.c_atb.rotate++;
	else if (ft_strcmp("translate", e->p.s_tmp) == 0)
		e->p.c_atb.translate++;
	else if (ft_strcmp("direction", e->p.s_tmp) == 0)
		e->p.c_atb.direction++;
	else
		return (56);
	return (0);
}

int		shapevocab_checker_cyn(t_env *e)
{
	if (ft_strcmp("radius", e->p.s_tmp) == 0)
		e->p.y_atb.radius++;
	else if (ft_strcmp("center", e->p.s_tmp) == 0)
		e->p.y_atb.center++;
	else if (ft_strcmp("diffusion", e->p.s_tmp) == 0)
		e->p.y_atb.diffusion++;
	else if (ft_strcmp("reflection", e->p.s_tmp) == 0)
		e->p.y_atb.reflection++;
	else if (ft_strcmp("specvalue", e->p.s_tmp) == 0)
		e->p.y_atb.specvalue++;
	else if (ft_strcmp("specpower", e->p.s_tmp) == 0)
		e->p.y_atb.specpower++;
	else if (ft_strcmp("angle", e->p.s_tmp) == 0)
		e->p.y_atb.angle++;
	else if (ft_strcmp("rotate", e->p.s_tmp) == 0)
		e->p.y_atb.rotate++;
	else if (ft_strcmp("translate", e->p.s_tmp) == 0)
		e->p.y_atb.translate++;
	else if (ft_strcmp("direction", e->p.s_tmp) == 0)
		e->p.y_atb.direction++;
	else
		return (57);
	return (0);
}

int		shapevocab_checker_plane(t_env *e)
{
	if (ft_strcmp("normal", e->p.s_tmp) == 0)
		e->p.p_atb.normal++;
	else if (ft_strcmp("d", e->p.s_tmp) == 0)
		e->p.p_atb.d++;
	else if (ft_strcmp("diffusion", e->p.s_tmp) == 0)
		e->p.p_atb.diffusion++;
	else if (ft_strcmp("reflection", e->p.s_tmp) == 0)
		e->p.p_atb.reflection++;
	else if (ft_strcmp("specvalue", e->p.s_tmp) == 0)
		e->p.p_atb.specvalue++;
	else if (ft_strcmp("specpower", e->p.s_tmp) == 0)
		e->p.p_atb.specpower++;
	else if (ft_strcmp("rotate", e->p.s_tmp) == 0)
		e->p.p_atb.rotate++;
	else if (ft_strcmp("translate", e->p.s_tmp) == 0)
		e->p.p_atb.translate++;
	else
		return (58);
	return (0);
}

int		shapevocab_checker(t_env *e) // /! string needs to be freed before returning error message /!
{
	int	ret;

	ret = 0;
	e->p.s_tmp = ft_strsub(e->p.split[0], 4,
		(ft_strclen(e->p.split[0], '>') - 4));
	if (e->cs == 1)
		if ((ret = shapevocab_checker_shpere(e)) != 0)
			return (ret);
	if (e->cs == 2)
		if ((ret = shapevocab_checker_cone(e)) != 0)
			return (ret);
	if (e->cs == 3)
		if ((ret = shapevocab_checker_cyn(e)) != 0)
			return (ret);
	if (e->cs == 4)
		if ((ret = shapevocab_checker_plane(e)) != 0)
			return (ret);
	free(e->p.s_tmp);
	e->p.s_tmp = NULL;
	return (0);
}
