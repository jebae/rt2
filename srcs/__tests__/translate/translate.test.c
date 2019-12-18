#include "rt.test.h"

static t_ol		ol;
static t_vec3	expected;
static t_vec3	v_translate = (t_vec3){2.0, 1.0, -0.9};

TEST_GROUP(translate);

TEST_SETUP(translate) {}

TEST_TEAR_DOWN(translate)
{
	ft_memdel((void **)&ol.object);
}

TEST(translate, sphere)
{
	t_sphere	*sphere;

	setup_sphere("1", &ol);
	sphere = (t_sphere *)ol.object;
	expected = v3_add(sphere->cen, v_translate);
	ol.translate(&v_translate, ol.object);

	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected, &sphere->cen, sizeof(t_vec3), "sphere.cen");
}

TEST(translate, cone)
{
	t_cone	*cone;

	setup_cone("1", &ol);
	cone = (t_cone *)ol.object;
	expected = v3_add(cone->cen, v_translate);
	ol.translate(&v_translate, ol.object);

	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected, &cone->cen, sizeof(t_vec3), "cone.cen");
}

TEST(translate, cylinder)
{
	t_cyl	*cyl;

	setup_cylinder("1", &ol);
	cyl = (t_cyl *)ol.object;
	expected = v3_add(cyl->cen, v_translate);
	ol.translate(&v_translate, ol.object);

	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected, &cyl->cen, sizeof(t_vec3), "cylinder.cen");
}

TEST(translate, plane)
{
	t_plane	*plane;
	double	expected_d;

	setup_plane("1", &ol);
	plane = (t_plane *)ol.object;
	expected_d = v3_dotpdt(plane->normal, v_translate) + plane->d;
	ol.translate(&v_translate, ol.object);

	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(expected_d, plane->d, "plane.d");
}

TEST(translate, rectangle)
{
	t_rectangle		*rect;
	double			expected_d;

	setup_rectangle("1", &ol);
	rect = (t_rectangle *)ol.object;
	expected = v3_add(rect->p, v_translate);
	expected_d = v3_dotpdt(expected, rect->normal);
	ol.translate(&v_translate, ol.object);

	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected, &rect->p, sizeof(t_vec3), "rect.p");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(expected_d, rect->d, "rect.d");
}

TEST(translate, box)
{
	t_box		*box;

	setup_box("1", &ol);
	box = (t_box *)ol.object;
	expected = v3_add(box->vmin, v_translate);
	ol.translate(&v_translate, ol.object);

	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected, &box->vmin, sizeof(t_vec3), "box.vmin");
}

TEST(translate, triangle)
{
	t_triangle		*triangle;

	setup_triangle("1", &ol);
	triangle = (t_triangle *)ol.object;
	expected = v3_add(triangle->a, v_translate);
	ol.translate(&v_translate, ol.object);

	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected, &triangle->a, sizeof(t_vec3), "triangle.a");
}

TEST(translate, pyramid)
{
	t_pyramid		*pyramid;
	t_vec3			expected_a[4];

	setup_pyramid("1", &ol);
	pyramid = (t_pyramid *)ol.object;

	for (int i=0; i < 4; i++)
		expected_a[i] = v3_add(pyramid->sides[i].a, v_translate);
	ol.translate(&v_translate, ol.object);
	for (int i=0; i < 4; i++)
		TEST_ASSERT_EQUAL_MEMORY_MESSAGE(
			&(expected_a[i]), &pyramid->sides[i].a, sizeof(t_vec3), "pyramid.sides[i].a");
}

TEST(translate, ring)
{
	t_ring		*ring;
	double		expected_d;

	setup_ring("1", &ol);
	ring = (t_ring *)ol.object;
	expected = v3_add(ring->center, v_translate);
	expected_d = v3_dotpdt(expected, ring->normal);
	ol.translate(&v_translate, ol.object);

	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected, &ring->center, sizeof(t_vec3), "ring.center");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(expected_d, ring->d, "ring.d");
}

TEST_GROUP_RUNNER(translate)
{
	RUN_TEST_CASE(translate, sphere);
	RUN_TEST_CASE(translate, cone);
	RUN_TEST_CASE(translate, cylinder);
	RUN_TEST_CASE(translate, plane);
	RUN_TEST_CASE(translate, rectangle);
	RUN_TEST_CASE(translate, box);
	RUN_TEST_CASE(translate, triangle);
	RUN_TEST_CASE(translate, pyramid);
	RUN_TEST_CASE(translate, ring);
}
