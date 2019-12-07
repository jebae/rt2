#include "rt.h"

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
	t_col					rgb;
	t_col					*rgb_buf;
	unsigned int			*hex_color_buf;
	t_arg_buffer_th_job		*arg;

	arg = (t_arg_buffer_th_job *)arg_void;
	hex_color_buf = (unsigned int *)arg->buf[0] + arg->offset;
	rgb_buf = (t_col *)arg->buf[1] + arg->offset;
	i = 0;
	while (i < arg->work_size)
	{
		rgb = uint32_to_rgb(hex_color_buf[i]);
		rgb_buf[i].r += rgb.r;
		rgb_buf[i].g += rgb.g;
		rgb_buf[i].b += rgb.b;
		i++;
	}
}

int				motion_blur_add_scenes(t_buffer_info *buf_info, t_env *e)
{
	int			i;
	double		dt;
	char		*temp;

	temp = e->data;
	e->data = buf_info->buf[0];
	dt = 1.0 / RT_FRAME_PER_SEC;
	i = 0;
	while (i < RT_FRAME_PER_SEC)
	{
		translate_objs_at_time(e->ll_obj, e->num_objs, dt, dt * i);
		multi_thread(e); // guard thread error
		if (for_each_pixel(buf_info, (void *)&add_translated_scene) == RT_FAIL)
		{
			e->data = temp;
			return (RT_FAIL);
		}
		i++;
	}
	e->data = temp;
	return (RT_SUCCESS);
}
