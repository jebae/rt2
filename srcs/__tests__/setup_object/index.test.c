#include "rt.test.h"

int			setup_object(
	const char *obj,
	const char *case_num,
	t_ol *ol
)
{
	int		res;

	res = RT_FAIL;
	if (strcmp(obj, "box") == 0)
		res = setup_box(case_num, ol);
	else if (strcmp(obj, "cone") == 0)
		res = setup_cone(case_num, ol);
	else if (strcmp(obj, "cylinder") == 0)
		res = setup_cylinder(case_num, ol);
	else if (strcmp(obj, "plane") == 0)
		res = setup_plane(case_num, ol);
	else if (strcmp(obj, "pyramid") == 0)
		res = setup_pyramid(case_num, ol);
	else if (strcmp(obj, "rect") == 0)
		res = setup_rectangle(case_num, ol);
	else if (strcmp(obj, "ring") == 0)
		res = setup_ring(case_num, ol);
	else if (strcmp(obj, "sphere") == 0)
		res = setup_sphere(case_num, ol);
	else if (strcmp(obj, "tri") == 0)
		res = setup_triangle(case_num, ol);
	else
		printf(KRED "Error : object not exist\n" KNRM);
	return (res);
}
