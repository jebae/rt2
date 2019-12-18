#include "rt.test.h"

static int					res;
static t_ol					ol;
static t_ellipsoid			*ellipsoid;
static t_arg_ellipsoid		arg;
static t_vec3				normalized_axis;

TEST_GROUP(set_ellipsoid);

TEST_SETUP(set_ellipsoid)
{
	ol.object = ft_memalloc(sizeof(t_ellipsoid));
	ellipsoid = (t_ellipsoid *)ol.object;
}

TEST_TEAR_DOWN(set_ellipsoid)
{
	ft_memdel((void **)&ellipsoid);
}

TEST(set_ellipsoid, valid)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.8, -0.8};
	arg.d = 1.0;
	arg.sum = 1.5;
	normalized_axis = v3_normalise(arg.axis);

	res = set_ellipsoid(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&arg.cen, &ellipsoid->cen, sizeof(t_vec3), "cen");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&normalized_axis, &ellipsoid->axis, sizeof(t_vec3), "axis");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(arg.d, ellipsoid->d, "d");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(arg.sum, ellipsoid->sum, "sum");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&v_intersect_ellipsoid, ol.intersect, "intersect");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&normal_ellipsoid, ol.get_normal, "get_normal");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&ellipsoid_translate, ol.translate, "translate");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&ellipsoid_rotate, ol.rotate, "rotate");
}

TEST(set_ellipsoid, axis_length_0)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){0.0, 0.0, -0.0};
	arg.d = 1.0;
	arg.sum = 1.5;
	normalized_axis = v3_normalise(arg.axis);

	res = set_ellipsoid(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_ellipsoid, d_lt_0)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.8, -0.8};
	arg.d = -1.0;
	arg.sum = 1.5;
	normalized_axis = v3_normalise(arg.axis);

	res = set_ellipsoid(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_ellipsoid, sum_0)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.8, -0.8};
	arg.d = 1.0;
	arg.sum = 0.0;
	normalized_axis = v3_normalise(arg.axis);

	res = set_ellipsoid(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST_GROUP_RUNNER(set_ellipsoid)
{
	RUN_TEST_CASE(set_ellipsoid, valid);
	RUN_TEST_CASE(set_ellipsoid, axis_length_0);
	RUN_TEST_CASE(set_ellipsoid, d_lt_0);
	RUN_TEST_CASE(set_ellipsoid, sum_0);
}
