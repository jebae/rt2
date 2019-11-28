#include "rt.test.h"

static t_ol				ol;
static t_pyramid		*pyramid;
static int				res;
static t_arg_pyramid	arg;
static t_vec3			normalized_u;
static t_vec3			normalized_v;

TEST_GROUP(set_pyramid);

TEST_SETUP(set_pyramid)
{
	ol.object = ft_memalloc(sizeof(t_pyramid));
	pyramid = (t_pyramid *)ol.object;
}

TEST_TEAR_DOWN(set_pyramid)
{
	ft_memdel((void **)&pyramid);
}

TEST(set_pyramid, valid)
{
	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.u = (t_vec3){1.5, 0.0, 0.0};
	arg.v = (t_vec3){0.0, 0.7, -1.0};
	arg.height = 2.0;
	normalized_u = v3_normalise(arg.u);
	normalized_v = v3_normalise(arg.v);

	res = set_pyramid(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&normalized_u, &pyramid->u, sizeof(t_vec3), "u");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&normalized_v, &pyramid->v, sizeof(t_vec3), "v");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(v3_norm(arg.u), pyramid->norm_u, "norm_u");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(v3_norm(arg.v), pyramid->norm_v, "norm_v");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&v_intersect_pyramid, ol.intersect, "intersect");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&normal_pyramid, ol.get_normal, "get_normal");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&pyramid_translate, ol.translate, "translate");
}

TEST(set_pyramid, u_norm_is_0)
{
	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.u = (t_vec3){0.0, 0.0, 0.0};
	arg.v = (t_vec3){0.0, 0.7, -1.0};
	arg.height = 2.0;

	res = set_pyramid(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_pyramid, v_norm_is_0)
{
	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.u = (t_vec3){1.0, 0.0, 0.0};
	arg.v = (t_vec3){0.0, 0.0, 0.0};
	arg.height = 2.0;

	res = set_pyramid(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_pyramid, u_v_is_not_orthogonal)
{
	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.u = (t_vec3){1.0, 0.0, 0.0};
	arg.v = (t_vec3){1.0, 1.0, 0.0};
	arg.height = 2.0;

	res = set_pyramid(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_pyramid, height_lte_0)
{
	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.u = (t_vec3){1.0, 0.0, 0.0};
	arg.v = (t_vec3){0.0, 1.0, 0.0};
	arg.height = 0.0;

	res = set_pyramid(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST_GROUP_RUNNER(set_pyramid)
{
	RUN_TEST_CASE(set_pyramid, valid);
	RUN_TEST_CASE(set_pyramid, u_norm_is_0);
	RUN_TEST_CASE(set_pyramid, v_norm_is_0);
	RUN_TEST_CASE(set_pyramid, u_v_is_not_orthogonal);
	RUN_TEST_CASE(set_pyramid, height_lte_0);
}
