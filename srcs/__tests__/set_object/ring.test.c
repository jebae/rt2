#include "rt.test.h"

static t_ol				ol;
static t_ring			*ring;
static int				res;
static t_arg_ring		arg;
static t_vec3			normal_expected;

TEST_GROUP(set_ring);

TEST_SETUP(set_ring)
{
	ol.object = ft_memalloc(sizeof(t_ring));
	ring = (t_ring *)ol.object;
}

TEST_TEAR_DOWN(set_ring)
{
	ft_memdel((void **)&ring);
}

TEST(set_ring, valid)
{
	arg.center = (t_vec3){0.0, 0.0, 0.0};
	arg.normal = (t_vec3){2.0, 1.0, 1.0};
	arg.r1 = 0.8;
	arg.r2 = 1.3;
	normal_expected = v3_normalise(arg.normal);

	res = set_ring(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&arg.center, &ring->center, sizeof(t_vec3), "center");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&normal_expected, &ring->normal, sizeof(t_vec3), "normal");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(arg.r1, ring->r1, "r1");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(arg.r2, ring->r2, "r2");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(v3_dotpdt(arg.center, normal_expected), ring->d, "d");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&v_intersect_ring, ol.intersect, "intersect");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&normal_ring, ol.get_normal, "get_normal");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&ring_translate, ol.translate, "translate");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&ring_translate, ol.rotate, "rotate");
}

TEST(set_ring, normal_norm_is_0)
{
	arg.center = (t_vec3){0.0, 0.0, 0.0};
	arg.normal = (t_vec3){0.0, 0.0, 0.0};
	arg.r1 = 0.8;
	arg.r2 = 1.3;

	res = set_ring(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_ring, r1_smaller_than_0)
{
	arg.center = (t_vec3){0.0, 0.0, 0.0};
	arg.normal = (t_vec3){1.0, 0.0, 0.0};
	arg.r1 = -0.9;
	arg.r2 = 1.3;

	res = set_ring(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_ring, r2_lte_0)
{
	arg.center = (t_vec3){0.0, 0.0, 0.0};
	arg.normal = (t_vec3){1.0, 0.0, 0.0};
	arg.r1 = 0.0;
	arg.r2 = 0.0;

	res = set_ring(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_ring, r1_gte_r2)
{
	arg.center = (t_vec3){0.0, 0.0, 0.0};
	arg.normal = (t_vec3){1.0, 0.0, 0.0};
	arg.r1 = 1.0;
	arg.r2 = 1.0;

	res = set_ring(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST_GROUP_RUNNER(set_ring)
{
	RUN_TEST_CASE(set_ring, valid);
	RUN_TEST_CASE(set_ring, normal_norm_is_0);
	RUN_TEST_CASE(set_ring, r1_smaller_than_0);
	RUN_TEST_CASE(set_ring, r2_lte_0);
	RUN_TEST_CASE(set_ring, r1_gte_r2);
}
