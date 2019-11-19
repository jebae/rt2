#include "rt.test.h"

// case success
void		test_set_triangle_case1(void)
{
	printf(KYEL "test_set_triangle_case1\n" KNRM);
	t_triangle			triangle;
	t_arg_triangle		arg;
	t_vec3				normal_expected;

	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.ab = (t_vec3){1.0, 2.0, -1.0};
	arg.ac = (t_vec3){0.0, -9.0, -3.0};
	normal_expected = v3_cross(arg.ab, arg.ac);
	normal_expected = v3_normalise(normal_expected);

	test(
		set_triangle(&triangle, &arg) == RT_SUCCESS,
		"set_triangle : return value"
	);

	test(
		memcmp(&triangle.a, &arg.a, sizeof(t_vec3)) == 0,
		"set_triangle : triangle.a"
	);

	test(
		memcmp(&triangle.ab, &arg.ab, sizeof(t_vec3)) == 0,
		"set_triangle : triangle.ab"
	);

	test(
		memcmp(&triangle.ac, &arg.ac, sizeof(t_vec3)) == 0,
		"set_triangle : triangle.ac"
	);

	test(
		memcmp(&triangle.normal, &normal_expected, sizeof(t_vec3)) == 0,
		"set_triangle : triangle.normal"
	);
}

// case ab's norm is 0
void		test_set_triangle_case2(void)
{
	printf(KYEL "test_set_triangle_case2\n" KNRM);
	t_triangle			triangle;
	t_arg_triangle		arg;

	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.ab = (t_vec3){0.0, 0.0, -0.0};
	arg.ac = (t_vec3){0.0, -9.0, -3.0};

	test(
		set_triangle(&triangle, &arg) == RT_FAIL,
		"set_triangle : return value"
	);
}

// case ac's norm is 0
void		test_set_triangle_case3(void)
{
	printf(KYEL "test_set_triangle_case3\n" KNRM);
	t_triangle			triangle;
	t_arg_triangle		arg;

	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.ab = (t_vec3){1.0, 0.0, -0.0};
	arg.ac = (t_vec3){0.0, -0.0, -0.0};

	test(
		set_triangle(&triangle, &arg) == RT_FAIL,
		"set_triangle : return value"
	);
}

// case ab and ac is parallel
void		test_set_triangle_case4(void)
{
	printf(KYEL "test_set_triangle_case4\n" KNRM);
	t_triangle			triangle;
	t_arg_triangle		arg;

	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.ab = (t_vec3){1.0, 2.0, 3.0};
	arg.ac = v3_scalar(arg.ab, -1.0);

	test(
		set_triangle(&triangle, &arg) == RT_FAIL,
		"set_triangle : return value"
	);
}
