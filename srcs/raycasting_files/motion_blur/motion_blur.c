#include "rt.test.h" // need to be changed as raycast.h

static int		handle_fail(unsigned int *buf2)
{
	ft_memdel((void **)&buf2);
	return (RT_FAIL);
}

static void		translate_objs_at_time(
	t_ol *ol,
	int num_objs,
	double dt,
	double t
)
{
	int			i;
	double		to_mul;
	t_vec3		v_translate;

	to_mul = dt * (1.0 - t - (dt / 2.0));
	i = 0;
	while (i < num_objs)
	{
		if (ol[i].has_velocity)
		{
			v_translate = v3_scalar(
				ol[i].v_translate, ol[i].init_speed * to_mul);
			ol[i].translate(&v_translate, ol[i].object);
		}
		i++;
	}
}

static void		add_translated_scene(void *arg_void)
{
	int						i;
	int						until;
	t_col					*rgb_buf;
	t_col					rgb;
	t_arg_buffer_th_job		*arg;

	arg = (t_arg_buffer_th_job *)arg_void;
	rgb_buf = (t_col *)arg->buf;
	i = arg->offset;
	until = i + arg->work_size;
	while (i < until)
	{
		rgb = uint32_to_rgb(arg->buf2[i]);
		rgb_buf[i].r += rgb.r;
		rgb_buf[i].g += rgb.g;
		rgb_buf[i].b += rgb.b;
		i++;
	}
}

static void		average(void *arg_void)
{
	int						i;
	int						until;
	t_col					rgb;
	t_arg_buffer_th_job		*arg;

	arg = (t_arg_buffer_th_job *)arg_void;
	i = arg->offset;
	until = i + arg->work_size;
	while (i < until)
	{
		rgb = uint32_to_rgb(arg->buf[i]);
		rgb.r /= RT_FRAME_PER_SEC + 1;
		rgb.g /= RT_FRAME_PER_SEC + 1;
		rgb.b /= RT_FRAME_PER_SEC + 1;
		arg->buf[i] = rgb_to_uint32(&rgb);
		i++;
	}
}

int				motion_blur(
	t_ol *ol,
	int num_objs,
	size_t buf_size,
	unsigned int *buffer,
	t_camera *cam,
	const char *color
)
{
	int				i;
	double			dt;
	t_buffer_info	buf_info;

	if ((buf_info.buf2 = ft_memalloc(buf_size)) == NULL)
		return (RT_FAIL);
	// width and height need to be changed by parameter
	set_buffer_info(buffer, WIDTH, WIDTH, &buf_info);
	dt = 1.0 / RT_FRAME_PER_SEC;
	i = 0;
	while (i < RT_FRAME_PER_SEC)
	{
		translate_objs_at_time(ol, num_objs, dt, dt * i);

		/*
		** below code will be replaced with real raytrace
		*/
		render_normal_test(buf_info.buf2, cam, ol, color);
		if (for_each_pixel(&buf_info, (void *)&add_translated_scene) == RT_FAIL)
			return (handle_fail(buf_info.buf2));
		i++;
	}
	if (for_each_pixel(&buf_info, (void *)&average) == RT_FAIL)
		return (handle_fail(buf_info.buf2));
	ft_memdel((void **)&buf_info.buf2);
	return (RT_SUCCESS);
}
