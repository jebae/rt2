/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_obj_voc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:23:02 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/24 14:02:24 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		shapevocab_checker_shpere(t_parser *p)
{
	if (ft_strcmp("radius", p->s_tmp) == 0)
		p->s_atb.radius++;
	else if (ft_strcmp("center", p->s_tmp) == 0)
		p->s_atb.center++;
	else if (ft_strcmp("diffusion", p->s_tmp) == 0)
		p->s_atb.diffusion++;
	else if (ft_strcmp("reflection", p->s_tmp) == 0)
		p->s_atb.reflection++;
	else if (ft_strcmp("specvalue", p->s_tmp) == 0)
		p->s_atb.specvalue++;
	else if (ft_strcmp("specpower", p->s_tmp) == 0)
		p->s_atb.specpower++;
	else if (ft_strcmp("rotate", p->s_tmp) == 0)
		p->s_atb.rotate++;
	else if (ft_strcmp("translate", p->s_tmp) == 0)
		p->s_atb.translate++;
	else
		return (55);
	return (0);
}

int		shapevocab_checker_cone(t_parser *p)
{
	if (ft_strcmp("radius", p->s_tmp) == 0)
		p->c_atb.radius++;
	else if (ft_strcmp("center", p->s_tmp) == 0)
		p->c_atb.center++;
	else if (ft_strcmp("diffusion", p->s_tmp) == 0)
		p->c_atb.diffusion++;
	else if (ft_strcmp("reflection", p->s_tmp) == 0)
		p->c_atb.reflection++;
	else if (ft_strcmp("specvalue", p->s_tmp) == 0)
		p->c_atb.specvalue++;
	else if (ft_strcmp("specpower", p->s_tmp) == 0)
		p->c_atb.specpower++;
	else if (ft_strcmp("angle", p->s_tmp) == 0)
		p->c_atb.angle++;
	else if (ft_strcmp("rotate", p->s_tmp) == 0)
		p->c_atb.rotate++;
	else if (ft_strcmp("translate", p->s_tmp) == 0)
		p->c_atb.translate++;
	else if (ft_strcmp("direction", p->s_tmp) == 0)
		p->c_atb.direction++;
	else
		return (56);
	return (0);
}

int		shapevocab_checker_cyn(t_parser *p)
{
	if (ft_strcmp("radius", p->s_tmp) == 0)
		p->y_atb.radius++;
	else if (ft_strcmp("center", p->s_tmp) == 0)
		p->y_atb.center++;
	else if (ft_strcmp("diffusion", p->s_tmp) == 0)
		p->y_atb.diffusion++;
	else if (ft_strcmp("reflection", p->s_tmp) == 0)
		p->y_atb.reflection++;
	else if (ft_strcmp("specvalue", p->s_tmp) == 0)
		p->y_atb.specvalue++;
	else if (ft_strcmp("specpower", p->s_tmp) == 0)
		p->y_atb.specpower++;
	else if (ft_strcmp("angle", p->s_tmp) == 0)
		p->y_atb.angle++;
	else if (ft_strcmp("rotate", p->s_tmp) == 0)
		p->y_atb.rotate++;
	else if (ft_strcmp("translate", p->s_tmp) == 0)
		p->y_atb.translate++;
	else if (ft_strcmp("direction", p->s_tmp) == 0)
		p->y_atb.direction++;
	else
		return (57);
	return (0);
}

int		shapevocab_checker_plane(t_parser *p)
{
	if (ft_strcmp("normal", p->s_tmp) == 0)
		p->p_atb.normal++;
	else if (ft_strcmp("d", p->s_tmp) == 0)
		p->p_atb.d++;
	else if (ft_strcmp("diffusion", p->s_tmp) == 0)
		p->p_atb.diffusion++;
	else if (ft_strcmp("reflection", p->s_tmp) == 0)
		p->p_atb.reflection++;
	else if (ft_strcmp("specvalue", p->s_tmp) == 0)
		p->p_atb.specvalue++;
	else if (ft_strcmp("specpower", p->s_tmp) == 0)
		p->p_atb.specpower++;
	else if (ft_strcmp("rotate", p->s_tmp) == 0)
		p->p_atb.rotate++;
	else if (ft_strcmp("translate", p->s_tmp) == 0)
		p->p_atb.translate++;
	else
		return (58);
	return (0);
}

int		shapevocab_checker(t_env *e, t_parser *p)
{
	int	ret;

	ret = 0;
	p->s_tmp = ft_strsub(p->split[0], 4, (ft_strclen(p->split[0], '>') - 4));
	if (e->cs == 1)
		if ((ret = shapevocab_checker_shpere(p)) != 0)
			return (ret);
	if (e->cs == 2)
		if ((ret = shapevocab_checker_cone(p)) != 0)
			return (ret);
	if (e->cs == 3)
		if ((ret = shapevocab_checker_cyn(p)) != 0)
			return (ret);
	if (e->cs == 4)
		if ((ret = shapevocab_checker_plane(p)) != 0)
			return (ret);
	ft_strfree(p->s_tmp);
	return (0);
}
