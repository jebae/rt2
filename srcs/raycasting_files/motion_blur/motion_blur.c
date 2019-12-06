#include "rt.test.h" // need to be changed as raycast.h

static int		handle_fail(t_buffer_info *buf_info)
{
	ft_memdel((void **)&buf_info->buf[0]);
	ft_memdel((void **)&buf_info->buf[1]);
	return (RT_FAIL);
}

static int		set_buffers(int num_pixels, t_buffer_info *buf_info)
{
	buf_info->buf[0] = NULL;
	buf_info->buf[1] = NULL;
	if ((buf_info->buf[0] =
		ft_memalloc(sizeof(unsigned int) * num_pixels)) == NULL)
		return (RT_FAIL);
	if ((buf_info->buf[1] = ft_memalloc(sizeof(t_col) * num_pixels)) == NULL)
		return (RT_FAIL);
	return (RT_SUCCESS);
}

static void		average(void *arg_void)
{
	int						i;
	t_col					*rgb_buf;
	unsigned int			*hex_color_buf;
	t_arg_buffer_th_job		*arg;

	arg = (t_arg_buffer_th_job *)arg_void;
	hex_color_buf = (unsigned int *)arg->buf[0] + arg->offset;
	rgb_buf = (t_col *)arg->buf[1] + arg->offset;
	i = 0;
	while (i < arg->work_size)
	{
		rgb_buf[i].r /= RT_FRAME_PER_SEC;
		rgb_buf[i].g /= RT_FRAME_PER_SEC;
		rgb_buf[i].b /= RT_FRAME_PER_SEC;
		hex_color_buf[i] = rgb_to_uint32(rgb_buf + i);
		i++;
	}
}

int				motion_blur(t_env *e)
{
	t_buffer_info	buf_info;

	set_buffer_info(e->width, e->height, &buf_info);
	if (set_buffers(e->num_pixels, &buf_info) == RT_FAIL)
		return (handle_fail(&buf_info));
	if (motion_blur_add_scenes(&buf_info, e) == RT_FAIL)
		return (handle_fail(&buf_info));
	ft_memdel((void **)&buf_info.buf[0]);
	buf_info.buf[0] = (void *)e->data;
	if (for_each_pixel(&buf_info, (void *)&average) == RT_FAIL)
		return (handle_fail(&buf_info));
	ft_memdel((void **)&buf_info.buf[1]);
	return (RT_SUCCESS);
}
