#include "rt.test.h"

static t_ol			ol;
static t_box		*box;
static int			res;
static t_arg_box	arg;
static t_vec3		normalized_a;
static t_vec3		normalized_b;
static t_vec3		c;
static t_vec3		vmax_expected;

TEST_GROUP(set_box);

TEST_SETUP(set_box)
{
	ol.object = ft_memalloc(sizeof(t_box));
	box = (t_box *)ol.object;
}

TEST_TEAR_DOWN(set_box)
{
	ft_memdel((void **)&box);
}

TEST(set_box, valid)
{
	arg.vmin = (t_vec3){0.0, 0.0, 0.0};
	arg.a = (t_vec3){2.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, 3.0, 1.0};
	arg.norm_c = 2.0;
	normalized_a = v3_normalise(arg.a);
	normalized_b = v3_normalise(arg.b);
	c = v3_cross(normalized_a, normalized_b);
	vmax_expected.x = v3_norm(arg.a);
	vmax_expected.y = v3_norm(arg.b);
	vmax_expected.z = arg.norm_c;

	res = set_box(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&arg.vmin, &box->vmin, sizeof(t_vec3), "vmin");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&vmax_expected, &box->vmax, sizeof(t_vec3), "vmax");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(
		&normalized_a, box->axis_mat.arr[0], sizeof(t_vec3), "axis_mat.arr[0]");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(
		&normalized_b, box->axis_mat.arr[1], sizeof(t_vec3), "axis_mat.arr[1]");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(
		&c, box->axis_mat.arr[2], sizeof(t_vec3), "axis_mat.arr[2]");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&v_intersect_box, ol.intersect, "intersect");
	TEST_ASSERT_EQUAL_INT_MESSAGE(&normal_box, ol.get_normal, "get_normal");
}

TEST(set_box, a_norm_is_0)
{
	arg.vmin = (t_vec3){0.0, 0.0, 0.0};
	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, 3.0, 1.0};
	arg.norm_c = 2.0;

	res = set_box(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_box, b_norm_is_0)
{
	arg.vmin = (t_vec3){0.0, 0.0, 0.0};
	arg.a = (t_vec3){2.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, 0.0, 0.0};
	arg.norm_c = 2.0;

	res = set_box(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_box, a_b_is_not_orthogonal)
{
	arg.vmin = (t_vec3){0.0, 0.0, 0.0};
	arg.a = (t_vec3){2.0, 0.0, 0.0};
	arg.b = (t_vec3){1.0, 0.0, 0.0};
	arg.norm_c = 2.0;

	res = set_box(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST(set_box, norm_c_is_0)
{
	arg.vmin = (t_vec3){0.0, 0.0, 0.0};
	arg.a = (t_vec3){2.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, 1.0, 0.0};
	arg.norm_c = 0.0;

	res = set_box(&ol, &arg);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, res, "res");
}

TEST_GROUP_RUNNER(set_box)
{
	RUN_TEST_CASE(set_box, valid);
	RUN_TEST_CASE(set_box, a_norm_is_0);
	RUN_TEST_CASE(set_box, b_norm_is_0);
	RUN_TEST_CASE(set_box, a_b_is_not_orthogonal);
	RUN_TEST_CASE(set_box, norm_c_is_0);
}
