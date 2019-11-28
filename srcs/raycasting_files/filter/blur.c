#include "raycast.h"

static t_col		horizontal_convolution(unsigned int *buf, int *coeffs)
{
	int		i;
	t_col	rgb_pixel;
	t_col	res;

	ft_memset(&res, 0, sizeof(t_col));
	i = 0;
	while (i < 5)
	{
		rgb_pixel = uint32_to_rgb(buf[i]);
		res.r += coeffs[i] * rgb_pixel.r;
		res.g += coeffs[i] * rgb_pixel.g;
		res.b += coeffs[i] * rgb_pixel.b;
		i++;
	}
	return (res);
}

static t_col		convolution(unsigned int *buf, int width)
{
	static int		coeffs[5] = {1, 4, 6, 4, 1};
	int				i;
	t_col			conv[5];
	t_col			res;

	ft_memset(&res, 0, sizeof(t_col));
	i = 0;
	while (i < 5)
	{
		conv[i] = horizontal_convolution(buf, (int *)coeffs);
		buf += width;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		res.r += coeffs[i] * conv[i].r;
		res.g += coeffs[i] * conv[i].g;
		res.b += coeffs[i] * conv[i].b;
		i++;
	}
	res.r /= 256;
	res.g /= 256;
	res.b /= 256;
	return (res);
}

static void			blur_func(void *arg_void)
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
		rgb = convolution(arg->buf_copy + i, arg->width);
		arg->buf[i + arg->width * 2 + 2] = rgb_to_uint32(&rgb);
		if (i % arg->width >= arg->width - 5)
			i += 5;
		else
			i++;
	}
}

int					gaussian_blur(
	unsigned int *buffer,
	int width,
	int height
)
{
	size_t			buf_size;
	t_buffer_info	buf_info;

	if (width < 5 || height < 5)
		return (RT_SUCCESS);
	buf_size = sizeof(unsigned int) * width * height;
	if ((buf_info.buf_copy = ft_memalloc(buf_size)) == NULL)
		return (RT_FAIL);
	ft_memcpy(buf_info.buf_copy, buffer, buf_size);
	set_buffer_info(buffer, width, height - 4, &buf_info);
	if (for_each_pixel(&buf_info, (void *)&blur_func) == RT_FAIL)
	{
		ft_memdel((void **)&buf_info.buf_copy);
		return (RT_FAIL);
	}
	ft_memdel((void **)&buf_info.buf_copy);
	return (RT_SUCCESS);
}
