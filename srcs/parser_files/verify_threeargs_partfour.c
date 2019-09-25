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

void	store_obj_rot(t_parser *p, t_ol *o_tmp)
{
	while (o_tmp->next != NULL)
		o_tmp = o_tmp->next;
	o_tmp->rot.x = p->v1;
	o_tmp->rot.y = p->v2;
	o_tmp->rot.z = p->v3;
}

void	store_obj_tra(t_parser *p, t_ol *o_tmp)
{
	while (o_tmp->next != NULL)
		o_tmp = o_tmp->next;
	o_tmp->tra.x = p->v1;
	o_tmp->tra.y = p->v2;
	o_tmp->tra.z = p->v3;
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

void	store_lit_tra(t_parser *p, t_ll *l_tmp)
{
	while (l_tmp->next != NULL)
		l_tmp = l_tmp->next;
	l_tmp->tra.x = p->v1;
	l_tmp->tra.y = p->v2;
	l_tmp->tra.z = p->v3;
}

void	storing_three_3(t_env *e, t_parser *p, t_ll *l_tmp, t_ol *o_tmp)
{
	if (ft_strcmp("rotate", p->strtwo) == 0)
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
			store_obj_rot(p, o_tmp);
	}
	else if (ft_strcmp("translate", p->strtwo) == 0)
	{
		if (p->p_spec.cam_cl == 1 && p->p_spec.amb_cl == 1
				&& p->status == 2 && p->objects == 0)
			store_lit_tra(p, l_tmp);
		if (p->objects == 1 && p->status == 2)
			store_obj_tra(p, o_tmp);
	}
	else if (ft_strcmp("position", p->strtwo) == 0)
		store_pos(e, p, l_tmp);
}
