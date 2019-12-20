#include "rt.test.h"

static t_ll						ll;
static t_distant_light			*dl;
static t_arg_distant_light		arg;
static t_vec3					dir;
static double					distance;

TEST_GROUP(distant_light);

TEST_SETUP(distant_light)
{
	ll.light = ft_memalloc(sizeof(t_distant_light));
	arg.dir = (t_vec3){0.1, -1.0, 3.14};
	set_distant_light(&ll, &arg);
	dl = (t_distant_light *)ll.light;
}

TEST_TEAR_DOWN(distant_light)
{
	ft_memdel((void **)&dl);
}

TEST(distant_light, get_dir)
{
	dir = ll.get_dir(NULL, ll.light);
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&dl->dir, &dir, sizeof(t_vec3), "get_dir");
}

TEST(distant_light, get_distance)
{
	distance = ll.get_distance(NULL, ll.light);
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(FAR, distance, "get_distance");
}

TEST_GROUP_RUNNER(distant_light)
{
	RUN_TEST_CASE(distant_light, get_dir);
	RUN_TEST_CASE(distant_light, get_distance);
}
