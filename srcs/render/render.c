#include "rt.h"

static void		erase_buffers(t_env *e)
{
	ft_bzero(e->img_buf, sizeof(unsigned int) * (e->num_pixels / 4));
	ft_bzero(e->data, sizeof(unsigned int) * e->num_pixels);
}

static int		set_filter(t_env *e)
{
	unsigned int	*buf;
	int				(*filter)(unsigned int *, int, int);

	filter = NULL;
	if (e->mask & RT_ENV_MASK_SEPHIA)
		filter = im_sephia;
	else if (e->mask & RT_ENV_MASK_NEGATIVE)
		filter = im_negative;
	else if (e->mask & RT_ENV_MASK_GRAY_SCALE)
		filter = im_gray_scale;
	else if (e->mask & RT_ENV_MASK_GAUSSIAN_BLUR)
		filter = im_gaussian_blur;
	buf = (unsigned int *)e->img_buf;
	if (filter == NULL)
		return (RT_SUCCESS);
	if (filter(buf, e->width / 2, e->height / 2) == IM_FAIL)
		return (RT_FAIL);
	return (RT_SUCCESS);
}

int				render(t_env *e)
{
	erase_buffers(e);
	if ((e->mask & RT_ENV_MASK_CEL_SHADING))
	{
		if (cel_shading(e) == RT_FAIL)
			return (RT_FAIL);
	}
	else
		multi_thread(e); // need to protect
	if (anti_aliasing(
		(unsigned int *)e->img_buf, (unsigned int *)e->data,
		e->width / 2, e->height / 2) == RT_FAIL)
		return (RT_FAIL);
	if (set_filter(e) == RT_FAIL)
		return (RT_FAIL);
	//mlx_put_image_to_window(e->w.mp, e->w.wp, e->w.ip, 0, 0);
	//write_buffer to sdl
	return (RT_SUCCESS);
}
