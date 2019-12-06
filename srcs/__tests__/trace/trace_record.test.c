#include "rt.test.h"

static t_trace_record	rec;
static t_ol				ol;
static t_sphere			*sphere;
static t_vec3			expected_point;
static t_vec3			expected_normal;
static t_vec3			expected_color;
static t_vec2			uv;

TEST_GROUP(set_trace_record);

TEST_SETUP(set_trace_record)
{
	t_arg_sphere	arg;

	init_ol(&ol);
    arg.cen = (t_vec3){0.0, 0.0, 2.0};
    arg.radius = 1.0;
	ol.object = ft_memalloc(sizeof(t_sphere));
	set_sphere(&ol, &arg);
	ol.dif = (t_vec3){255, 210, 42};
	sphere = (t_sphere *)ol.object;
	rec.obj = &ol;
	rec.ray.ori = (t_vec3){0.0, 0.0, 0.0};
	rec.ray.dir = (t_vec3){0.0, 0.0, 1.0};
	rec.ray.t = ol.intersect(rec.ray, sphere);
	expected_point = find_point_from_ray(rec.ray);
}

TEST_TEAR_DOWN(set_trace_record)
{
	ft_memdel((void **)&sphere);
	if (ol.texture.buffer != NULL)
		free(ol.texture.buffer);
	if (ol.bump_map.buffer != NULL)
		free(ol.bump_map.buffer);
}

TEST(set_trace_record, no_texture)
{
	expected_normal = rec.obj->get_normal(rec.ray, rec.obj->object);
	expected_color = rec.obj->dif;

	set_trace_record(&rec);
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected_point, &rec.point, sizeof(t_vec3), "rec.point");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected_normal, &rec.normal, sizeof(t_vec3), "rec.normal");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected_color, &rec.color, sizeof(t_vec3), "rec.color");
}

TEST(set_trace_record, has_texture)
{
	set_texels("./contents/earth.jpg", "1", &ol.texture);
	expected_normal = rec.obj->get_normal(rec.ray, rec.obj->object);
	uv = ol.uv_mapping(expected_point, &ol.axis_mat, &ol.texture, ol.object);
	expected_color = get_texel_color(&uv, &ol.texture);

	set_trace_record(&rec);
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected_point, &rec.point, sizeof(t_vec3), "rec.point");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected_normal, &rec.normal, sizeof(t_vec3), "rec.normal");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected_color, &rec.color, sizeof(t_vec3), "rec.color");
}

TEST(set_trace_record, has_bump_map)
{
	set_texels("./contents/water_bump.jpg", "1", &ol.bump_map);
	expected_color = rec.obj->dif;
	expected_normal = rec.obj->get_normal(rec.ray, rec.obj->object);
	uv = ol.uv_mapping(expected_point, &ol.axis_mat, &ol.bump_map, ol.object);
	expected_normal = get_bumped_normal(&uv, &ol.bump_map, &expected_normal, &ol.axis_mat);

	set_trace_record(&rec);
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected_point, &rec.point, sizeof(t_vec3), "rec.point");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected_normal, &rec.normal, sizeof(t_vec3), "rec.normal");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected_color, &rec.color, sizeof(t_vec3), "rec.color");
}

TEST(set_trace_record, has_texture_and_bump_map)
{
	set_texels("./contents/earth.jpg", "1", &ol.texture);
	set_texels("./contents/water_bump.jpg", "2", &ol.bump_map);

	// texture
	uv = ol.uv_mapping(expected_point, &ol.axis_mat, &ol.texture, ol.object);
	expected_color = get_texel_color(&uv, &ol.texture);

	// bump_map
	expected_normal = rec.obj->get_normal(rec.ray, rec.obj->object);
	uv = ol.uv_mapping(expected_point, &ol.axis_mat, &ol.bump_map, ol.object);
	expected_normal = get_bumped_normal(&uv, &ol.bump_map, &expected_normal, &ol.axis_mat);

	set_trace_record(&rec);
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected_point, &rec.point, sizeof(t_vec3), "rec.point");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected_normal, &rec.normal, sizeof(t_vec3), "rec.normal");
	TEST_ASSERT_EQUAL_MEMORY_MESSAGE(&expected_color, &rec.color, sizeof(t_vec3), "rec.color");
}

TEST_GROUP_RUNNER(set_trace_record)
{
	RUN_TEST_CASE(set_trace_record, no_texture);
	RUN_TEST_CASE(set_trace_record, has_texture);
	RUN_TEST_CASE(set_trace_record, has_bump_map);
	RUN_TEST_CASE(set_trace_record, has_texture_and_bump_map);
}
