#include "rt.test.h"

// case success
void		test_set_pyramid_case1(void)
{
	printf(KYEL "test_set_pyramid_case1\n" KNRM);
	t_pyramid			pyramid;
	t_arg_pyramid		arg;
	t_vec3				normalized_u;
	t_vec3				normalized_v;

	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.u = (t_vec3){1.5, 0.0, 0.0};
	arg.v = (t_vec3){0.0, 0.7, -1.0};
	arg.height = 2.0;
	normalized_u = v3_normalise(arg.u);
	normalized_v = v3_normalise(arg.v);

	test(
		set_pyramid(&pyramid, &arg) == RT_SUCCESS,
		"set_pyramid : return value"
	);

	test(
		memcmp(&pyramid.u, &normalized_u, sizeof(t_vec3)) == 0,
		"set_pyramid : pyramid.u"
	);

	test(
		memcmp(&pyramid.v, &normalized_v, sizeof(t_vec3)) == 0,
		"set_pyramid : pyramid.v"
	);

	test(
		pyramid.norm_u = v3_norm(arg.u),
		"set_pyramid : pyramid.norm_u"
	);

	test(
		pyramid.norm_v = v3_norm(arg.v),
		"set_pyramid : pyramid.norm_v"
	);
}

// case u's norm is 0
void		test_set_pyramid_case2(void)
{
	printf(KYEL "test_set_pyramid_case2\n" KNRM);
	t_pyramid			pyramid;
	t_arg_pyramid		arg;

	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.u = (t_vec3){0.0, 0.0, 0.0};
	arg.v = (t_vec3){0.0, 0.7, -1.0};
	arg.height = 2.0;

	test(
		set_pyramid(&pyramid, &arg) == RT_FAIL,
		"set_pyramid : return value"
	);
}

// case v's norm is 0
void		test_set_pyramid_case3(void)
{
	printf(KYEL "test_set_pyramid_case3\n" KNRM);
	t_pyramid			pyramid;
	t_arg_pyramid		arg;

	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.u = (t_vec3){1.0, 0.0, 0.0};
	arg.v = (t_vec3){0.0, 0.0, 0.0};
	arg.height = 2.0;

	test(
		set_pyramid(&pyramid, &arg) == RT_FAIL,
		"set_pyramid : return value"
	);
}

// case u, v is not orthogonal
void		test_set_pyramid_case4(void)
{
	printf(KYEL "test_set_pyramid_case4\n" KNRM);
	t_pyramid			pyramid;
	t_arg_pyramid		arg;

	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.u = (t_vec3){1.0, 0.0, 0.0};
	arg.v = (t_vec3){1.0, 1.0, 0.0};
	arg.height = 2.0;

	test(
		set_pyramid(&pyramid, &arg) == RT_FAIL,
		"set_pyramid : return value"
	);
}

// case height <= 0
void		test_set_pyramid_case5(void)
{
	printf(KYEL "test_set_pyramid_case5\n" KNRM);
	t_pyramid			pyramid;
	t_arg_pyramid		arg;

	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.u = (t_vec3){1.0, 0.0, 0.0};
	arg.v = (t_vec3){0.0, 1.0, 0.0};
	arg.height = 0.0;

	test(
		set_pyramid(&pyramid, &arg) == RT_FAIL,
		"set_pyramid : return value"
	);
}
