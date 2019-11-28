#include "raycast.h"

static int		handle_fail(unsigned int *buf2)
{
	ft_memdel((void **)&buf2);
	return (RT_FAIL);
}

// need to fix
// have to consider accumulated distance !!
static void		translate_objs_at_time(t_ol *ol, size_t num_objs, double time)
{
	int			i;
	double		to_mul;
	t_vec3		v_translate;

	to_mul = time * (1.0 - 0.5 * time);
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
	t_col					rgb_buf;
	t_col					rgb_buf2;
	t_arg_buffer_th_job		*arg;

	arg = (t_arg_buffer_th_job *)arg_void;
	i = arg->offset;
	until = i + arg->work_size;
	while (i < until)
	{
		rgb_buf = uint32_to_rgb(arg->buf[i]);
		rgb_buf2 = uint32_to_rgb(arg->buf2[i]);
		rgb_buf.r += rgb_buf2.r;
		rgb_buf.g += rgb_buf2.g;
		rgb_buf.b += rgb_buf2.b;
		arg->buf[i] = rgb_to_uint32(&rgb_buf);
		i++;
	}
}

static void		average(void *arg_void)
{
	int						i;
	int						until;
	t_col					rgb_buf;
	t_arg_buffer_th_job		*arg;

	arg = (t_arg_buffer_th_job *)arg_void;
	i = arg->offset;
	until = i + arg->work_size;
	while (i < until)
	{
		rgb_buf = uint32_to_rgb(arg->buf[i]);
		rgb_buf.r /= RT_FRAME_PER_SEC + 1;
		rgb_buf.g /= RT_FRAME_PER_SEC + 1;
		rgb_buf.b /= RT_FRAME_PER_SEC + 1;
		arg->buf[i] = rgb_to_uint32(&rgb_buf);
		i++;
	}
}

int				motion_blur(
	t_ol *ol,
	size_t num_objs,
	size_t buf_size,
	unsigned int *buf
)
{
	int				i;
	double			dt;
	t_buffer_info	buf_info;

	if ((buf_info.buf2 = ft_memalloc(buf_size)) == NULL)
		return (RT_FAIL);
	dt = 1.0 / RT_FRAME_PER_SEC;
	i = 1;
	while (i <= RT_FRAME_PER_SEC)
	{
		translate_objs_at_time(ol, num_objs, dt * i);

		/*
		** below code will be replaced with real raytrace
		*/
		
		if (for_each_pixel(&buf_info, (void *)&add_translated_scene) == RT_FAIL)
			return (handle_fail(buf_info.buf2));
		i++;
	}
	if (for_each_pixel(&buf_info, (void *)&add_translated_scene) == RT_FAIL)
		return (handle_fail(buf_info.buf2));
	ft_memdel((void **)&buf_info.buf2);
	return (RT_SUCCESS);
}

