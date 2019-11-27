#include "raycast.h"

static void			filter_func(void *arg_void)
{
	int						i;
	int						until;
	t_col					rgb;
	t_arg_filter_th_job		*arg;

	arg = (t_arg_filter_th_job *)arg_void;
	i = arg->offset;
	until = i + arg->work_size;
	while (i < until)
	{
		rgb = uint32_to_rgb(arg->buf[i]);
		rgb.r = 0xff - rgb.r;
		rgb.g = 0xff - rgb.g;
		rgb.b = 0xff - rgb.b;
		arg->buf[i] = rgb_to_uint32(&rgb);
		i++;
	}
}

int					negative_filter(
	unsigned int *buffer,
	int width,
	int height
)
{
	t_filter_buffer_info	buf_info;

	buf_info.buf_copy = NULL;
	set_filter_buf_info(buffer, width, height, &buf_info);
	return (filter_color(&buf_info, &filter_func));
}
