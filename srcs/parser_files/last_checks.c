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

int		last_checks(t_env *e)
{
	if (e->p.objects != 2 || e->p.specs != 2)
		return (4);
	if (e->p.p_spec.cam_cl != 1 || e->p.p_spec.amb_cl != 1)
		return (26);
	if (e->p.scene != 2)
		return (6);
	if ((e->p.count.spheres + e->p.count.planes + e->p.count.cones + \
				e->p.count.cylinders) == 0)
		return (59);
	if ((ft_iseven(e->p.p_spec.light)) == -1)
		return (27);
	if ((ft_iseven(e->p.p_obj.sphere)) == -1)
		return (34);
	if ((ft_iseven(e->p.p_obj.cone)) == -1)
		return (34);
	if ((ft_iseven(e->p.p_obj.cyn)) == -1)
		return (34);
	if ((ft_iseven(e->p.p_obj.plane)) == -1)
		return (34);
	if (e->p.p_spec.cam != 2 || e->p.p_spec.amb != 2)
		return (37);
	if (e->p.ret.gnl == -1)
		return (1);
	return (0);
}
