/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_threeargs_partwo.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:10:15 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/24 16:06:05 by mhernand         ###   ########.fr       */
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

void	store_camdir(t_env *e, t_parser *p)
{
	e->cam.camdir.x = p->v1;
	e->cam.camdir.y = p->v2;
	e->cam.camdir.z = p->v3;
}

void	store_objdir(t_parser *p, t_ol *o_tmp)
{
	while (o_tmp->next != NULL)
		o_tmp = o_tmp->next;
	o_tmp->dir.x = p->v1;
	o_tmp->dir.y = p->v2;
	o_tmp->dir.z = p->v3;
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
				store_camdir(e, p);
		}
		if (p->specs == 2 && p->objects == 1)
		{
			if (e->cs == 1 || e->cs == 2 || e->cs == 3)
				store_objdir(p, o_tmp);
		}
	}
	else if ((p->ret_p = storing_three(e, p, l_tmp, o_tmp)) != 0)
		return (p->ret_p);
	return (0);
}
