#include "raycast.h"

void			negative_filter(void *arg_void)
{
	int						i;
	t_col					rgb;
	t_col					temp;
	t_arg_filter_th_job		*arg;

	arg = (t_arg_filter_th_job *)arg_void;
	i = 0;
	while (i < arg->work_size)
	{
		rgb = uint32_to_rgb(arg->buffer[i]);
		temp = rgb;
		rgb.r = 0xff - rgb.r;
		rgb.g = 0xff - rgb.g;
		rgb.b = 0xff - rgb.b;
		arg->buffer[i] = rgb_to_uint32(&rgb);
		i++;
	}
}
