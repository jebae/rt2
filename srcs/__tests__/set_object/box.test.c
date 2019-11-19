#include "rt.test.h"

// case success
void		test_set_box_case1(void)
{
	printf(KYEL "test_set_box_case1\n" KNRM);
	t_box			box;
	t_arg_box		arg;
	t_vec3			normalized_a;
	t_vec3			normalized_b;
	t_vec3			c;
	t_vec3			vmax_expected;

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

	test(
		set_box(&box, &arg) == RT_SUCCESS,
		"set_box : return value"
	);

	test(
		memcmp(&box.vmin, &arg.vmin, sizeof(t_vec3)) == 0,
		"set_box : box.vmin"
	);

	test(
		memcmp(&box.vmax, &vmax_expected, sizeof(t_vec3)) == 0,
		"set_box : box.vmax"
	);

	test(
		memcmp(&(box.mat.arr[0]), &normalized_a, sizeof(t_vec3)) == 0,
		"set_box : box.mat.arr[0]"
	);

	test(
		memcmp(&(box.mat.arr[1]), &normalized_b, sizeof(t_vec3)) == 0,
		"set_box : box.mat.arr[1]"
	);

	test(
		memcmp(&(box.mat.arr[2]), &c, sizeof(t_vec3)) == 0,
		"set_box : box.mat.arr[2]"
	);
}

// case a's norm is 0
void		test_set_box_case2(void)
{
	printf(KYEL "test_set_box_case2\n" KNRM);
	t_box			box;
	t_arg_box		arg;

	arg.vmin = (t_vec3){0.0, 0.0, 0.0};
	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, 3.0, 1.0};
	arg.norm_c = 2.0;

	test(
		set_box(&box, &arg) == RT_FAIL,
		"set_box : return value"
	);
}

// case b's norm is 0
void		test_set_box_case3(void)
{
	printf(KYEL "test_set_box_case3\n" KNRM);
	t_box			box;
	t_arg_box		arg;

	arg.vmin = (t_vec3){0.0, 0.0, 0.0};
	arg.a = (t_vec3){2.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, 0.0, 0.0};
	arg.norm_c = 2.0;

	test(
		set_box(&box, &arg) == RT_FAIL,
		"set_box : return value"
	);
}

// case a, b is not orthogonal
void		test_set_box_case4(void)
{
	printf(KYEL "test_set_box_case4\n" KNRM);
	t_box			box;
	t_arg_box		arg;

	arg.vmin = (t_vec3){0.0, 0.0, 0.0};
	arg.a = (t_vec3){2.0, 0.0, 0.0};
	arg.b = (t_vec3){1.0, 0.0, 0.0};
	arg.norm_c = 2.0;

	test(
		set_box(&box, &arg) == RT_FAIL,
		"set_box : return value"
	);
}

// case norm_c <= 0
void		test_set_box_case5(void)
{
	printf(KYEL "test_set_box_case5\n" KNRM);
	t_box			box;
	t_arg_box		arg;

	arg.vmin = (t_vec3){0.0, 0.0, 0.0};
	arg.a = (t_vec3){2.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, 1.0, 0.0};
	arg.norm_c = 0.0;

	test(
		set_box(&box, &arg) == RT_FAIL,
		"set_box : return value"
	);
}
