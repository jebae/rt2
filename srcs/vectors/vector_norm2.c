#include "vector.h"

double		v2_norm2(t_vec2 u)
{
	return (v2_dotpdt(u, u));
}

double		v3_norm2(t_vec3 u)
{
	return (v3_dotpdt(u, u));
}

double		v4_norm2(t_vec4 u)
{
	return (v4_dotpdt(u, u));
}
