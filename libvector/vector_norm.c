#include "libvector.h"

double		v2_norm(t_vec2 u)
{
	return (sqrt(v2_dotpdt(u, u)));
}

double		v3_norm(t_vec3 u)
{
	return (sqrt(v3_dotpdt(u, u)));
}

double		v4_norm(t_vec4 u)
{
	return (sqrt(v4_dotpdt(u, u)));
}
