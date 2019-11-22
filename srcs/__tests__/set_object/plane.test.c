#include "rt.test.h"

static t_ol			ol;
static t_plane		*plane;
static int			res;
static t_vec3		normal;
static double		d;
static t_vec3		normalized_normal;

TEST_GROUP(set_plane);

TEST_SETUP(set_plane)
{
	ol.object = ft_memalloc(sizeof(t_plane));
	plane = (t_plane *)ol.object;
}

TEST_TEAR_DOWN(set_plane)
{
	ft_memdel((void **)&plane);
}

TEST(set_plane, valid)
{
	normal = (t_vec3){1.0, 23.0, -0.7};
	d = 1.0;
	normalized_normal = v3_normalise(normal);

	res = set_plane(&ol, normal, d);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&normalized_normal, &plane->normal, sizeof(t_vec3), "normal");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(d, plane->d, "d");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&v_intersect_pl, ol.intersect, "intersect");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&normal_plane, ol.get_normal, "get_normal");
}

TEST(set_plane, normal_norm_is_0)
{
	normal = (t_vec3){0.0, 0.0, -0.0};
	d = 1.0;

	res = set_plane(&ol, normal, d);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST_GROUP_RUNNER(set_plane)
{
	RUN_TEST_CASE(set_plane, valid);
	RUN_TEST_CASE(set_plane, normal_norm_is_0);
}
