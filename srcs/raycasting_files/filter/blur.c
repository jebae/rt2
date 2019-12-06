#include "raycast.h"

static t_col		horizontal_convolution(unsigned int *buf, int *coeffs)
{
	int		i;
	t_col	rgb_pixel;
	t_col	res;

	ft_memset(&res, 0, sizeof(t_col));
	i = 0;
	while (i < 7)
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
	static int		coeffs[7] = {1, 6, 15, 20, 15, 6, 1};
	int				i;
	t_col			conv[7];
	t_col			res;

	ft_memset(&res, 0, sizeof(t_col));
	i = 0;
	while (i < 7)
	{
		conv[i] = horizontal_convolution(buf, (int *)coeffs);
		buf += width;
		i++;
	}
	i = 0;
	while (i < 7)
	{
		res.r += coeffs[i] * conv[i].r;
		res.g += coeffs[i] * conv[i].g;
		res.b += coeffs[i] * conv[i].b;
		i++;
	}
	res.r /= 4096;
	res.g /= 4096;
	res.b /= 4096;
	return (res);
}

static void			blur(void *arg_void)
{
	int						i;
	t_col					rgb;
	unsigned int			*buf[2];
	t_arg_buffer_th_job		*arg;

	arg = (t_arg_buffer_th_job *)arg_void;
	buf[0] = (unsigned int *)arg->buf[0] + arg->offset;
	buf[1] = (unsigned int *)arg->buf[1] + arg->offset;
	i = 0;
	while (i < arg->work_size)
	{
		rgb = convolution(buf[1] + i, arg->width);
		buf[0][i + arg->width * 3 + 3] = rgb_to_uint32(&rgb);
		if (i % arg->width >= arg->width - 7)
			i += 7;
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

	if (width < 7 || height < 7)
		return (RT_SUCCESS);
	buf_size = sizeof(unsigned int) * width * height;
	if ((buf_info.buf[1] = ft_memalloc(buf_size)) == NULL)
		return (RT_FAIL);
	ft_memcpy(buf_info.buf[1], buffer, buf_size);
	buf_info.buf[0] = buffer;
	set_buffer_info(width, height - 6, &buf_info);
	if (for_each_pixel(&buf_info, (void *)&blur) == RT_FAIL)
	{
		ft_memdel((void **)&buf_info.buf[1]);
		return (RT_FAIL);
	}
	ft_memdel((void **)&buf_info.buf[1]);
	return (RT_SUCCESS);
}
