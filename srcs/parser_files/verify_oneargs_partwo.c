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

int		verify_numbers_one(t_env *e, t_ll *l_head, t_ol *o_head)// working here !
{
    (void)l_head;
	t_ol	*o_tmp;

	o_tmp = o_head;
	e->p.v = ft_atoi(e->p.strone);
	if (ft_strcmp("radius", e->p.strtwo) == 0)
	{
		if (e->p.v <= 0) // || e->p.realnum > LIMIT (?))
			return (83);
		if (e->p.specs == 2 && e->p.objects == 1)
		{
            if (e->cs == 1 || e->cs == 2 || e->cs == 3)
            {
                while (o_tmp->next != NULL)
					o_tmp = o_tmp->next;
				o_tmp->radius = e->p.v;
            }
		}
	}
	else if (ft_strcmp("angle", e->p.strtwo) == 0)
	{
		if (e->p.v > 360 || e->p.v < -360)
			return (84);
		if (e->p.specs == 2 && e->p.objects == 1 && e->cs == 2)
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->angle = e->p.v;
		}
	}
	else if (ft_strcmp("d", e->p.strtwo) == 0)
	{
		if (e->p.specs == 2 && e->p.objects == 1 && e->cs == 4)
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->d = e->p.v;
		}
	}
	else if (ft_strcmp("specpower", e->p.strtwo) == 0)
	{
		if (e->p.specs == 1 && e->p.objects == 0)
		{
			if (e->p.p_spec.cam_cl == 1 && e->p.p_spec.amb_cl == 0) // cam position
                e->amb.specpower = e->p.v;
		}
		else if (e->p.specs == 2 && e->p.objects == 1)
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->specpower = e->p.v;
		}
	}
	else if (ft_strcmp("specvalue", e->p.strtwo) == 0)
	{
		if (e->p.specs == 2 && e->p.objects == 1)
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->specvalue = e->p.v;
		}
	}
	else if (ft_strcmp("reflection", e->p.strtwo) == 0)
	{
		if (e->p.specs == 2 && e->p.objects == 1)
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->ref = e->p.v;
		}
	}
	return (0);
}