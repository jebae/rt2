#include "rt.test.h"

// case success
void		test_set_ring_case1(void)
{
	printf(KYEL "test_set_ring_case1\n" KNRM);
	t_ring			ring;
	t_arg_ring		arg;
	t_vec3			normal_expected;

	arg.center = (t_vec3){0.0, 0.0, 0.0};
	arg.normal = (t_vec3){2.0, 1.0, 1.0};
	arg.r1 = 0.8;
	arg.r2 = 1.3;

	normal_expected = v3_normalise(arg.normal);

	test(
		set_ring(&ring, &arg) == RT_SUCCESS,
		"set_ring : return value"
	);

	test(
		memcmp(&ring.center, &arg.center, sizeof(t_vec3)) == 0,
		"set_ring : ring.center"
	);

	test(
		memcmp(&ring.normal, &normal_expected, sizeof(t_vec3)) == 0,
		"set_ring : ring.normal"
	);

	test(
		ring.r1 == arg.r1,
		"set_ring : ring.r1"
	);

	test(
		ring.r2 == arg.r2,
		"set_ring : ring.r2"
	);

	test(
		ring.d == v3_dotpdt(arg.center, normal_expected),
		"set_ring : ring.d"
	);
}

// case normal's norm is 0
void		test_set_ring_case2(void)
{
	printf(KYEL "test_set_ring_case2\n" KNRM);
	t_ring			ring;
	t_arg_ring		arg;

	arg.center = (t_vec3){0.0, 0.0, 0.0};
	arg.normal = (t_vec3){0.0, 0.0, 0.0};
	arg.r1 = 0.8;
	arg.r2 = 1.3;

	test(
		set_ring(&ring, &arg) == RT_FAIL,
		"set_ring : return value"
	);
}

// case r1 smaller than 0
void		test_set_ring_case3(void)
{
	printf(KYEL "test_set_ring_case3\n" KNRM);
	t_ring			ring;
	t_arg_ring		arg;

	arg.center = (t_vec3){0.0, 0.0, 0.0};
	arg.normal = (t_vec3){1.0, 0.0, 0.0};
	arg.r1 = -0.9;
	arg.r2 = 1.3;

	test(
		set_ring(&ring, &arg) == RT_FAIL,
		"set_ring : return value"
	);
}

// case r2 <= 0
void		test_set_ring_case4(void)
{
	printf(KYEL "test_set_ring_case4\n" KNRM);
	t_ring			ring;
	t_arg_ring		arg;

	arg.center = (t_vec3){0.0, 0.0, 0.0};
	arg.normal = (t_vec3){1.0, 0.0, 0.0};
	arg.r1 = 0.0;
	arg.r2 = 0.0;

	test(
		set_ring(&ring, &arg) == RT_FAIL,
		"set_ring : return value"
	);
}

// case r1 >= r2
void		test_set_ring_case5(void)
{
	printf(KYEL "test_set_ring_case5\n" KNRM);
	t_ring			ring;
	t_arg_ring		arg;

	arg.center = (t_vec3){0.0, 0.0, 0.0};
	arg.normal = (t_vec3){1.0, 0.0, 0.0};
	arg.r1 = 1.0;
	arg.r2 = 1.0;

	test(
		set_ring(&ring, &arg) == RT_FAIL,
		"set_ring : return value"
	);
}
