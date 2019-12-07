#include "rt.h"

static void			adjust_color(t_col *rgb)
{
	if (rgb->r > 0xff)
		rgb->r = 0xff;
	if (rgb->g > 0xff)
		rgb->g = 0xff;
	if (rgb->b > 0xff)
		rgb->b = 0xff;
}

static void			filter(void *arg_void)
{
	int						i;
	t_col					rgb;
	t_col					temp;
	unsigned int			*buf;
	t_arg_buffer_th_job		*arg;

	arg = (t_arg_buffer_th_job *)arg_void;
	buf = (unsigned int *)arg->buf[0] + arg->offset;
	i = 0;
	while (i < arg->work_size)
	{
		rgb = uint32_to_rgb(buf[i]);
		temp = rgb;
		rgb.r = 0.393 * temp.r + 0.769 * temp.g + 0.189 * temp.b;
		rgb.g = 0.349 * temp.r + 0.686 * temp.g + 0.168 * temp.b;
		rgb.b = 0.272 * temp.r + 0.534 * temp.g + 0.131 * temp.b;
		adjust_color(&rgb);
		buf[i] = rgb_to_uint32(&rgb);
		i++;
	}
}

int					sephia_filter(
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
