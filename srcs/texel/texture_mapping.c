#include "rt.h"

t_vec3			get_texel_color(t_vec2 *uv, t_texels *texels)
{
	unsigned int	texel;
	t_vec3			color;

	texel = texels->buffer[uv_to_texel_index(uv, texels)];
	color.x = texel & 0x000000ff;
	texel >>= 8;
	color.y = texel & 0x000000ff;
	texel >>= 8;
	color.z = texel & 0x000000ff;
	return (color);
}
