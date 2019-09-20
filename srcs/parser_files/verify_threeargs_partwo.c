/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_threeargs_partwo.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:10:15 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/11 15:31:28 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		verify_values(t_parser *p)
{
	if (p->v1 == 0 && p->v2 == 0 && p->v3 == 0)
		return (-1);
    return (0);
}

int		verify_values_diff(t_parser *p)
{
	if (p->v1 < 0 || p->v1 > 255)
		return (-1);
	if (p->v2 < 0 || p->v2 > 255)
		return (-1);
	if (p->v3 < 0 || p->v3 > 255)
		return (-1);
    return (0);
}

int		verify_numbers_three(t_env *e, t_parser *p, t_ll *l_head, t_ol *o_head)
{
	t_ll	*l_tmp;
	t_ol	*o_tmp;

	l_tmp = l_head;
	o_tmp = o_head;
	if (ft_strcmp("direction", p->strtwo) == 0)
	{
		if ((p->ret_p = verify_values(p)) != 0)
			return (85);
        if (p->specs == 1 && p->objects == 0)
		{
			if (p->p_spec.cam == 1 && p->p_spec.amb_cl == 0)
            {
                e->cam.camdir.x = p->v1;
                e->cam.camdir.y = p->v2;
                e->cam.camdir.z = p->v3;
            }
		}
        if (p->specs == 2 && p->objects == 1)
		{
            if (e->cs == 1 || e->cs == 2 || e->cs == 3)
            {
				while (o_tmp->next != NULL)
					o_tmp = o_tmp->next;
				o_tmp->dir.x = p->v1;
				o_tmp->dir.y = p->v2;
				o_tmp->dir.z = p->v3;
            }
		}
	}
	else if (ft_strcmp("center", p->strtwo) == 0)
	{
        if ((e->cs == 0 || e->cs == 1 || e->cs == 2) && (p->specs == 2 && p->objects == 1))
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->cen.x = p->v1;
			o_tmp->cen.y = p->v2;
			o_tmp->cen.z = p->v3;
		}
	}
	else if (ft_strcmp("normal", p->strtwo) == 0) 
	{
		if ((p->ret_p = verify_values(p)) != 0)
			return (85);
		if (e->cs == 4 && (p->specs == 2 && p->objects == 1))
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->nor.x = p->v1;
			o_tmp->nor.y = p->v2;
			o_tmp->nor.z = p->v3;
		}
	}
	else if (ft_strcmp("diffusion", p->strtwo) == 0)
	{
		if (verify_values_diff(p) != 0)
			return (86);
		if (p->specs == 2 && p->objects == 1)
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->dif.x = p->v1;
			o_tmp->dif.y = p->v2;
			o_tmp->dif.z = p->v3;
			o_tmp->cur_shape = e->cs;
			o_tmp->status = p->status;
		}
	}
	else if (ft_strcmp("rotate", p->strtwo) == 0)
	{
    	if (p->p_spec.cam_cl == 1 && p->p_spec.amb_cl == 1 && p->status == 2 && p->objects == 0) // light position
		{
			while (l_tmp->next != NULL)
				l_tmp = l_tmp->next;
			l_tmp->rot.x = p->v1;
			l_tmp->rot.y = p->v2;
			l_tmp->rot.z = p->v3;
		}
		if (p->objects == 1 && p->status == 2)
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->rot.x = p->v1;
			o_tmp->rot.y = p->v2;
			o_tmp->rot.z = p->v3;
		}
	}
	else if (ft_strcmp("translate", p->strtwo) == 0)
	{
		if (p->p_spec.cam_cl == 1 && p->p_spec.amb_cl == 1 && p->status == 2 && p->objects == 0)
		{
			while (l_tmp->next != NULL)
				l_tmp = l_tmp->next;
			l_tmp->tra.x = p->v1;
			l_tmp->tra.y = p->v2;
			l_tmp->tra.z = p->v3;
		}
		if (p->objects == 1 && p->status == 2)
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->tra.x = p->v1;
			o_tmp->tra.y = p->v2;
			o_tmp->tra.z = p->v3;
		}
	}
	else if (ft_strcmp("position", p->strtwo) == 0)
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
	else if (ft_strcmp("color", p->strtwo) == 0)
	{
		if (p->p_spec.cam_cl == 1 && p->p_spec.light == 0 && p->objects == 0)
		{
			e->amb.col.x = p->v1;
			e->amb.col.y = p->v2;
			e->amb.col.z = p->v3;
		}
	}
	else if (ft_strcmp("intensity", p->strtwo) == 0)
	{
		if (p->p_spec.cam_cl == 1 && p->p_spec.amb_cl == 1 && p->objects == 0)
		{
			while (l_tmp->next != NULL)
				l_tmp = l_tmp->next;
			l_tmp->its.x = p->v1;
			l_tmp->its.y = p->v2;
			l_tmp->its.z = p->v3;
		}
	}
	return (0);
}
