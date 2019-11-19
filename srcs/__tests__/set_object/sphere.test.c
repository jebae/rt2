#include "rt.test.h"

// case success
void		test_set_sphere_case1(void)
{
	printf(KYEL "test_set_sphere_case1\n" KNRM);
	t_sphere		sphere;
	t_vec3			cen = (t_vec3){0.0, 0.0, 0.0};
	double			radius = 1.0;

	test(
		set_sphere(&sphere, cen, radius) == RT_SUCCESS,
		"set_sphere : return value"
	);

	test(
		memcmp(&sphere.cen, &cen, sizeof(t_vec3)) == 0,
		"set_sphere : sphere.cen"
	);

	test(
		sphere.radius == radius,
		"set_sphere : sphere.radius"
	);
}

// case radius == 0
void		test_set_sphere_case2(void)
{
	printf(KYEL "test_set_sphere_case2\n" KNRM);
	t_sphere		sphere;
	t_vec3			cen = (t_vec3){0.0, 0.0, 0.0};
	double			radius = 0.0;

	test(
		set_sphere(&sphere, cen, radius) == RT_FAIL,
		"set_sphere : return value"
	);
}
