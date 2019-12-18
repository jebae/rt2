#include "rt.test.h"

static t_vec3		amb;

TEST_GROUP(set_ambient);

TEST_SETUP(set_ambient) {}

TEST_TEAR_DOWN(set_ambient) {}

TEST(set_ambient, valid)
{
	amb = (t_vec3){0.1, 0.1, 0.1};
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, set_ambient(&amb), "res");

	amb = (t_vec3){0.0, 0.0, 0.0};
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_SUCCESS, set_ambient(&amb), "res");
}

TEST(set_ambient, lt_0)
{
	amb = (t_vec3){-0.1, 0.1, 0.1};
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, set_ambient(&amb), "res");
	amb = (t_vec3){0.1, -0.1, 0.1};
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, set_ambient(&amb), "res");
	amb = (t_vec3){0.1, 0.1, -0.1};
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, set_ambient(&amb), "res");
}

TEST(set_ambient, gt_1)
{
	amb = (t_vec3){1.1, 0.1, 0.1};
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, set_ambient(&amb), "res");
	amb = (t_vec3){0.1, 1.1, 0.1};
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, set_ambient(&amb), "res");
	amb = (t_vec3){0.1, 0.1, 1.1};
	TEST_ASSERT_EQUAL_INT_MESSAGE(RT_FAIL, set_ambient(&amb), "res");
}

TEST_GROUP_RUNNER(set_ambient)
{
	RUN_TEST_CASE(set_ambient, valid);
	RUN_TEST_CASE(set_ambient, lt_0);
	RUN_TEST_CASE(set_ambient, gt_1);
}
