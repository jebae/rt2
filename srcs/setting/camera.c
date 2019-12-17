/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:31:28 by jebae             #+#    #+#             */
/*   Updated: 2019/12/17 19:37:43 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		validate(t_arg_camera *arg)
{
	if (v3_norm2(arg->dir) < RT_APPROX_0)
		return (handle_fail("set_camera : dir's length almost 0"));
	if (v3_norm2(arg->right) < RT_APPROX_0)
		return (handle_fail("set_camera : right's length almost 0"));
	return (RT_SUCCESS);
}

int				set_camera(t_arg_camera *arg, t_camera *cam)
{
	if (validate(arg) == RT_FAIL)
		return (RT_FAIL);
	cam->pos = arg->pos;
	cam->dir = v3_normalise(arg->dir);
	cam->right = v3_normalise(arg->right);
	cam->down = v3_cross(arg->dir, arg->right);
	return (RT_SUCCESS);
}
