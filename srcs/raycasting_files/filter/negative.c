#include "raycast.h"

static void			filter(void *arg_void)
{
	int						i;
	t_col					rgb;
	unsigned int			*buf;
	t_arg_buffer_th_job		*arg;

	arg = (t_arg_buffer_th_job *)arg_void;
	buf = (unsigned int *)arg->buf[0] + arg->offset;
	i = 0;
	while (i < arg->work_size)
	{
		rgb = uint32_to_rgb(buf[i]);
		rgb.r = 0xff - rgb.r;
		rgb.g = 0xff - rgb.g;
		rgb.b = 0xff - rgb.b;
		buf[i] = rgb_to_uint32(&rgb);
		i++;
	}
}

int					negative_filter(
	unsigned int *buffer,
	int width,
	int height
)
{
	t_buffer_info	buf_info;

	buf_info.buf[0] = (void *)buffer;
	buf_info.buf[1] = NULL;
	set_buffer_info(width, height, &buf_info);
	return (for_each_pixel(&buf_info, (void *)&filter));
}
