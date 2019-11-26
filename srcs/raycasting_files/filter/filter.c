#include "raycat.h"

#define MAX_THREAD 50

static int		case_one_line_per_th(
	t_arg_filter *arg,
	void (*filter_func)(void *arg),
	int *num_thread
)
{
	*num_thread = height;
	arg->work_size = width;
	while (height--)
	{
		arg.start_index = height * width;
		if (pthread_create())
	}
}

// handle line bigger than max thread;

int				filter_color(
	const unsigned int *buffer,
	int width,
	int height,
	void (*filter_func)(void *arg)
)
{
	int				res;
	int				num_thread;
	int				line_per_th;
	t_arg_filter	arg;
	pthread_t		tid[MAX_THREAD];

	arg.width = width;
	arg.height = height;
	arg.buffer = buffer;
	arg.line_per_th = height / MAX_THREAD;
	if (line_per_th == 0)
		res = case_one_line_per_th(&num_thread);
	else
		res = case_multi_line_per_th(&num_thread);
	if (res == RT_FAIL)
		return (RT_FAIL);
	while (num_thread--)
	{
		if (pthread_join(tid + num_thread, NULL) != 0)
			return (RT_FAIL);
	}
	return (RT_SUCCESS);
}
