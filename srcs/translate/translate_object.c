#include "rt.h"

void		translate_object(t_env *e, t_vec3 v_translate)
{
	t_ol		*obj;

	obj = e->ll_obj + e->current_obj_index;
	obj->translate(&v_translate, obj->object);
}
