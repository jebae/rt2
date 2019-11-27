#include "raycast.h"

static void			adjust_color(t_col *rgb)
{
	if (rgb->r > 0xff)
		rgb->r = 0xff;
	if (rgb->g > 0xff)
		rgb->g = 0xff;
	if (rgb->b > 0xff)
		rgb->b = 0xff;
}

static void			filter_func(void *arg_void)
{
	int						i;
	int						until;
	t_col					rgb;
	t_col					temp;
	t_arg_filter_th_job		*arg;

	arg = (t_arg_filter_th_job *)arg_void;
	i = arg->offset;
	until = i + arg->work_size;
	while (i < until)
	{
		rgb = uint32_to_rgb(arg->buf[i]);
		temp = rgb;
		rgb.r = 0.393 * temp.r + 0.769 * temp.g + 0.189 * temp.b;
		rgb.g = 0.349 * temp.r + 0.686 * temp.g + 0.168 * temp.b;
		rgb.b = 0.272 * temp.r + 0.534 * temp.g + 0.131 * temp.b;
		adjust_color(&rgb);
		arg->buf[i] = rgb_to_uint32(&rgb);
		i++;
	}
}

int					sephia_filter(
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
