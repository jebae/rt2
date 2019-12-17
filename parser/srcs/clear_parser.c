#include "rt.h"

void		clear_parse(t_parse *p)
{
	if (p->mem.m != NULL)
		ft_memdel((void **)&p->mem.m);
	if (p->str.time != NULL)
		ft_memdel((void **)&p->str.time);
}
