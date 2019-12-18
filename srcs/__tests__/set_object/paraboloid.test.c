#include "rt.test.h"

static int					res;
static t_ol					ol;
static t_paraboloid			*paraboloid;
static t_arg_paraboloid		arg;
static t_vec3				normalized_axis;

TEST_GROUP(set_paraboloid);

TEST_SETUP(set_paraboloid)
{
	ol.object = ft_memalloc(sizeof(t_paraboloid));
	paraboloid = (t_paraboloid *)ol.object;
}

TEST_TEAR_DOWN(set_paraboloid)
{
	ft_memdel((void **)&paraboloid);
}

TEST(set_paraboloid, valid)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.8, -0.8};
	arg.k = 1.0;
	arg.min = 0.5;
	arg.max = 1.0;
	normalized_axis = v3_normalise(arg.axis);

	res = set_paraboloid(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&arg.cen, &paraboloid->cen, sizeof(t_vec3), "cen");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&normalized_axis, &paraboloid->axis, sizeof(t_vec3), "axis");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(arg.k, paraboloid->k, "k");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(arg.min, paraboloid->min, "min");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(arg.max, paraboloid->max, "max");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&v_intersect_paraboloid, ol.intersect, "intersect");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&normal_paraboloid, ol.get_normal, "get_normal");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&paraboloid_translate, ol.translate, "translate");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&paraboloid_rotate, ol.rotate, "rotate");
}

TEST(set_paraboloid, axis_length_0)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){0.0, 0.0, -0.0};
	arg.k = 1.0;
	arg.min = 0.5;
	arg.max = 1.0;

	res = set_paraboloid(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_paraboloid, k_0)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.8, -0.8};
	arg.k = 0.0;
	arg.min = 0.5;
	arg.max = 1.0;

	res = set_paraboloid(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_paraboloid, min_lt_0)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.8, -0.8};
	arg.k = 1.0;
	arg.min = -1.0;
	arg.max = 1.0;

	res = set_paraboloid(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_paraboloid, min_gt_max)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.8, -0.8};
	arg.k = 1.0;
	arg.min = 1.0;
	arg.max = 1.0;

	res = set_paraboloid(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST_GROUP_RUNNER(set_paraboloid)
{
	RUN_TEST_CASE(set_paraboloid, valid);
	RUN_TEST_CASE(set_paraboloid, axis_length_0);
	RUN_TEST_CASE(set_paraboloid, k_0);
	RUN_TEST_CASE(set_paraboloid, min_lt_0);
	RUN_TEST_CASE(set_paraboloid, min_gt_max);
}
