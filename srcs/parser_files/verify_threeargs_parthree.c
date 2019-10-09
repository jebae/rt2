/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_threeargs_parthree.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:12:30 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/26 13:23:25 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	store_light_int(t_parser *p, t_ll *l_tmp)
{
	while (l_tmp->next != NULL)
		l_tmp = l_tmp->next;
	l_tmp->its.x = p->v1;
	l_tmp->its.y = p->v2;
	l_tmp->its.z = p->v3;
}

void	store_normal(t_parser *p, t_ol *o_tmp)
{
	while (o_tmp->next != NULL)
		o_tmp = o_tmp->next;
	o_tmp->nor.x = p->v1;
	o_tmp->nor.y = p->v2;
	o_tmp->nor.z = p->v3;
}

void	store_diffusion(t_env *e, t_parser *p, t_ol *o_tmp)
{
	while (o_tmp->next != NULL)
		o_tmp = o_tmp->next;
	o_tmp->dif.x = p->v1;
	o_tmp->dif.y = p->v2;
	o_tmp->dif.z = p->v3;
	o_tmp->cur_shape = e->cs;
	o_tmp->status = p->status;
}

int		storing_three_2(t_env *e, t_parser *p, t_ll *l_tmp, t_ol *o_tmp)
{
	if (ft_strcmp("intensity", p->strtwo) == 0)
	{
		if (p->p_spec.cam_cl == 1 && p->p_spec.amb_cl == 1 && p->objects == 0)
			store_light_int(p, l_tmp);
	}
	else if (ft_strcmp("normal", p->strtwo) == 0)
	{
		if ((p->ret_p = verify_values(p)) != 0)
			return (85);
		if (e->cs == 4 && (p->specs == 2 && p->objects == 1))
			store_normal(p, o_tmp);
	}
	else if (ft_strcmp("diffusion", p->strtwo) == 0)
	{
		if (verify_values_diff(p) != 0)
			return (86);
		if (p->specs == 2 && p->objects == 1)
			store_diffusion(e, p, o_tmp);
	}
	else
		storing_three_3(e, p, l_tmp, o_tmp);
	return (0);
}

int		storing_three(t_env *e, t_parser *p, t_ll *l_tmp, t_ol *o_tmp)
{
	if (ft_strcmp("center", p->strtwo) == 0)
	{
		if ((e->cs == 1 || e->cs == 2 || e->cs == 3) && (p->objects == 1))
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->cen.x = p->v1;
			o_tmp->cen.y = p->v2;
			o_tmp->cen.z = p->v3;
		}
	}
	else if (ft_strcmp("color", p->strtwo) == 0)
	{
		if (p->p_spec.cam_cl == 1 && p->p_spec.light == 0 && p->objects == 0)
		{
			e->amb.col.r = p->v1;
			e->amb.col.g = p->v2;
			e->amb.col.b = p->v3;
		}
	}
	else if ((p->ret_p = storing_three_2(e, p, l_tmp, o_tmp)) != 0)
		return (p->ret_p);
	return (0);
}
