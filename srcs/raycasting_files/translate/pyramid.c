#include "raycast.h"

void		pyramid_translate(t_vec3 *v_translate, void *object)
{
	int			i;
	t_pyramid	*pyramid;

	pyramid = (t_pyramid *)object;
	i = 0;
	while (i < 4)
	{
		pyramid->sides[i].a = v3_add(pyramid->sides[i].a, *v_translate);
		i++;
	}
}
