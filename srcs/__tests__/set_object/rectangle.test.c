#include "rt.test.h"

// case success
void		test_set_rectangle_case1(void)
{
	printf(KYEL "test_set_rectangle_case1\n" KNRM);
	t_ol				ol;
	t_rectangle			*rect;
	t_arg_rectangle		arg;
	t_vec3				normalized_a;
	t_vec3				normalized_b;
	t_vec3				normal;

	ol.object = ft_memalloc(sizeof(t_rectangle));
	rect = (t_rectangle *)ol.object;

	arg.p = (t_vec3){0.0, 0.0, 0.0};
	arg.a = (t_vec3){2.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, 2.0, 3.0};

	normalized_a = v3_normalise(arg.a);
	normalized_b = v3_normalise(arg.b);
	normal = v3_cross(normalized_b, normalized_a);

	test(
		set_rectangle(&ol, &arg) == RT_SUCCESS,
		"set_rectangle : return value"
	);

	test(
		memcmp(&rect->p, &arg.p, sizeof(t_vec3)) == 0,
		"set_rectangle : p"
	);

	test(
		memcmp(&rect->a, &normalized_a, sizeof(t_vec3)) == 0,
		"set_rectangle : a"
	);

	test(
		memcmp(&rect->b, &normalized_b, sizeof(t_vec3)) == 0,
		"set_rectangle : b"
	);

	test(
		memcmp(&rect->normal, &normal, sizeof(t_vec3)) == 0,
		"set_rectangle : normal"
	);

	test(
		rect->norm_a = v3_norm(arg.a),
		"set_rectangle : norm_a"
	);

	test(
		rect->norm_b = v3_norm(arg.b),
		"set_rectangle : norm_b"
	);

	test(
		rect->d == v3_dotpdt(arg.p, normal),
		"set_rectangle : d"
	);

	free(rect);
}

// case a's norm == 0
void		test_set_rectangle_case2(void)
{
	printf(KYEL "test_set_rectangle_case2\n" KNRM);
	t_ol				ol;
	t_arg_rectangle		arg;

	arg.p = (t_vec3){0.0, 0.0, 0.0};
	arg.a = (t_vec3){0.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, 2.0, 3.0};

	test(
		set_rectangle(&ol, &arg) == RT_FAIL,
		"set_rectangle : return value"
	);
}

// case b's norm == 0
void		test_set_rectangle_case3(void)
{
	printf(KYEL "test_set_rectangle_case3\n" KNRM);
	t_ol				ol;
	t_arg_rectangle		arg;

	arg.p = (t_vec3){0.0, 0.0, 0.0};
	arg.a = (t_vec3){2.0, 0.0, 0.0};
	arg.b = (t_vec3){0.0, 0.0, -0.0};

	test(
		set_rectangle(&ol, &arg) == RT_FAIL,
		"set_rectangle : return value"
	);
}

// case a and b is not orthogonal
void		test_set_rectangle_case4(void)
{
	printf(KYEL "test_set_rectangle_case4\n" KNRM);
	t_ol				ol;
	t_arg_rectangle		arg;

	arg.p = (t_vec3){0.0, 0.0, 0.0};
	arg.a = (t_vec3){2.0, 0.0, 0.0};
	arg.b = (t_vec3){1.0, 2.0, -0.0};

	test(
		set_rectangle(&ol, &arg) == RT_FAIL,
		"set_rectangle : return value"
	);
}
