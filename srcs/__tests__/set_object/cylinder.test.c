#include "rt.test.h"

// case success
void		test_set_cyl_case1(void)
{
	printf(KYEL "test_set_cyl_case1\n" KNRM);
	t_ol			ol;
	t_cyl			*cyl;
	t_arg_cyl		arg;
	t_vec3			normalized_axis;

	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.9, 0.7};
	arg.radius = 30.0;
	arg.height = 1.0;
	normalized_axis = v3_normalise(arg.axis);

	ol.object = ft_memalloc(sizeof(t_cyl));
	cyl = (t_cyl *)ol.object;

	test(
		set_cyl(&ol, &arg) == RT_SUCCESS,
		"set_cyl : return value"
	);

	test(
		memcmp(&cyl->cen, &arg.cen, sizeof(t_vec3)) == 0,
		"set_cyl : cen"
	);

	test(
		memcmp(&cyl->axis, &normalized_axis, sizeof(t_vec3)) == 0,
		"set_cyl : axis"
	);

	test(
		cyl->radius = arg.radius,
		"set_cyl : radius"
	);

	free(cyl);
}

// case radius <= 0
void		test_set_cyl_case2(void)
{
	printf(KYEL "test_set_cyl_case2\n" KNRM);
	t_ol			ol;
	t_arg_cyl		arg;

	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.9, 0.7};
	arg.radius = 0.0;

	test(
		set_cyl(&ol, &arg) == RT_FAIL,
		"set_cyl : return value"
	);
}

// case axis norm is 0
void		test_set_cyl_case3(void)
{
	printf(KYEL "test_set_cyl_case3\n" KNRM);
	t_ol			ol;
	t_arg_cyl		arg;

	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){0.0, 0.0, -0.0};
	arg.radius = 1.0;

	test(
		set_cyl(&ol, &arg) == RT_FAIL,
		"set_cyl : return value"
	);
}

// case height <= 0
void		test_set_cyl_case4(void)
{
	printf(KYEL "test_set_cyl_case4\n" KNRM);
	t_ol			ol;
	t_arg_cyl		arg;

	arg.cen = (t_vec3){0.0, 0.0, 0.0};
	arg.axis = (t_vec3){1.0, 0.9, 0.7};
	arg.radius = 30.0;
	arg.height = 0.0;

	test(
		set_cyl(&ol, &arg) == RT_FAIL,
		"set_cyl : return value"
	);
}
