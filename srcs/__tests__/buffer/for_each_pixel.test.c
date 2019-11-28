#include "rt.test.h"

/*
** consider MAX_THREAD = 50
*/
static unsigned int			*buffer;
static int					width;
static int					height;
static int					size;
static int					res;
static t_buffer_info		buf_info;

static void		func(void *arg_void)
{
	int						i;
	int						until;
	t_arg_buffer_th_job		*arg;

	arg = (t_arg_buffer_th_job *)arg_void;
	i = arg->offset;
	until = i + arg->work_size;
	while (i < until)
	{
		arg->buf[i] = 0xff;
		i++;
	}
}

TEST_GROUP(for_each_pixel);

TEST_SETUP(for_each_pixel) {}

TEST_TEAR_DOWN(for_each_pixel)
{
	ft_memdel((void **)&buffer);
}

TEST(for_each_pixel, case_one_line_per_thread)
{
	width = 21;
	height = 42;
	size = width * height;
	buffer = ft_memalloc(sizeof(unsigned int) * size);
	set_buffer_info(buffer, width, height, &buf_info);

	res = for_each_pixel(&buf_info, (void *)&func);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	for (int i=0; i < size; i++)
		TEST_ASSERT_EQUAL_INT_MESSAGE(0xff, buffer[i], "buffer value");
}

TEST(for_each_pixel, case_multi_line_per_thread)
{
	width = 21;
	height = 142;
	size = width * height;
	buffer = ft_memalloc(sizeof(unsigned int) * size);
	set_buffer_info(buffer, width, height, &buf_info);

	res = for_each_pixel(&buf_info, (void *)&func);
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, res, "res");
	for (int i=0; i < size; i++)
		TEST_ASSERT_EQUAL_INT_MESSAGE(0xff, buffer[i], "buffer value");
}

TEST_GROUP_RUNNER(for_each_pixel)
{
	RUN_TEST_CASE(for_each_pixel, case_one_line_per_thread);
	RUN_TEST_CASE(for_each_pixel, case_multi_line_per_thread);
}

void	test_for_each_pixel(void)
{
	RUN_TEST_GROUP(for_each_pixel);
}
