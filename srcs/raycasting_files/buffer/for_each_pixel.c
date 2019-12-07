#include "rt.h"

static void		set_arg_th_job(
	t_buffer_info *buf_info,
	int offset,
	int work_size,
	t_arg_buffer_th_job *arg
)
{
	ft_memcpy(arg->buf, buf_info->buf, sizeof(void *) * 2);
	arg->width = buf_info->width;
	arg->offset = offset;
	arg->work_size = work_size;
}

static int		distribute_work(
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
	i = -1;
	while (++i < buf_info->line_rest)
	{
		set_arg_th_job(buf_info, offset, work_size, arg + i);
		if (pthread_create(tid + i, NULL, func, arg + i) != 0)
			return (RT_FAIL);
		offset += work_size;
	}
	if ((work_size = work_size - buf_info->width) == 0)
		return (RT_SUCCESS);
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
	int						num_thread;
	t_arg_buffer_th_job		arg[RT_MAX_THREAD];
	pthread_t				tid[RT_MAX_THREAD];

	if (buf_info->line_per_th == 0)
		num_thread = buf_info->height;
	else
		num_thread = RT_MAX_THREAD;
	if (distribute_work(buf_info, arg, tid, func) == RT_FAIL)
		return (RT_FAIL);
	while (num_thread--)
	{
		if (pthread_join(tid[num_thread], NULL) != 0)
			return (RT_FAIL);
	}
	return (RT_SUCCESS);
}

void			set_buffer_info(
	int width,
	int height,
	t_buffer_info *buf_info
)
{
	buf_info->width = width;
	buf_info->height = height;
	buf_info->line_per_th = height / RT_MAX_THREAD;
	buf_info->line_rest = height % RT_MAX_THREAD;
}
