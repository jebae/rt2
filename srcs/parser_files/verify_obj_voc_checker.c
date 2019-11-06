/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_obj_voc_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:38:23 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/24 14:05:00 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		shapevocab_checker_partwo_sphere(t_parser *p)
{
	if (p->s_atb.radius < 1 || p->s_atb.center < 1 || p->s_atb.diffusion < 1
			|| p->s_atb.reflection < 1 || p->s_atb.specvalue < 1
			|| p->s_atb.specpower < 1)
		return (39);
	if (p->s_atb.radius > 1 || p->s_atb.center > 1 || p->s_atb.diffusion > 1
			|| p->s_atb.reflection > 1 || p->s_atb.specvalue > 1
			|| p->s_atb.specpower > 1)
		return (40);
	if (p->status == 1)
		if (p->s_atb.rotate_x != 0 || p->s_atb.rotate_y != 0
			|| p->s_atb.rotate_z != 0 || p->s_atb.translate != 0)
			return (41);
	if (p->status == 2)
		if (p->s_atb.rotate_x != 1 || p->s_atb.rotate_y != 1
			|| p->s_atb.rotate_z != 1 || p->s_atb.translate != 1)
			return (42);
	return (0);
}

int		shapevocab_checker_partwo_cone(t_parser *p)
{
	if (p->c_atb.radius < 1 || p->c_atb.center < 1 || p->c_atb.diffusion < 1
			|| p->c_atb.direction < 1 || p->c_atb.reflection < 1
			|| p->c_atb.specvalue < 1 || p->c_atb.specpower < 1
			|| p->c_atb.angle < 1)
		return (43);
	if (p->c_atb.radius > 1 || p->c_atb.center > 1 || p->c_atb.diffusion > 1
			|| p->c_atb.direction > 1 || p->c_atb.reflection > 1
			|| p->c_atb.specvalue > 1 || p->c_atb.specpower > 1
			|| p->c_atb.angle > 1)
		return (44);
	if (p->status == 1)
		if (p->c_atb.rotate_x != 0 || p->c_atb.rotate_y != 0
			|| p->c_atb.rotate_z != 0 || p->c_atb.translate != 0)
			return (45);
	if (p->status == 2)
		if (p->c_atb.rotate_x != 1 || p->c_atb.rotate_y != 1
			|| p->c_atb.rotate_z != 1 || p->c_atb.translate != 1)
			return (46);
	return (0);
}

int		shapevocab_checker_partwo_cyn(t_parser *p)
{
	if (p->y_atb.radius < 1 || p->y_atb.center < 1 || p->y_atb.diffusion < 1
			|| p->y_atb.direction < 1 || p->y_atb.reflection < 1
			|| p->y_atb.specvalue < 1 || p->y_atb.specpower < 1
			|| p->y_atb.angle < 1)
		return (47);
	if (p->y_atb.radius > 1 || p->y_atb.center > 1 || p->y_atb.diffusion > 1
			|| p->y_atb.direction > 1 || p->y_atb.reflection > 1
			|| p->y_atb.specvalue > 1 || p->y_atb.specpower > 1
			|| p->y_atb.angle > 1)
		return (48);
	if (p->status == 1)
		if (p->y_atb.rotate_x != 0 || p->y_atb.rotate_y != 0
			|| p->y_atb.rotate_z != 0 || p->y_atb.translate != 0)
			return (49);
	if (p->status == 2)
		if (p->y_atb.rotate_x != 1 || p->y_atb.rotate_y != 1
			|| p->y_atb.rotate_z != 1 || p->y_atb.translate != 1)
			return (50);
	return (0);
}

int		shapevocab_checker_partwo_plane(t_parser *p)
{
	if (p->p_atb.normal < 1 || p->p_atb.d < 1 || p->p_atb.diffusion < 1
			|| p->p_atb.reflection < 1 || p->p_atb.specvalue < 1
			|| p->p_atb.specpower < 1)
		return (51);
	if (p->p_atb.normal > 1 || p->p_atb.d > 1 || p->p_atb.diffusion > 1
			|| p->p_atb.reflection > 1 || p->p_atb.specvalue > 1
			|| p->p_atb.specpower > 1)
		return (52);
	if (p->status == 1)
		if (p->p_atb.rotate_x != 0 || p->p_atb.rotate_y != 0
			|| p->p_atb.rotate_z != 0 || p->p_atb.translate != 0)
			return (53);
	if (p->status == 2)
		if (p->p_atb.rotate_x != 1 || p->p_atb.rotate_y != 1
			|| p->p_atb.rotate_z != 1 || p->p_atb.translate != 1)
			return (54);
	return (0);
}

int		shapevocab_checker_partwo(t_env *e, t_parser *p)
{
	int ret;

	ret = 0;
	if (e->cs == 1)
		if ((ret = shapevocab_checker_partwo_sphere(p)) != 0)
			return (ret);
	if (e->cs == 2)
		if ((ret = shapevocab_checker_partwo_cone(p)) != 0)
			return (ret);
	if (e->cs == 3)
		if ((ret = shapevocab_checker_partwo_cyn(p)) != 0)
			return (ret);
	if (e->cs == 4)
		if ((ret = shapevocab_checker_partwo_plane(p)) != 0)
			return (ret);
	return (0);
}
