/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 10:52:23 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/20 10:57:18 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		last_checks(t_parser *p)
{
	if (p->objects != 2 || p->specs != 2)
		return (4);
	if (p->p_spec.cam_cl != 1 || p->p_spec.amb_cl != 1)
		return (26);
	if (p->scene != 2)
		return (6);
	if ((p->count.spheres + p->count.planes + p->count.cones + \
				p->count.cylinders) == 0)
		return (59);
	if ((ft_iseven(p->p_spec.light)) == -1)
		return (27);
	if ((ft_iseven(p->p_obj.sphere)) == -1)
		return (34);
	if ((ft_iseven(p->p_obj.cone)) == -1)
		return (34);
	if ((ft_iseven(p->p_obj.cyn)) == -1)
		return (34);
	if ((ft_iseven(p->p_obj.plane)) == -1)
		return (34);
	if (p->p_spec.cam != 2 || p->p_spec.amb != 2)
		return (37);
	if (p->ret.gnl == -1)
		return (1);
	return (0);
}
