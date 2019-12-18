#include "rt.test.h"

static t_texels		texels;

TEST_GROUP(set_texels);

TEST_SETUP(set_texels) {}

TEST_TEAR_DOWN(set_texels)
{
	ft_memdel((void **)&texels.buffer);
}

TEST(set_texels, valid)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(
		RT_SUCCESS, set_texels("./contents/earth.jpg", 1, &texels), "res");
}

TEST(set_texels, not_exist_file)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(
		RT_FAIL, set_texels("notexist.jpg", 1, &texels), "res");
}

TEST(set_texels, invalid_repeat)
{
	TEST_ASSERT_EQUAL_INT_MESSAGE(
		RT_FAIL, set_texels("./contents/earth.jpg", -1, &texels), "res");
	TEST_ASSERT_EQUAL_INT_MESSAGE(
		RT_FAIL, set_texels("./contents/earth.jpg", 0, &texels), "res");
}

TEST_GROUP_RUNNER(set_texels)
{
	RUN_TEST_CASE(set_texels, valid);
	RUN_TEST_CASE(set_texels, not_exist_file);
	RUN_TEST_CASE(set_texels, invalid_repeat);
}
