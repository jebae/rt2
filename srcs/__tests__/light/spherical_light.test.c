#include "rt.test.h"

static t_ll						ll;
static t_spherical_light		*sl;
static t_arg_spherical_light	arg;
static t_vec3					point;
static t_vec3					dir;
static double					distance;

TEST_GROUP(spherical_light);

TEST_SETUP(spherical_light)
{
	ll.light = ft_memalloc(sizeof(t_spherical_light));
	arg.pos = (t_vec3){0.1, -1.0, 3.14};
	arg.tra = (t_vec3){0.0, 0.0, 0.0};
	set_spherical_light(&ll, &arg);
	sl = (t_spherical_light *)ll.light;
	point = (t_vec3){-2.0, 0.1, 8.1};
}

TEST_TEAR_DOWN(spherical_light)
{
	ft_memdel((void **)&sl);
}

TEST(spherical_light, get_dir)
{
	t_vec3	expected;

	expected = v3_normalise(v3_frompoints(point, sl->pos));
	dir = ll.get_dir(&point, ll.light);
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected, &dir, sizeof(t_vec3), "get_dir");
}

TEST(spherical_light, get_distance)
{
	double	expected;

	distance = ll.get_distance(&point, ll.light);
	expected = v3_norm(v3_frompoints(point, sl->pos));
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(expected, distance, "get_distance");
}

TEST_GROUP_RUNNER(spherical_light)
{
	RUN_TEST_CASE(spherical_light, get_dir);
	RUN_TEST_CASE(spherical_light, get_distance);
}
