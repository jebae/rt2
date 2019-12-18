#include "rt.test.h"

static t_ol			ol;
static t_cone		*cone;
static int			res;
static t_arg_cone	arg;
static t_vec3		normalized_axis;
static t_mat3		axis_mat;

TEST_GROUP(set_cone);

TEST_SETUP(set_cone)
{
	ol.object = ft_memalloc(sizeof(t_cone));
	cone = (t_cone *)ol.object;
}

TEST_TEAR_DOWN(set_cone)
{
	ft_memdel((void **)&cone);
}

TEST(set_cone, valid)
{
	arg.cen = (t_vec3){1.0, 0.0, 0.0};
	arg.axis = (t_vec3){0.0, 1.0, 0.0};
	arg.angle = 30.0;
	arg.upper_height = 2.0;
	arg.lower_height = 1.0;
	normalized_axis = v3_normalise(arg.axis);
	axis_mat = (t_mat3){
		.arr = {
			{0.0, 0.0, -1.0},
			{0.0, 1.0, 0.0},
			{1.0, -0.0, 0.0}
		}
	};

	res = set_cone(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&arg.cen, &cone->cen, sizeof(t_vec3), "cen");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&normalized_axis, &cone->axis, sizeof(t_vec3), "axis");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(arg.angle, cone->angle, "angle");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(arg.lower_height, cone->lower_height, "lower_height");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(arg.upper_height, cone->upper_height, "upper_height");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&axis_mat, &ol.axis_mat, sizeof(t_mat3), "axis_mat");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&v_intersect_co, ol.intersect, "intersect");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&normal_cone, ol.get_normal, "get_normal");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&cone_uv_mapping, ol.uv_mapping, "uv_mapping");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&cone_translate, ol.translate, "translate");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&cone_rotate, ol.rotate, "rotate");
}

TEST(set_cone, axis_is_parallel_to_world_x_axis)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){-1.0, 0.0, 0.0};
	arg.angle = 30.0;
	arg.upper_height = 2.0;
	arg.lower_height = 1.0;
	normalized_axis = v3_normalise(arg.axis);
	axis_mat = (t_mat3){
		.arr = {
			{0.0, 0.0, -1.0},
			{-1.0, 0.0, 0.0},
			{0.0, 1.0, 0.0}
		}
	};

	res = set_cone(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&arg.cen, &cone->cen, sizeof(t_vec3), "cen");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&normalized_axis, &cone->axis, sizeof(t_vec3), "axis");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(arg.angle, cone->angle, "angle");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(arg.lower_height, cone->lower_height, "lower_height");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(arg.upper_height, cone->upper_height, "upper_height");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&axis_mat, &ol.axis_mat, sizeof(t_mat3), "axis_mat");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&v_intersect_co, ol.intersect, "intersect");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&normal_cone, ol.get_normal, "get_normal");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&cone_uv_mapping, ol.uv_mapping, "uv_mapping");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&cone_translate, ol.translate, "translate");
}

TEST(set_cone, axis_norm_is_0)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){0.0, -0.0, 0.0};
	arg.angle = 30.0;
	arg.upper_height = 2.0;
	arg.lower_height = 1.0;

	res = set_cone(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_cone, angle_is_0)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.9, 0.7};
	arg.angle = 0.0;
	arg.upper_height = 2.0;
	arg.lower_height = 1.0;


	res = set_cone(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_cone, angle_smaller_than_0)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.9, 0.7};
	arg.angle = -20.0;
	arg.upper_height = 2.0;
	arg.lower_height = 1.0;


	res = set_cone(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_cone, angle_bigger_than_90)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.9, 0.7};
	arg.angle = 90.0;
	arg.upper_height = 2.0;
	arg.lower_height = 1.0;


	res = set_cone(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_cone, upper_height_is_negative)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.9, 0.7};
	arg.angle = 30.0;
	arg.upper_height = -2.0;
	arg.lower_height = 1.0;

	res = set_cone(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_cone, lower_height_is_negative)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.9, 0.7};
	arg.angle = 30.0;
	arg.upper_height = 2.0;
	arg.lower_height = -1.0;

	res = set_cone(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_cone, both_of_height_is_0)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.9, 0.7};
	arg.angle = 30.0;
	arg.upper_height = 0.0;
	arg.lower_height = 0.0;

	res = set_cone(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_cone, one_of_height_is_not_0_case1)
{
	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.9, 0.7};
	arg.angle = 30.0;
	arg.upper_height = 1.0;
	arg.lower_height = 0.0;

	res = set_cone(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
}

TEST_GROUP_RUNNER(set_cone)
{
	RUN_TEST_CASE(set_cone, valid);
	RUN_TEST_CASE(set_cone, axis_norm_is_0);
	RUN_TEST_CASE(set_cone, angle_is_0);
	RUN_TEST_CASE(set_cone, angle_smaller_than_0);
	RUN_TEST_CASE(set_cone, angle_bigger_than_90);
	RUN_TEST_CASE(set_cone, axis_is_parallel_to_world_x_axis);
	RUN_TEST_CASE(set_cone, upper_height_is_negative);
	RUN_TEST_CASE(set_cone, lower_height_is_negative);
	RUN_TEST_CASE(set_cone, both_of_height_is_0);
	RUN_TEST_CASE(set_cone, one_of_height_is_not_0_case1);
}