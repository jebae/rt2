/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_oneargs_partwo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:10:23 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/10 11:10:28 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		verify_numbers_one(t_env *e, t_parser *p, t_ll *l_head, t_ol *o_head)
{
    (void)l_head;
	(void)e;
	t_ol	*o_tmp;

	o_tmp = o_head;
	p->v = ft_atoi(p->strone);
	if (ft_strcmp("radius", p->strtwo) == 0)
	{
		if (p->v <= 0) // || p->realnum > LIMIT (?))
			return (83);
		if (p->specs == 2 && p->objects == 1)
		{
            if (e->cs == 1 || e->cs == 2 || e->cs == 3)
            {
                while (o_tmp->next != NULL)
					o_tmp = o_tmp->next;
				o_tmp->radius = p->v;
            }
		}
	}
	else if (ft_strcmp("angle", p->strtwo) == 0)
	{
		if (p->v > 360 || p->v < -360)
			return (84);
		if (p->specs == 2 && p->objects == 1 && e->cs == 2)
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->angle = p->v;
		}
	}
	else if (ft_strcmp("d", p->strtwo) == 0)
	{
		if (p->specs == 2 && p->objects == 1 && e->cs == 4)
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->d = p->v;
		}
	}
	else if (ft_strcmp("specpower", p->strtwo) == 0)
	{
		if (p->specs == 1 && p->objects == 0)
		{
			if (p->p_spec.cam_cl == 1 && p->p_spec.amb_cl == 0)
                e->amb.specpower = p->v;
		}
		else if (p->specs == 2 && p->objects == 1)
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->specpower = p->v;
		}
	}
	else if (ft_strcmp("specvalue", p->strtwo) == 0)
	{
		if (p->specs == 2 && p->objects == 1)
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->specvalue = p->v;
		}
	}
	else if (ft_strcmp("reflection", p->strtwo) == 0)
	{
		if (p->specs == 2 && p->objects == 1)
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->ref = p->v;
		}
	}
	return (0);
}