#include "rt.test.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

static void	sphere_case1(t_ol *ol)
{
	t_sphere	*sphere;
	t_vec3		center;
	t_vec3		axis[3];
	double		radius;

    ol->intersect = &v_intersect_sp2;
    ol->get_normal = &normal_sphere;
    ol->uv_mapping = &sphere_uv_mapping;
    ol->object = ft_memalloc(sizeof(t_sphere));
	sphere = (t_sphere *)ol->object;
    center = (t_vec3){0.0, 0.0, 2.0};
    radius = 1.0;

	axis[0] = (t_vec3){0.0, 1.0, 0.0};
	axis[1] = (t_vec3){0.0, 0.0, 1.0};
	axis[2] = v3_cross(axis[0], axis[1]);
	ft_memcpy(&(ol->axis_mat.arr[0]), &(axis[0]), sizeof(t_vec3));
	ft_memcpy(&(ol->axis_mat.arr[1]), &(axis[1]), sizeof(t_vec3));
	ft_memcpy(&(ol->axis_mat.arr[2]), &(axis[2]), sizeof(t_vec3));

	test(
		set_sphere(sphere, center, radius) == RT_SUCCESS,
		"set_sphere : return value"
	);
}

void		test_sphere_texture_mapping_case1(void)
{
	t_mlxkit	mlxkit;
	t_camera	cam;
	t_ol		ol;
	const char	*texture_file_name = "./contents/Brick_image_texture.jpg";

	init_mlxkit(&mlxkit);
	cam.campos = (t_vec3){0.0, 0.0, -1.0};
	cam.camdir = (t_vec3){0.0, 0.0, 1.0};
	cam.left = (t_vec3){1.0, 0.0, 0.0};
	cam.up = (t_vec3){0.0, 1.0, 0.0};
	cam.forw = (t_vec3){0.0, 0.0, 1.0};
	cam.focal_length = 1.0;
	cam.f_wdth = WIDTH / 384;
	cam.f_hght = WIDTH / 384;

	sphere_case1(&ol);
	ol.texture.pixels = (unsigned int *)stbi_load(
		texture_file_name, &ol.texture.width, &ol.texture.height,
		NULL, STBI_rgb_alpha);
	printf("pixels has loaded\n");
	render_texture_mapping_test(&mlxkit, &cam, &ol);
}
