#include "rt.test.h"

static t_ol				ol;
static t_rectangle		*rect;
static int				res;
static t_arg_rectangle	arg;
static t_vec3			normalized_a;
static t_vec3			normalized_b;
static t_vec3			normal;

TEST_GROUP(set_rectangle);

TEST_SETUP(set_rectangle)
{
	ol.object = ft_memalloc(sizeof(t_rectangle));
	rect = (t_rectangle *)ol.object;
}

TEST_TEAR_DOWN(set_rectangle)
{
	ft_memdel((void **)&rect);
}

TEST(set_rectangle, valid)
{
	arg.p = (t_vec3){0.0, 0.0, 0.0};
	arg.a = (t_vec3){2.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, 2.0, 3.0};
	normalized_a = v3_normalise(arg.a);
	normalized_b = v3_normalise(arg.b);
	normal = v3_cross(normalized_b, normalized_a);

	res = set_rectangle(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&arg.p, &rect->p, sizeof(t_vec3), "p");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&normalized_a, &rect->a, sizeof(t_vec3), "a");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&normalized_b, &rect->b, sizeof(t_vec3), "b");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&normal, &rect->normal, sizeof(t_vec3), "normal");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(v3_norm(arg.a), rect->norm_a, "norm_a");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(v3_norm(arg.b), rect->norm_b, "norm_b");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(v3_dotpdt(arg.p, normal), rect->d, "d");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&v_intersect_rectangle, ol.intersect, "intersect");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&normal_rectangle, ol.get_normal, "get_normal");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&rectangle_uv_mapping, ol.uv_mapping, "uv_mapping");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&rectangle_translate, ol.translate, "translate");
}

TEST(set_rectangle, a_norm_is_0)
{
	arg.p = (t_vec3){0.0, 0.0, 0.0};
	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, 2.0, 3.0};

	res = set_rectangle(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_rectangle, b_norm_is_0)
{
	arg.p = (t_vec3){0.0, 0.0, 0.0};
	arg.a = (t_vec3){2.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, 0.0, -0.0};

	res = set_rectangle(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_rectangle, a_b_is_not_orthogonal)
{
	arg.p = (t_vec3){0.0, 0.0, 0.0};
	arg.a = (t_vec3){2.0, 0.0, 0.0};
	arg.b = (t_vec3){1.0, 2.0, -0.0};

	res = set_rectangle(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST_GROUP_RUNNER(set_rectangle)
{
	RUN_TEST_CASE(set_rectangle, valid);
	RUN_TEST_CASE(set_rectangle, a_norm_is_0);
	RUN_TEST_CASE(set_rectangle, b_norm_is_0);
	RUN_TEST_CASE(set_rectangle, a_b_is_not_orthogonal);
}
