/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanbox.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabonifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:25:49 by sabonifa          #+#    #+#             */
/*   Updated: 2019/09/17 11:16:23 by sabonifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "rtv1s.h"

#define X0 -WIDTH / 2
#define Y0 -WIDTH / 2
#define	RAYON 70

#define cx 0 // camera coordinates
#define cy 0
#define cz -50
#define sx 0// sphere coordinates
#define sy 0
#define sz 21
 /*
typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;
*/

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;
/*
typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;
*/
//t_point	cam; cam.x = 0; cam.y = 0; cam.z = -50;
t_mlx   init(t_mlx *p);
int		sand(t_env *e);
int 	sand2(t_env *e, t_ol *ol, t_ll *ll);
/*
** Vector operations
*/

t_point     create_pt(double x, double y, double z);
t_vector    create_v(t_point ori, t_point dest);
t_vector    v_add(t_vector u, t_vector v, char c);
t_vector    v_mult(t_vector u, double k);
double      v_scal(t_vector u, t_vector v);
double      v_norm(t_vector u);
t_vector    v_cross(t_vector u, t_vector v);
t_vector    v_normalise(t_vector u);

/*
** Intersection functions
*/

double v_intersect_sp(t_vector ray, t_ol *ol, t_env *e);
