#include "raycast.h"

static void		set_arg_th_job(
	t_buffer_info *buf_info,
	int offset,
	int work_size,
	t_arg_buffer_th_job *arg
)
{
	arg->buf = buf_info->buf;
	arg->buf_copy = buf_info->buf_copy;
	arg->offset = offset;
	arg->work_size = work_size;
}

static int		case_one_line_per_th(
	t_buffer_info *buf_info,
	t_arg_buffer_th_job *arg,
	pthread_t *tid,
	void *(*func)(void *arg)
)
{
	int		i;
	int		offset;

	offset = 0;
	i = 0;
	while (i < buf_info->height)
	{
		set_arg_th_job(buf_info, offset, buf_info->width, arg + i);
		if (pthread_create(tid + i, NULL, func, arg + i) != 0)
			return (RT_FAIL);
		offset += buf_info->width;
		i++;
	}
	return (RT_SUCCESS);
}

static int		case_multi_line_per_th(
	t_buffer_info *buf_info,
	t_arg_buffer_th_job *arg,
	pthread_t *tid,
	void *(*func)(void *arg)
)
{
	int		i;
	int		work_size;
	int		offset;

	work_size = buf_info->width * (buf_info->line_per_th + 1);
	offset = 0;
	i = 0;
	while (i < buf_info->line_rest)
	{
		set_arg_th_job(buf_info, offset, work_size, arg + i);
		if (pthread_create(tid + i, NULL, func, arg + i) != 0)
			return (RT_FAIL);
		offset += work_size;
		i++;
	}
	work_size = buf_info->width * buf_info->line_per_th;
	while (i < RT_MAX_THREAD)
	{
		set_arg_th_job(buf_info, offset, work_size, arg + i);
		if (pthread_create(tid + i, NULL, func, arg + i) != 0)
			return (RT_FAIL);
		offset += work_size;
		i++;
	}
	return (RT_SUCCESS);
}

int				for_each_pixel(
	t_buffer_info *buf_info,
	void *(*func)(void *arg)
)
{
	int						res;
	int						num_thread;
	t_arg_buffer_th_job		arg[RT_MAX_THREAD];
	pthread_t				tid[RT_MAX_THREAD];

	if (buf_info->line_per_th == 0)
	{
		num_thread = buf_info->height;
		res = case_one_line_per_th(buf_info, arg, tid, func);
	}
	else
	{
		num_thread = RT_MAX_THREAD;
		res = case_multi_line_per_th(buf_info, arg, tid, func);
	}
	if (res == RT_FAIL)
		return (RT_FAIL);
	while (num_thread--)
	{
		if (pthread_join(tid[num_thread], NULL) != 0)
			return (RT_FAIL);
	}
	return (RT_SUCCESS);
}

void			set_buffer_info(
	unsigned int *buffer,
	int width,
	int height,
	t_buffer_info *buf_info
)
{
	buf_info->buf = buffer;
	buf_info->width = width;
	buf_info->height = height;
	buf_info->line_per_th = height / RT_MAX_THREAD;
	buf_info->line_rest = height % RT_MAX_THREAD;
}
