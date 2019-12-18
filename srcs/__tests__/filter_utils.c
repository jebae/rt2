#include "rt.test.h"

void	set_filter(
	const char *filter,
	unsigned int *buffer,
	int width,
	int height
)
{
	if (strcmp(filter, "sephia") == 0)
		im_sephia(buffer, width, height);
	else if (strcmp(filter, "negative") == 0)
		im_negative(buffer, width, height);
	else if (strcmp(filter, "blur") == 0)
		im_gaussian_blur(buffer, width, height);
	else if (strcmp(filter, "gray") == 0)
		im_gray_scale(buffer, width, height);
}
