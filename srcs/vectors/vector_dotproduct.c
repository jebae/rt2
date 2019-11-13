#include "vector.h"

double		v2_dotpdt(t_vec2 u, t_vec2 v)
{
	return (u.x * v.x + u.y * v.y);
}

double		v3_dotpdt(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double		v4_dotpdt(t_vec4 u, t_vec4 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

