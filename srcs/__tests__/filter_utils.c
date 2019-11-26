#include "rt.test.h"

void	set_filter(
	const char *filter,
	unsigned int *buffer,
	int width,
	int height
)
{
	if (strcmp(filter, "sephia") == 0)
		filter_color(buffer, width, height, &sephia_filter);
	else if (strcmp(filter, "negative") == 0)
		filter_color(buffer, width, height, &negative_filter);
}
