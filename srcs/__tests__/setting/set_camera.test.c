#include "rt.test.h"

static t_camera			cam;
static t_arg_camera		arg_cam;

TEST_GROUP(set_camera);

TEST_SETUP(set_camera) {}

TEST_TEAR_DOWN(set_camera) {}

TEST(set_camera, valid)
{
	arg_cam.pos = (t_vec3){0.0, 0.0, 0.0};
	arg_cam.dir = (t_vec3){0.0, 0.0, 1.0};
	arg_cam.right = (t_vec3){1.0, 0.0, 0.0};
	TEST_ASSERT_EQUAL_INT_MESSAGE(
		RT_SUCCESS, set_camera(&arg_cam, &cam), "res");
}

TEST(set_camera, dir_approx0)
{
	arg_cam.pos = (t_vec3){0.0, 0.0, 0.0};
	arg_cam.dir = (t_vec3){0.0, 0.0, 0.0};
	arg_cam.right = (t_vec3){1.0, 0.0, 0.0};
	TEST_ASSERT_EQUAL_INT_MESSAGE(
		RT_FAIL, set_camera(&arg_cam, &cam), "res");
}

TEST(set_camera, right_approx0)
{
	arg_cam.pos = (t_vec3){0.0, 0.0, 0.0};
	arg_cam.dir = (t_vec3){1.0, 0.0, 0.0};
	arg_cam.right = (t_vec3){0.0, 0.0, 0.0};
	TEST_ASSERT_EQUAL_INT_MESSAGE(
		RT_FAIL, set_camera(&arg_cam, &cam), "res");
}

TEST(set_camera, dir_right_not_orthogonal)
{
	arg_cam.pos = (t_vec3){0.0, 0.0, 0.0};
	arg_cam.dir = (t_vec3){1.0, 0.0, 0.0};
	arg_cam.right = (t_vec3){-1.0, 0.0, 0.0};
	TEST_ASSERT_EQUAL_INT_MESSAGE(
		RT_FAIL, set_camera(&arg_cam, &cam), "res");
}

TEST_GROUP_RUNNER(set_camera)
{
	RUN_TEST_CASE(set_camera, valid);
	RUN_TEST_CASE(set_camera, dir_approx0);
	RUN_TEST_CASE(set_camera, right_approx0);
	RUN_TEST_CASE(set_camera, dir_right_not_orthogonal);
}
