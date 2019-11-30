#include "rt.test.h"

static t_ol			ol;
static t_sphere		*sphere;
static int			res;
static t_arg_sphere	arg;
static t_mat3		axis_mat;

TEST_GROUP(set_sphere);

TEST_SETUP(set_sphere)
{
	ol.object = ft_memalloc(sizeof(t_sphere));
	sphere = (t_sphere *)ol.object;
}

TEST_TEAR_DOWN(set_sphere)
{
	ft_memdel((void **)&sphere);
}

TEST(set_sphere, valid)
{
	arg.cen = (t_vec3){1.0, 0.0, 0.0};
	arg.radius = 1.0;
	axis_mat = (t_mat3){
		.arr = {
			{-1.0, 0.0, 0.0},
			{0.0, -1.0, 0.0},
			{0.0, 0.0, -1.0}
		}
	};

	res = set_sphere(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&arg.cen, &sphere->cen, sizeof(t_vec3), "cen");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(arg.radius, sphere->radius, "radius");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&axis_mat, &ol.axis_mat, sizeof(t_mat3), "axis_mat");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&v_intersect_sp2, ol.intersect, "intersect");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&normal_sphere, ol.get_normal, "get_normal");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&sphere_uv_mapping, ol.uv_mapping, "uv_mapping");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&sphere_translate, ol.translate, "translate");
}

TEST(set_sphere, radius_is_0)
{
	arg.cen = (t_vec3){1.0, 0.0, 0.0};
	arg.radius = 0.0;

	res = set_sphere(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST_GROUP_RUNNER(set_sphere)
{
	RUN_TEST_CASE(set_sphere, valid);
	RUN_TEST_CASE(set_sphere, radius_is_0);
}
