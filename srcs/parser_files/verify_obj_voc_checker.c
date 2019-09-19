/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_seven.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:38:23 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/03 12:46:19 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		shapevocab_checker_partwo_sphere(t_env *e)
{
	if (e->p.s_atb.radius < 1 || e->p.s_atb.center < 1 || e->p.s_atb.diffusion < 1
			|| e->p.s_atb.reflection < 1 || e->p.s_atb.specvalue < 1
			|| e->p.s_atb.specpower < 1)
		return (39);
	if (e->p.s_atb.radius > 1 || e->p.s_atb.center > 1 || e->p.s_atb.diffusion > 1
			|| e->p.s_atb.reflection > 1 || e->p.s_atb.specvalue > 1
			|| e->p.s_atb.specpower > 1)
		return (40);
	if (e->p.status == 1)
		if (e->p.s_atb.rotate != 0 || e->p.s_atb.translate != 0)
			return (41);
	if (e->p.status == 2)
		if (e->p.s_atb.rotate != 1 || e->p.s_atb.translate != 1)
			return (42);
	return (0);
}

int		shapevocab_checker_partwo_cone(t_env *e)
{
	if (e->p.c_atb.radius < 1 || e->p.c_atb.center < 1 || e->p.c_atb.diffusion < 1
			|| e->p.c_atb.direction < 1 || e->p.c_atb.reflection < 1
			|| e->p.c_atb.specvalue < 1 || e->p.c_atb.specpower < 1
			|| e->p.c_atb.angle < 1)
		return (43);
	if (e->p.c_atb.radius > 1 || e->p.c_atb.center > 1 || e->p.c_atb.diffusion > 1
			|| e->p.c_atb.direction > 1 || e->p.c_atb.reflection > 1
			|| e->p.c_atb.specvalue > 1 || e->p.c_atb.specpower > 1
			|| e->p.c_atb.angle > 1)
		return (44);
	if (e->p.status == 1)
		if (e->p.c_atb.rotate != 0 || e->p.c_atb.translate != 0)
			return (45);
	if (e->p.status == 2)
		if (e->p.c_atb.rotate != 1 || e->p.c_atb.translate != 1)
			return (46);
	return (0);
}

int		shapevocab_checker_partwo_cyn(t_env *e)
{
	if (e->p.y_atb.radius < 1 || e->p.y_atb.center < 1 || e->p.y_atb.diffusion < 1
			|| e->p.y_atb.direction < 1 || e->p.y_atb.reflection < 1
			|| e->p.y_atb.specvalue < 1 || e->p.y_atb.specpower < 1
			|| e->p.y_atb.angle < 1)
		return (47);
	if (e->p.y_atb.radius > 1 || e->p.y_atb.center > 1 || e->p.y_atb.diffusion > 1
			|| e->p.y_atb.direction > 1 || e->p.y_atb.reflection > 1
			|| e->p.y_atb.specvalue > 1 || e->p.y_atb.specpower > 1
			|| e->p.y_atb.angle > 1)
		return (48);
	if (e->p.status == 1)
		if (e->p.y_atb.rotate != 0 || e->p.y_atb.translate != 0)
			return (49);
	if (e->p.status == 2)
		if (e->p.y_atb.rotate != 1 || e->p.y_atb.translate != 1)
			return (50);
	return (0);
}

int		shapevocab_checker_partwo_plane(t_env *e)
{
	if (e->p.p_atb.normal < 1 || e->p.p_atb.d < 1 || e->p.p_atb.diffusion < 1
			|| e->p.p_atb.reflection < 1 || e->p.p_atb.specvalue < 1
			|| e->p.p_atb.specpower < 1)
		return (51);
	if (e->p.p_atb.normal > 1 || e->p.p_atb.d > 1 || e->p.p_atb.diffusion > 1
			|| e->p.p_atb.reflection > 1 || e->p.p_atb.specvalue > 1
			|| e->p.p_atb.specpower > 1)
		return (52);
	if (e->p.status == 1)
		if (e->p.p_atb.rotate != 0 || e->p.p_atb.translate != 0)
			return (53);
	if (e->p.status == 2)
		if (e->p.p_atb.rotate != 1 || e->p.p_atb.translate != 1)
			return (54);
	return (0);
}

int		shapevocab_checker_partwo(t_env *e)
{
	int ret;

	ret = 0;
	if (e->cs == 1)
		if ((ret = shapevocab_checker_partwo_sphere(e)) != 0)
			return (ret);
	if (e->cs == 2)
		if ((ret = shapevocab_checker_partwo_cone(e)) != 0)
			return (ret);
	if (e->cs == 3)
		if ((ret = shapevocab_checker_partwo_cyn(e)) != 0)
			return (ret);
	if (e->cs == 4)
		if ((ret = shapevocab_checker_partwo_plane(e)) != 0)
			return (ret);
	return (0);
}
