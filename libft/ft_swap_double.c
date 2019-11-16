#include "libft.h"

void		ft_swap_double(double *a, double *b)
{
	double		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

