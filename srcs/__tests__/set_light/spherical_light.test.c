#include "rt.test.h"

static t_ll						ll;
static t_spherical_light		*sl;
static t_arg_spherical_light	arg;
static int						res;

TEST_GROUP(set_spherical_light);

TEST_SETUP(set_spherical_light)
{
	ll.light = ft_memalloc(sizeof(t_spherical_light));
	sl = (t_spherical_light *)ll.light;
}

TEST_TEAR_DOWN(set_spherical_light)
{
	ft_memdel((void **)&sl);
}

TEST(set_spherical_light, valid)
{
	arg.pos = (t_vec3){1.0, 2.0, -0.9};

	res = set_spherical_light(&ll, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&arg.pos, &sl->pos, sizeof(t_vec3), "pos");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&spherical_light_dir, ll.get_dir, "get_dir");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&spherical_light_distance, ll.get_distance, "get_spherical");
}

TEST_GROUP_RUNNER(set_spherical_light)
{
	RUN_TEST_CASE(set_spherical_light, valid);
}
