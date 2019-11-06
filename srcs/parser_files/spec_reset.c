/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:12:13 by mhernand          #+#    #+#             */
/*   Updated: 2019/11/06 12:12:20 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	reset_spec_atb(t_parser *p)
{
	p->ca_atb.position = 0;
	p->ca_atb.direction = 0;
	p->ca_atb.rotate = 0;
	p->ca_atb.translate = 0;
	p->a_atb.power = 0;
	p->a_atb.color = 0;
	p->l_atb.position = 0;
	p->l_atb.intensity = 0;
	p->l_atb.rotate = 0;
	p->l_atb.translate = 0;
}
