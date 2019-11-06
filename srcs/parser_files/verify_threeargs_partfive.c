/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_threeargs_partfive.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:52:11 by mhernand          #+#    #+#             */
/*   Updated: 2019/11/05 15:52:12 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	store_obj_tra(t_parser *p, t_ol *o_tmp)
{
	while (o_tmp->next != NULL)
		o_tmp = o_tmp->next;
	o_tmp->tra.x = p->v1;
	o_tmp->tra.y = p->v2;
	o_tmp->tra.z = p->v3;
}

void	store_lit_tra(t_parser *p, t_ll *l_tmp)
{
	while (l_tmp->next != NULL)
		l_tmp = l_tmp->next;
	l_tmp->tra.x = p->v1;
	l_tmp->tra.y = p->v2;
	l_tmp->tra.z = p->v3;
}

void	store_translate(t_parser *p, t_ll *l_tmp, t_ol *o_tmp)
{
	if (p->p_spec.cam_cl == 1 && p->p_spec.amb_cl == 1
			&& p->status == 2 && p->objects == 0)
		store_lit_tra(p, l_tmp);
	if (p->objects == 1 && p->status == 2)
		store_obj_tra(p, o_tmp);
}
