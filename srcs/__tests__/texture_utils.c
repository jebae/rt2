#include "rt.test.h"
#include "stb_image.h"

void		set_texels(
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
