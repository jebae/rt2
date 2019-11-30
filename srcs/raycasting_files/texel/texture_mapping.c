#include "raycast.h"

t_col			get_texel_color(t_vec2 *uv, t_texels *texels)
{
	unsigned int	texel;

	texel = texels->buffer[uv_to_texel_index(uv, texels)];
	return (uint32_to_rgb(texel));
}
