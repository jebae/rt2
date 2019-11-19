#include "rt.test.h"

// case success
void		test_set_plane_case1(void)
{
	printf(KYEL "test_set_plane_case1\n" KNRM);
	t_plane			plane;
	t_vec3			normal = (t_vec3){1.0, 23.0, -0.7};
	double			d = 1.0;
	t_vec3			normalized_normal;

	normalized_normal = v3_normalise(normal);

	test(
		set_plane(&plane, normal, d) == RT_SUCCESS,
		"set_plane : return value"
	);

	test(
		memcmp(&plane.normal, &normalized_normal, sizeof(t_vec3)) == 0,
		"set_plane : plane.normal"
	);

	test(
		plane.d == d,
		"set_plane : plane.d"
	);
}

// case normal's norm is 0
void		test_set_plane_case2(void)
{
	printf(KYEL "test_set_plane_case2\n" KNRM);
	t_plane			plane;
	t_vec3			normal = (t_vec3){0.0, 0.0, -0.0};
	double			d = 1.0;

	test(
		set_plane(&plane, normal, d) == RT_FAIL,
		"set_plane : return value"
	);
}
