
#include "vector.h"

t_vec2		v2_add(t_vec2 u, t_vec2 v)
{
	t_vec2	w;

	w.x = u.x + v.x;
	w.y = u.y + v.y;
	return (w);
}

t_vec3		v3add(t_vec3 u, t_vec3 v, char c)
{
	t_vec3	w;

	w.x = u.x + v.x;
	w.y = u.y + v.y;
	w.z = u.z + v.z;
	return (w);
}

t_vec4		v4_add(t_vec4 u, t_vec4 v, char c)
{
	t_vec4	w;

	w.x = u.x + v.x;
	w.y = u.y + v.y;
	w.z = u.z + v.z;
    w.w = 0;
	return (w);
}