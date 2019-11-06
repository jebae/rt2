/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_threeargs_partfour.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:25:21 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/24 16:09:08 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		verify_rotation(t_parser *p)
{
	if (p->v1 < -1 || p->v1 > 1)
		return (-1);
	if (p->v2 < -1 || p->v2 > 1)
		return (-1);
	if (p->v3 < -1 || p->v3 > 1)
		return (-1);
	return (0);
}

void	store_obj_rot(t_parser *p, t_ol *o_tmp, char *str)
{
	if (ft_strcmp("rotate_x", str) == 0)
	{
		while (o_tmp->next != NULL)
			o_tmp = o_tmp->next;
		o_tmp->rot_x.x = p->v1;
		o_tmp->rot_x.y = p->v2;
		o_tmp->rot_x.z = p->v3;
	}
	else if (ft_strcmp("rotate_y", str) == 0)
	{
		while (o_tmp->next != NULL)
			o_tmp = o_tmp->next;
		o_tmp->rot_y.x = p->v1;
		o_tmp->rot_y.y = p->v2;
		o_tmp->rot_y.z = p->v3;
	}
	else if (ft_strcmp("rotate_z", str) == 0)
	{
		while (o_tmp->next != NULL)
			o_tmp = o_tmp->next;
		o_tmp->rot_z.x = p->v1;
		o_tmp->rot_z.y = p->v2;
		o_tmp->rot_z.z = p->v3;
	}
}

void	store_pos(t_env *e, t_parser *p, t_ll *l_tmp)
{
	if (p->p_spec.cam == 1 && p->p_spec.cam_cl != 1 && p->objects == 0)
	{
		e->cam.campos.x = p->v1;
		e->cam.campos.y = p->v2;
		e->cam.campos.z = p->v3;
	}
	else if (p->p_spec.cam_cl == 1 && p->p_spec.amb_cl == 1 && p->objects == 0)
	{
		while (l_tmp->next != NULL)
			l_tmp = l_tmp->next;
		l_tmp->pos.x = p->v1;
		l_tmp->pos.y = p->v2;
		l_tmp->pos.z = p->v3;
	}
}

int		storing_three_3(t_env *e, t_parser *p, t_ll *l_tmp, t_ol *o_tmp)
{
	if (ft_strncmp("rotate", p->strtwo, 5) == 0)
	{
		if (p->p_spec.cam_cl == 1 && p->p_spec.amb_cl == 1
				&& p->status == 2 && p->objects == 0)
		{
			while (l_tmp->next != NULL)
				l_tmp = l_tmp->next;
			l_tmp->rot.x = p->v1;
			l_tmp->rot.y = p->v2;
			l_tmp->rot.z = p->v3;
		}
		if (p->objects == 1 && p->status == 2)
		{
			if (verify_rotation(p) != 0)
				return (87);
			store_obj_rot(p, o_tmp, p->strtwo);
		}
	}
	else if (ft_strcmp("translate", p->strtwo) == 0)
		store_translate(p, l_tmp, o_tmp);
	else if (ft_strcmp("position", p->strtwo) == 0)
		store_pos(e, p, l_tmp);
	return (0);
}
