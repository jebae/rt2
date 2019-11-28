#include "rt.test.h"

void	set_filter(
	const char *filter,
	unsigned int *buffer,
	int width,
	int height
)
{
	if (strcmp(filter, "sephia") == 0)
		sephia_filter(buffer, width, height);
	else if (strcmp(filter, "negative") == 0)
		negative_filter(buffer, width, height);
	else if (strcmp(filter, "blur") == 0)
		gaussian_blur_filter(buffer, width, height);
}
