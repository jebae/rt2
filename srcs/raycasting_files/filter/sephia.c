#include "raycast.h"

void			sephia_filter(void *arg_void)
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
		rgb.r = 0.393 * temp.r + 0.769 * temp.g + 0.189 * temp.b;
		rgb.g = 0.349 * temp.r + 0.686 * temp.g + 0.168 * temp.b;
		rgb.b = 0.272 * temp.r + 0.534 * temp.g + 0.131 * temp.b;
		adjust_color(&rgb.r);
		adjust_color(&rgb.g);
		adjust_color(&rgb.b);
		arg->buffer[i] = rgb_to_uint32(&rgb);
		i++;
	}
}
