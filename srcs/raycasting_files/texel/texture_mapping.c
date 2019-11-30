#include "raycast.h"

t_col			get_texel_color(t_vec2 *uv, t_texels *texels)
{
	unsigned int	texel;
	t_col			color;

	texel = texels->buffer[uv_to_texel_index(uv, texels)];
	color.r = texel & 0x000000ff;
	texel >>= 8;
	color.g = texel & 0x000000ff;
	texel >>= 8;
	color.b = texel & 0x000000ff;
	return (color);
}
