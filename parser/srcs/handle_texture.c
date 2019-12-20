#include "rt.h"

static void		assign_value(t_str *s, int *repeat)
{
	if ((ft_strcmp(s->word, "file")) == 0)
		ft_cpymiddleword(s->word3, s->line);
	if ((ft_strcmp(s->word, "repeat")) == 0)
		*repeat = handle_int_number(s, 0);
}

static void		handle_texture(t_parse *p)
{
	int			repeat;
	t_ol		*ob;
	t_str		*s;

	ob = &p->ob[p->index];
	s = &p->str;
	printf("so i = %d\n", p->index);
	puts("texture HERE");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</texture>") != 0)
	{
		if (*s->buf != '\n' && *s->buf)
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		assign_value(s, &repeat);
		s->buf++;
	}
	printf("filename : %s\n", s->word3);
	if (set_texels(s->word3, repeat, &ob->texture) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
}

static void		handle_bump_map(t_parse *p)
{
	int			repeat;
	t_ol		*ob;
	t_str		*s;

	ob = &p->ob[p->index];
	s = &p->str;
	printf("so i = %d\n", p->index);
	puts("Bump map HERE");
	while (*s->buf != '\0' && ft_strcmp(s->line, "</bump_map>") != 0)
	{
		if (*s->buf != '\n' && *s->buf)
			ft_cpynline(s->line, s->buf);
		ft_cpyword(s->line, s->word);
		while (*s->buf != '\n' && *s->buf)
			s->buf++;
		assign_value(s, &repeat);
		s->buf++;
	}
	if (set_texels(s->word3, repeat, &ob->bump_map) == RT_FAIL)
		p->mask |= RT_ENV_MASK_PARSE_FAIL;
}

void			handle_texels(t_str *s, t_parse *p)
{
	if ((ft_strcmp(s->word, "texture")) == 0)
		handle_texture(p);
	if ((ft_strcmp(s->word, "bump_map")) == 0)
		handle_bump_map(p);
}
