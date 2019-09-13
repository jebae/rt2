/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanbox.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:25:49 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/12 19:07:32 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 1000
#define X0 -WIDTH / 2
#define Y0 -WIDTH / 2
#define	RAYON 70

#define cx 0 // camera coordinates
#define cy 0
#define cz -50
#define sx 10 + X0// sphere coordinates
#define sy 10 + Y0
#define sz 21

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}t_env;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

//t_point	cam; cam.x = 0; cam.y = 0; cam.z = -50;
t_env   *init(t_env *p);
int		sand(t_env *e);

/*
 * Vector operations
*/

t_point     point(double x, double y, double z);
t_vector    vector(t_point o, t_point p);
t_vector    v_add(t_vector u, t_vector v, char c);
t_vector    v_mult(t_vector u, double k);
double          v_scal(t_vector u, t_vector v);
double          v_norm(t_vector u);
t_vector    v_cross(t_vector u, t_vector v);
int v_intersecit(t_vector ray);
t_vector        v_normalise(t_vector u);
