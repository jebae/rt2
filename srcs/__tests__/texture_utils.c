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

void					set_texels(
	const char *filename,
	const char *repeat,
	t_texels *texels
)
{
	texels->buffer = (unsigned int *)stbi_load(
		filename, &texels->width, &texels->height,
		NULL, STBI_rgb_alpha);
	texels->repeat = atoi(repeat);
}

int						get_texel_color(
	t_vec2 *uv,
	t_texels *texels,
	double n_dot_l
)
{
	int		img_coord[2];
	int		index;
	t_col	rgb;

	img_coord[0] = uv->x * (texels->width - 1);
	img_coord[1] = uv->y * (texels->height - 1);

	index = img_coord[0] + img_coord[1] * texels->width;
	if (index < 0 || index >= texels->width * texels->height)
		return (0);
	rgb = get_rgb(texels->buffer[index]);
	rgb.r *= MAX(0.0, n_dot_l);
	rgb.g *= MAX(0.0, n_dot_l);
	rgb.b *= MAX(0.0, n_dot_l);
	return (get_uint32_color(&rgb));
}
