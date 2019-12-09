#include "rt.h"

/*
static unsigned int		average_hex(unsigned int *p, int width)
{
	unsigned int	hex;

	(void)width;
	hex = *p;
	hex = ((*p & 0x000000ff) + (*(p + 1) & 0x000000ff) +
		(*(p + width) & 0x000000ff) + (*(p + width + 1) & 0x000000ff)) / 4;
	hex += ((*p & 0x0000ff00) + (*(p + 1) & 0x0000ff00) +
		(*(p + width) & 0x0000ff00) + (*(p + width + 1) & 0x0000ff00)) / 4;
	hex += ((*p & 0x00ff0000) + (*(p + 1) & 0x00ff0000) +
		(*(p + width) & 0x00ff0000) + (*(p + width + 1) & 0x00ff0000)) / 4;
	return (hex);
}
*/

static void				average(void *arg_void)
{
	unsigned int	i;
	unsigned int	*after;
	unsigned int	*before;
	t_im_arg_th		*arg;

	arg = (t_im_arg_th *)arg_void;
	after = (unsigned int *)arg->buf[0] + arg->offset;
	before = (unsigned int *)arg->buf[1] + arg->offset * 4;
	i = 0;
	while (i < arg->worksize)
	{
		//after[i] = average_hex(before + (i % arg->width) * 2, arg->width * 2);
		after[i] = *(before + (i % arg->width) * 2);
		if (i % arg->width == arg->width - 1)
			before += arg->width * 4;
		i++;
	}
}

int						anti_aliasing(
	unsigned int *after,
	unsigned int *before,
	int width,
	int height
)
{
	t_im_buffer_info	buf_info;

	im_set_buffer_info(width, height, &buf_info);
	buf_info.buf[0] = (unsigned char *)after;
	buf_info.buf[1] = (unsigned char *)before;
	if (im_for_each_pixel(&buf_info, &average) == IM_FAIL)
		return (RT_FAIL); // need message
	return (RT_SUCCESS);
}
