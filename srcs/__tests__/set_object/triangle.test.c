#include "rt.test.h"

static t_ol				ol;
static t_triangle		*triangle;
static int				res;
static t_arg_triangle	arg;
static t_vec3			normal_expected;

TEST_GROUP(set_triangle);

TEST_SETUP(set_triangle)
{
	ol.object = ft_memalloc(sizeof(t_triangle));
	triangle = (t_triangle *)ol.object;
}

TEST_TEAR_DOWN(set_triangle)
{
	ft_memdel((void **)&triangle);
}

TEST(set_triangle, valid)
{
	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.ab = (t_vec3){1.0, 2.0, -1.0};
	arg.ac = (t_vec3){0.0, -9.0, -3.0};
	normal_expected = v3_cross(arg.ab, arg.ac);
	normal_expected = v3_normalise(normal_expected);

	res = set_triangle(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&arg.a, &triangle->a, sizeof(t_vec3), "a");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&arg.ab, &triangle->ab, sizeof(t_vec3), "ab");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&arg.ac, &triangle->ac, sizeof(t_vec3), "ac");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&normal_expected, &triangle->normal, sizeof(t_vec3), "normal");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&v_intersect_triangle, ol.intersect, "intersect");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&normal_triangle, ol.get_normal, "get_normal");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&triangle_translate, ol.translate, "translate");
}

TEST(set_triangle, ab_norm_is_0)
{
	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.ab = (t_vec3){0.0, 0.0, -0.0};
	arg.ac = (t_vec3){0.0, -9.0, -3.0};

	res = set_triangle(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_triangle, ac_norm_is_0)
{
	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.ab = (t_vec3){1.0, 0.0, -0.0};
	arg.ac = (t_vec3){0.0, -0.0, -0.0};

	res = set_triangle(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_triangle, ab_ac_is_parallel)
{
	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.ab = (t_vec3){1.0, 2.0, 3.0};
	arg.ac = v3_scalar(arg.ab, -1.0);

	res = set_triangle(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST_GROUP_RUNNER(set_triangle)
{
	RUN_TEST_CASE(set_triangle, valid);
	RUN_TEST_CASE(set_triangle, ab_norm_is_0);
	RUN_TEST_CASE(set_triangle, ac_norm_is_0);
	RUN_TEST_CASE(set_triangle, ab_ac_is_parallel);
}
