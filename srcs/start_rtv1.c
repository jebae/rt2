/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rtv1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:55:08 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/20 10:12:37 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	temp_function_print_data(t_env *e)	
{
	t_ll 	*tmp;
	t_ol 	*omp;
	int		i = 1;

	tmp = NULL;
	tmp = e->ll_lit;
	omp = NULL;
	omp = e->ll_obj;
	printf("\nCAMERA :\n");
	printf("position -> x : [%f] - y : [%f] - z : [%f] === ", e->cam.campos.x, e->cam.campos.y, e->cam.campos.z );
	printf("direction -> x : [%f] - y : [%f] - z : [%f] \n\n", e->cam.camdir.x, e->cam.camdir.y, e->cam.camdir.z );

	printf("AMBIANCE :\n");
	printf("specpower -> value [%d]] === ", e->amb.specpower);
	printf("color -> x : [%d] - y : [%d] - z : [%d] \n\n", e->amb.col.x, e->amb.col.y, e->amb.col.z );

	printf("LIGHT: \n");
	while (tmp)
	{
		printf("i : [%d] -- pos -> x : [%f] - y : [%f] - z : [%f] === ", i, tmp->pos.x, tmp->pos.y, tmp->pos.z);
		printf("ints -> x : [%f] - y : [%f] - z : [%f] === ", tmp->its.x, tmp->its.y, tmp->its.z);
		printf("rot -> x : [%f] - y : [%f] - z : [%f] === ", tmp->rot.x, tmp->rot.y, tmp->rot.z);
		printf("tra -> x : [%f] - y : [%f] - z : [%f] \n", tmp->tra.x, tmp->tra.y, tmp->tra.z);
		tmp = tmp->next;
		i++;
	}
	printf("\n\n");
	i = 1;
	while (omp)
	{
		printf("ind : [%d] ---> ", i);
		if (omp->cur_shape == 1)
			printf("SPHERE !\n");
		if (omp->cur_shape == 2)
			printf("CONE !\n");
		if (omp->cur_shape == 3)
			printf("CYLINDER !\n");
		if (omp->cur_shape == 4)
			printf("PLANE !\n");
		printf("CENTER    ---> x : [%f] - y : [%f] - z : [%f]\n", omp->cen.x, omp->cen.y, omp->cen.z);
		printf("DIRECTION ---> x : [%f] - y : [%f] - z : [%f]\n", omp->dir.x, omp->dir.y, omp->dir.z);
		printf("DIFFUSION ---> x : [%f] - y : [%f] - z : [%f]\n", omp->dif.x, omp->dif.y, omp->dif.z);
		printf("ROTATION  ---> x : [%f] - y : [%f] - z : [%f]\n", omp->rot.x, omp->rot.y, omp->rot.z);
		printf("NORMAL 	  ---> x : [%f] - y : [%f] - z : [%f]\n", omp->nor.x, omp->nor.y, omp->nor.z);
		printf("TRANSLATE ---> x : [%f] - y : [%f] - z : [%f]\n", omp->tra.x, omp->tra.y, omp->tra.z);
		printf("RADIUS    ---> [%d]\n", omp->radius);
		printf("ANGLE     ---> [%f]\n", omp->angle);
		printf("SPECVALUE ---> [%d]\n", omp->specvalue);
		printf("REFLECT   ---> [%d]\n", omp->ref);
		printf("SPECPOWER ---> [%d]\n", omp->specpower);
		printf("D-plane   ---> [%d]\n", omp->d);
		printf("STATUS    ---> [%d]\n\n", omp->status);
		omp = omp->next;
		i++;
	}
}

t_vec4	normalize_vector(t_vec4 vector)
{
	int		magnitude;
	t_vec4	tmp;

	magnitude = sqrt(vector.x * vector.x + vector.y * vector.y);
	// normalize = sqrt(pow((double)vector.x/magnitude, 2) + pow((double)vector.y/magnitude, 2)); // need to cast as doubles here !
	printf("magnitude : [%d]\n", magnitude);
	tmp.x = (double)vector.x / magnitude;
	tmp.y = (double)vector.y / magnitude;
	tmp.z = (double)vector.z / magnitude;
	return (vector);
}

t_vec4	vector_diff(t_point pos, t_vec3 dir) // switch pos and dir !
{
	t_vec4	tmp;

	tmp.x = pos.x - dir.x;
	tmp.y = pos.y - dir.y;
	tmp.z = pos.z - dir.z;
	return (tmp);
}

t_vec4	crossproduct(t_vec4 one, t_vec4 two)
{
	t_vec4	tmp;

	tmp.x = one.y * two.z - one.z * two.y;
	tmp.y = one.z * two.x - one.x * two.z;
	tmp.z = one.x * two.y - one.y * two.x;
	return (tmp);
}

t_creecam	setup_camera(t_env *e)
{
	(void)e;
	t_creecam	thecam;
	t_vec4		tmp;
	t_vec4		forward;
	t_vec4		up; // camera up
	t_vec4		fo; // camera forward
	t_vec4		le; // camera right

	tmp.x = 0;
	tmp.y = 1;
	tmp.z = 0;

	forward = normalize_vector(vector_diff(e->cam.campos, e->cam.camdir));
	le = normalize_vector(crossproduct(tmp, forward));
	up = normalize_vector(crossproduct(forward, le));
	fo = forward;

	thecam.v1 = le;
	thecam.v2 = up;
	thecam.v3 = fo;

	return (thecam);
}

void    start_rtv1(t_env *e)
{
	t_creecam	mycam;

	mlx_put_image_to_window(e->w.mp, e->w.wp, e->w.ip, 0, 0);
	mlx_hook(e->w.wp, 2, 1L << 2, key_press, e);
	mlx_hook(e->w.wp, 3, 1L << 3, key_release, e);
	// mlx_hook(e->w.wp, 6, 1L << 6, mouse_move, e);
	// mlx_hook(e->w.wp, 4, 1L << 4, mouse_click, e);
	// mlx_hook(e->w.wp, 5, 1L << 5, mouse_no_click, e);
	mlx_hook(e->w.wp, 17, 1L << 17, quit, e);
	mlx_loop_hook(e->w.mp, touch, e);
	// temp_function_print_data(e);   
	mycam = setup_camera(e);
}
