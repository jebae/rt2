#include "rt.test.h"

/*
** consider MAX_THREAD = 50
*/
static unsigned int			*buffer;
static int					width;
static int					height;
static int					size;
static int					res;
static t_filter_buffer_info	buf_info;

static void		filter_func(void *arg_void)
{
	int						i;
	int						until;
	t_arg_filter_th_job		*arg;

	arg = (t_arg_filter_th_job *)arg_void;
	i = arg->offset;
	until = i + arg->work_size;
	while (i < until)
	{
		arg->buf[i] = 0xff;
		i++;
	}
}

TEST_GROUP(filter_color);

TEST_SETUP(filter_color) {}

TEST_TEAR_DOWN(filter_color)
{
	ft_memdel((void **)&buffer);
}

TEST(filter_color, case_one_line_per_thread)
{
	width = 21;
	height = 42;
	size = width * height;
	buffer = ft_memalloc(sizeof(unsigned int) * size);
	set_filter_buf_info(buffer, width, height, &buf_info);

	res = filter_color(&buf_info, &filter_func);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	for (int i=0; i < size; i++)
		TEST_ASSERT_EQUAL_INT_MESSAGE(0xff, buffer[i], "buffer value");
}

TEST(filter_color, case_multi_line_per_thread)
{
	width = 21;
	height = 142;
	size = width * height;
	buffer = ft_memalloc(sizeof(unsigned int) * size);
	set_filter_buf_info(buffer, width, height, &buf_info);

	res = filter_color(&buf_info, &filter_func);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	for (int i=0; i < size; i++)
		TEST_ASSERT_EQUAL_INT_MESSAGE(0xff, buffer[i], "buffer value");
}

TEST_GROUP_RUNNER(filter_color)
{
	RUN_TEST_CASE(filter_color, case_one_line_per_thread);
	RUN_TEST_CASE(filter_color, case_multi_line_per_thread);
}
