#include "vector.h"

t_vec2  v2_frompoints(t_vec2 ori, t_vec2 dest)
{
    t_vec2  u;

    u.x = dest.x - ori.x;
    u.y = dest.y - ori.y;
    return (u);
}

t_vec3  v3_frompoints(t_vec3 ori, t_vec3 dest)
{
    t_vec3  u;

    u.x = dest.x - ori.x;
    u.y = dest.y - ori.y;
    u.z = dest.z - ori.z;
    return (u);
}

t_vec4  v4_frompoints(t_vec4 ori, t_vec4 dest)
{
    t_vec4  u;

    u.x = dest.x - ori.x;
    u.y = dest.y - ori.y;
    u.z = dest.z - ori.z;
    u.w = 0;
    return (u);
}