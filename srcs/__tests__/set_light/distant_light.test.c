#include "rt.test.h"

static t_ll					ll;
static t_distant_light		*dl;
static t_arg_distant_light	arg;
static t_vec3				expected_v;
static int					res;

TEST_GROUP(set_distant_light);

TEST_SETUP(set_distant_light)
{
	ll.light = ft_memalloc(sizeof(t_distant_light));
	dl = (t_distant_light *)ll.light;
}

TEST_TEAR_DOWN(set_distant_light)
{
	ft_memdel((void **)&dl);
}

TEST(set_distant_light, valid)
{
	arg.dir = (t_vec3){1.0, 2.0, -0.9};
	arg.rot = (t_vec3){0.2, 0.3, 1.9};
	expected_v = v3_normalise(arg.dir);

	res = set_distant_light(&ll, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected_v, &dl->dir, sizeof(t_vec3), "dir");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&arg.rot, &dl->rot, sizeof(t_vec3), "rot");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&distant_light_dir, ll.get_dir, "get_dir");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&distant_light_distance, ll.get_distance, "get_distant");
}

TEST(set_distant_light, dir_norm_is_0)
{
	arg.dir = (t_vec3){0.0, 0.0, 0.0};
	arg.rot = (t_vec3){0.2, 0.3, 1.9};
	expected_v = v3_normalise(arg.dir);

	res = set_distant_light(&ll, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST_GROUP_RUNNER(set_distant_light)
{
	RUN_TEST_CASE(set_distant_light, valid);
	RUN_TEST_CASE(set_distant_light, dir_norm_is_0);
}
