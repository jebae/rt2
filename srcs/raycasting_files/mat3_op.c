#include "raycast.h"

t_vec3		m_mult(t_mat3 m, t_vec3 v)
{
	int		r;
	int		c;
	t_vec3	res;
	double	*p_res;
	double	*p_v;

	p_res = (double *)&res;
	p_v = (double *)&v;
	r = 0;
	while (r < 3)
	{
		p_res[r] = 0.0;
		c = 0;
		while (c < 3)
		{
			p_res[r] += m.arr[r][c] * p_v[c];
			c++;
		}
		r++;
	}
	return (res);
}
