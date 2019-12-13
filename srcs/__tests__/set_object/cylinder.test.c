#include "rt.test.h"

static t_ol			ol;
static t_cyl		*cyl;
static int			res;
static t_arg_cyl	arg;
static t_vec3		normalized_axis;

TEST_GROUP(set_cyl);

TEST_SETUP(set_cyl)
{
	ol.object = ft_memalloc(sizeof(t_cyl));
	cyl = (t_cyl *)ol.object;
}

TEST_TEAR_DOWN(set_cyl)
{
	ft_memdel((void **)&cyl);
}

TEST(set_cyl, valid)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.9, 0.7};
	arg.radius = 30.0;
	arg.height = 1.0;
	normalized_axis = v3_normalise(arg.axis);

	res = set_cyl(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&arg.cen, &cyl->cen, sizeof(t_vec3), "cen");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&normalized_axis, &cyl->axis, sizeof(t_vec3), "axis");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(arg.radius, cyl->radius, "radius");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&v_intersect_cy, ol.intersect, "intersect");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&normal_cylinder, ol.get_normal, "get_normal");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&cyl_uv_mapping, ol.uv_mapping, "uv_mapping");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&cyl_translate, ol.translate, "translate");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&cyl_rotate, ol.rotate, "rotate");
}

TEST(set_cyl, radius_lte_0)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.9, 0.7};
	arg.radius = 0.0;
	arg.height = 1.0;

	res = set_cyl(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_cyl, axis_norm_is_0)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){0.0, 0.0, -0.0};
	arg.radius = 1.0;
	arg.height = 1.0;

	res = set_cyl(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_cyl, height_lte_0)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){0.0, 0.0, -0.0};
	arg.radius = 1.0;
	arg.height = 0.0;

	res = set_cyl(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST_GROUP_RUNNER(set_cyl)
{
	RUN_TEST_CASE(set_cyl, valid);
	RUN_TEST_CASE(set_cyl, radius_lte_0);
	RUN_TEST_CASE(set_cyl, axis_norm_is_0);
	RUN_TEST_CASE(set_cyl, height_lte_0);
}
