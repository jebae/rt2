#include "rt.test.h"

TEST_GROUP(set_sphere);

t_ol			ol;
t_sphere		*sphere;
static t_vec3		cen;
static double		radius;
static t_mat3		axis_mat;

TEST_SETUP(set_sphere)
{
	ol.object = ft_memalloc(sizeof(t_sphere));
	sphere = (t_sphere *)ol.object;
}

TEST_TEAR_DOWN(set_sphere)
{
	ft_memdel((void **)&sphere);
}

TEST(set_sphere, valid)
{
	cen = (t_vec3){1.0, 0.0, 0.0};
	radius = 1.0;
	axis_mat = (t_mat3){
		.arr = {
			{-1.0, 0.0, 0.0},
			{0.0, -1.0, 0.0},
			{0.0, 0.0, -1.0}
		}
	};

	TEST_ASSERT_EQUAL_INT(RT_SUCCESS, set_sphere(&ol, cen, radius));
	TEST_ASSERT_EQUAL_MEMORY(&cen, &sphere->cen, sizeof(t_vec3));
	TEST_ASSERT_EQUAL_DOUBLE(radius, sphere->radius);
	TEST_ASSERT_EQUAL_MEMORY(&axis_mat, &ol.axis_mat, sizeof(t_mat3));
}

TEST(set_sphere, radius_is_0)
{
	cen = (t_vec3){1.0, 0.0, 0.0};
	radius = 0.0;

	TEST_ASSERT_EQUAL_INT(RT_FAIL, set_sphere(&ol, cen, radius));
}

TEST_GROUP_RUNNER(set_sphere)
{
	RUN_TEST_CASE(set_sphere, valid);
	RUN_TEST_CASE(set_sphere, radius_is_0);
}
