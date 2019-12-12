#include "rt.h"

t_vec4		rotate_q(t_vec4 *n, float theta)
{
	t_vec4		q;
	double		s;

	s = sin(theta * 0.5);
	q.x = s * n->x;
	q.y = s * n->y;
	q.z = s * n->z;
	q.w = cos(theta * 0.5);
	return (q);
}

t_vec4		rotate(t_vec4 *q, t_vec4 *v, t_vec4 *q_i)
{
	t_vec4	res;

	v->w = 0.0;
	res = q_mul_q(q, v);
	res = q_mul_q(&res, q_i);
	v->w = 1.0;
	res.w = 1.0;
	return (res);
}
