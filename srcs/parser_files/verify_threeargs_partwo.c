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

int		verify_values(t_env *e)
{
	if (e->p.v1 == 0 && e->p.v2 == 0 && e->p.v3 == 0)
		return (-1);
    return (0);
}

int		verify_values_diff(t_env *e)
{
	if (e->p.v1 < 0 || e->p.v1 > 255)
		return (-1);
	if (e->p.v2 < 0 || e->p.v2 > 255)
		return (-1);
	if (e->p.v3 < 0 || e->p.v3 > 255)
		return (-1);
    return (0);
}

int		verify_numbers_three(t_env *e, t_ll *l_head, t_ol *o_head) // working here 
{
	t_ll	*l_tmp;
	t_ol	*o_tmp;

	l_tmp = l_head;
	o_tmp = o_head;
	if (ft_strcmp("direction", e->p.strtwo) == 0)
	{
		if ((e->p.ret_p = verify_values(e)) != 0)
			return (85);
        if (e->p.specs == 1 && e->p.objects == 0) // in the specs tag <specs> </specs>
		{
			if (e->p.p_spec.cam == 1 && e->p.p_spec.amb_cl == 0) // cam position
            {
                e->cam.camdir.x = e->p.v1;
                e->cam.camdir.y = e->p.v2;
                e->cam.camdir.z = e->p.v3;
            }
		}
        if (e->p.specs == 2 && e->p.objects == 1) // in the objects tag <objects> </objects>
		{
            if (e->cs == 1 || e->cs == 2 || e->cs == 3)
            {
				while (o_tmp->next != NULL)
					o_tmp = o_tmp->next;
				o_tmp->dir.x = e->p.v1;
				o_tmp->dir.y = e->p.v2;
				o_tmp->dir.z = e->p.v3;
            }
		}
	}
	else if (ft_strcmp("center", e->p.strtwo) == 0)
	{
        if ((e->cs == 0 || e->cs == 1 || e->cs == 2) && (e->p.specs == 2 && e->p.objects == 1))
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->cen.x = e->p.v1;
			o_tmp->cen.y = e->p.v2;
			o_tmp->cen.z = e->p.v3;
		}
	}
	else if (ft_strcmp("normal", e->p.strtwo) == 0) 
	{
		if ((e->p.ret_p = verify_values(e)) != 0)
			return (85);
		if (e->cs == 4 && (e->p.specs == 2 && e->p.objects == 1))
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->nor.x = e->p.v1;
			o_tmp->nor.y = e->p.v2;
			o_tmp->nor.z = e->p.v3;
		}
	}
	else if (ft_strcmp("diffusion", e->p.strtwo) == 0)
	{
		if (verify_values_diff(e) != 0)
			return (86);
		if (e->p.specs == 2 && e->p.objects == 1)
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->dif.x = e->p.v1;
			o_tmp->dif.y = e->p.v2;
			o_tmp->dif.z = e->p.v3;
			o_tmp->cur_shape = e->cs;
			o_tmp->status = e->p.status;
		}
	}
	else if (ft_strcmp("rotate", e->p.strtwo) == 0)
	{
    	if (e->p.p_spec.cam_cl == 1 && e->p.p_spec.amb_cl == 1 && e->p.status == 2 && e->p.objects == 0) // light position
		{
			while (l_tmp->next != NULL)
				l_tmp = l_tmp->next;
			l_tmp->rot.x = e->p.v1;
			l_tmp->rot.y = e->p.v2;
			l_tmp->rot.z = e->p.v3;
		}
		if (e->p.objects == 1 && e->p.status == 2)
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->rot.x = e->p.v1;
			o_tmp->rot.y = e->p.v2;
			o_tmp->rot.z = e->p.v3;
		}
	}
	else if (ft_strcmp("translate", e->p.strtwo) == 0)
	{
		if (e->p.p_spec.cam_cl == 1 && e->p.p_spec.amb_cl == 1 && e->p.status == 2 && e->p.objects == 0) // light position
		{
			while (l_tmp->next != NULL)
				l_tmp = l_tmp->next;
			l_tmp->tra.x = e->p.v1;
			l_tmp->tra.y = e->p.v2;
			l_tmp->tra.z = e->p.v3;
		}
		if (e->p.objects == 1 && e->p.status == 2)
		{
			while (o_tmp->next != NULL)
				o_tmp = o_tmp->next;
			o_tmp->tra.x = e->p.v1;
			o_tmp->tra.y = e->p.v2;
			o_tmp->tra.z = e->p.v3;
		}
	}
	else if (ft_strcmp("position", e->p.strtwo) == 0)
	{
		if (e->p.p_spec.cam == 1 && e->p.p_spec.cam_cl != 1 && e->p.objects == 0)
		{
			e->cam.campos.x = e->p.v1;
			e->cam.campos.y = e->p.v2;
			e->cam.campos.z = e->p.v3;
		}
		else if (e->p.p_spec.cam_cl == 1 && e->p.p_spec.amb_cl == 1 && e->p.objects == 0)
		{
			while (l_tmp->next != NULL)
				l_tmp = l_tmp->next;
			l_tmp->pos.x = e->p.v1;
			l_tmp->pos.y = e->p.v2;
			l_tmp->pos.z = e->p.v3;
		}
	}
	else if (ft_strcmp("color", e->p.strtwo) == 0)
	{
		if (e->p.p_spec.cam_cl == 1 && e->p.p_spec.light == 0 && e->p.objects == 0)
		{
			e->amb.col.x = e->p.v1;
			e->amb.col.y = e->p.v2;
			e->amb.col.z = e->p.v3;
		}
	}
	else if (ft_strcmp("intensity", e->p.strtwo) == 0)
	{
		if (e->p.p_spec.cam_cl == 1 && e->p.p_spec.amb_cl == 1 && e->p.objects == 0) // light position
		{
			while (l_tmp->next != NULL)
				l_tmp = l_tmp->next;
			l_tmp->its.x = e->p.v1;
			l_tmp->its.y = e->p.v2;
			l_tmp->its.z = e->p.v3;
		}
	}
	return (0);
}
