/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:30:45 by jebae             #+#    #+#             */
/*   Updated: 2019/12/16 15:30:45 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		sphere_rotate(
	t_vec4 *q,
	t_mat3 *axis_mat,
	void *object
)
{
	(void)object;
	rotate_object_axis(q, axis_mat);
}
