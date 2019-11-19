#include "rt.test.h"

// case success
void		test_set_cone_case1(void)
{
	printf(KYEL "test_set_cone_case1\n" KNRM);
	t_cone			cone;
	t_arg_cone		arg;
	t_vec3			normalized_axis;

	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.9, 0.7};
	arg.angle = 30.0;
	normalized_axis = v3_normalise(arg.axis);

	test(
		set_cone(&cone, &arg) == RT_SUCCESS,
		"set_cone : return value"
	);

	test(
		memcmp(&cone.cen, &arg.cen, sizeof(t_vec3)) == 0,
		"set_cone : cone.cen"
	);

	test(
		memcmp(&cone.axis, &normalized_axis, sizeof(t_vec3)) == 0,
		"set_cone : cone.axis"
	);

	test(
		cone.angle = arg.angle,
		"set_cone : cone.angle"
	);
}

// case axis norm is 0
void		test_set_cone_case2(void)
{
	printf(KYEL "test_set_cone_case2\n" KNRM);
	t_cone			cone;
	t_arg_cone		arg;

	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){0.0, -0.0, 0.0};
	arg.angle = 30.0;

	test(
		set_cone(&cone, &arg) == RT_FAIL,
		"set_cone : return value"
	);
}

// case angle == 0
void		test_set_cone_case3(void)
{
	printf(KYEL "test_set_cone_case3\n" KNRM);
	t_cone			cone;
	t_arg_cone		arg;

	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.9, 0.7};
	arg.angle = 0.0;

	test(
		set_cone(&cone, &arg) == RT_FAIL,
		"set_cone : return value"
	);
}

// case angle < 0
void		test_set_cone_case4(void)
{
	printf(KYEL "test_set_cone_case4\n" KNRM);
	t_cone			cone;
	t_arg_cone		arg;

	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.9, 0.7};
	arg.angle = -20.0;

	test(
		set_cone(&cone, &arg) == RT_FAIL,
		"set_cone : return value"
	);
}

// case angle >= 90
void		test_set_cone_case5(void)
{
	printf(KYEL "test_set_cone_case5\n" KNRM);
	t_cone			cone;
	t_arg_cone		arg;

	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.9, 0.7};
	arg.angle = 90.0;

	test(
		set_cone(&cone, &arg) == RT_FAIL,
		"set_cone : return value"
	);
}
