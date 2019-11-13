typedef struct  s_vec2
{
    double  x;
    double  y;
}               t_vec2;

typedef struct  s_vec3
{
    double  x;
    double  y;
    double  z;
}               t_vec3;

typedef struct  s_vec4
{
    double  x;
    double  y;
    double  z;
    double  w;
}               t_vec4;

t_vec2		v2_add(t_vec2 u, t_vec2 v);
t_vec3		v3_add(t_vec3 u, t_vec3 v);
t_vec4		v4_add(t_vec4 u, t_vec4 v);
t_vec2		v2_sub(t_vec2 u, t_vec2 v);
t_vec3		v3_sub(t_vec3 u, t_vec3 v);
t_vec4		v4_sub(t_vec4 u, t_vec4 v);
t_vec2		v2_scalar(t_vec2 u, double k);
t_vec3		v3_scalar(t_vec3 u, double k);
t_vec4		v4_scalar(t_vec4 u, double k);
double		v2_dotpdt(t_vec2 u, t_vec2 v);
double		v3_dotpdt(t_vec3 u, t_vec3 v);
double		v4_dotpdt(t_vec4 u, t_vec4 v);
