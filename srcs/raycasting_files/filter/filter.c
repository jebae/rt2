#include "raycast.h"

static int		case_one_line_per_th(
	t_filter_buffer_info buf_info,
	t_arg_filter_th_job *arg,
	pthread_t *tid,
	void (*filter_func)(void *arg)
)
{
	while (buf_info.height--)
	{
		arg[buf_info.height].buffer = buf_info.buffer;
		arg[buf_info.height].work_size = buf_info.width;
		if (pthread_create(&(tid[buf_info.height]), NULL,
			(void *)filter_func, &(arg[buf_info.height])) != 0)
			return (RT_FAIL);
		buf_info.buffer += buf_info.width;
	}
	return (RT_SUCCESS);
}

static int		case_multi_line_per_th(
	t_filter_buffer_info buf_info,
	t_arg_filter_th_job *arg,
	pthread_t *tid,
	void (*filter_func)(void *arg)
)
{
	int		i;
	int		work_size;

	work_size = buf_info.width * (buf_info.line_per_th + 1);
	i = 0;
	while (i < buf_info.line_rest)
	{
		arg[i].buffer = buf_info.buffer;
		arg[i].work_size = work_size;
		if (pthread_create(tid + i, NULL, (void *)filter_func, arg + i) != 0)
			return (RT_FAIL);
		buf_info.buffer += work_size;
		i++;
	}
	work_size = buf_info.width * buf_info.line_per_th;
	while (i < RT_MAX_THREAD)
	{
		arg[i].buffer = buf_info.buffer;
		arg[i].work_size = work_size;
		if (pthread_create(tid + i, NULL, (void *)filter_func, arg + i) != 0)
			return (RT_FAIL);
		buf_info.buffer += work_size;
		i++;
	}
	return (RT_SUCCESS);
}

int				filter_color(
	unsigned int *buffer,
	int width,
	int height,
	void (*filter_func)(void *arg)
)
{
	int						res;
	int						num_thread;
	t_filter_buffer_info	buf_info;
	t_arg_filter_th_job		arg[RT_MAX_THREAD];
	pthread_t				tid[RT_MAX_THREAD];

	buf_info.width = width;
	buf_info.height = height;
	buf_info.buffer = buffer;
	buf_info.line_per_th = height / RT_MAX_THREAD;
	buf_info.line_rest = height % RT_MAX_THREAD;
	num_thread = RT_MAX_THREAD;
	if (buf_info.line_per_th == 0 && (num_thread = height))
		res = case_one_line_per_th(buf_info, arg, tid, filter_func);
	else
		res = case_multi_line_per_th(buf_info, arg, tid, filter_func);
	if (res == RT_FAIL)
		return (RT_FAIL);
	while (num_thread--)
	{
		if (pthread_join(tid[num_thread], NULL) != 0)
			return (RT_FAIL);
	}
	return (RT_SUCCESS);
}

void			adjust_color(int *color)
{
	if (*color > 0xff)
		*color = 0xff;
}

