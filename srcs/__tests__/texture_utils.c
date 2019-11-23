#include "rt.test.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

static t_col			get_rgb(unsigned int value)
{
	t_col	rgb;

	rgb.r = value & 0x000000ff;
	value >>= 8;
	rgb.g = value & 0x000000ff;
	value >>= 8;
	rgb.b = value & 0x000000ff;
	return (rgb);
}

static unsigned int		get_uint32_color(t_col *rgb)
{
	unsigned int	color;

	color = 0;
	color += rgb->r;
	color <<= 8;
	color += rgb->g;
	color <<= 8;
	color += rgb->b;
	return (color);
}

void					set_texture(
	const char *texture_file_name,
	const char *repeat,
	t_texture *texture
)
{
	texture->pixels = (unsigned int *)stbi_load(
		texture_file_name, &texture->width, &texture->height,
		NULL, STBI_rgb_alpha);
	texture->repeat = atoi(repeat);
}

int						get_texture_pixel_color(
	t_vec2 *uv,
	t_texture *texture,
	double n_dot_l
)
{
	int		img_coord[2];
	int		index;
	t_col	rgb;

	img_coord[0] = uv->x * (texture->width - 1);
	img_coord[1] = uv->y * (texture->height - 1);

	index = img_coord[0] + img_coord[1] * texture->width;
	if (index < 0 || index >= texture->width * texture->height)
		return (0);
	rgb = get_rgb(texture->pixels[img_coord[0] + img_coord[1] * texture->width]);
	rgb.r *= MAX(0.0, n_dot_l);
	rgb.g *= MAX(0.0, n_dot_l);
	rgb.b *= MAX(0.0, n_dot_l);
	return (get_uint32_color(&rgb));
}
