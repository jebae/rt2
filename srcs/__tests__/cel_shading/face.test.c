#include "rt.test.h"

static double		cos_60 = 0.5;
static double		cos_75 = 0.25881904510252074;

TEST_GROUP(cel_shade_manipulate);

TEST_SETUP(cel_shade_manipulate) {}

TEST_TEAR_DOWN(cel_shade_manipulate) {}

TEST(cel_shade_manipulate, _0_to_60)
{
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(1.0,
		cel_shade_manipulate(1.0), "0 deg");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(1.0,
		cel_shade_manipulate(cos(M_PI / 4.0)), "45 deg");
}

TEST(cel_shade_manipulate, _60_to_75)
{
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.5,
		cel_shade_manipulate(cos_60), "60 deg");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.5,
		cel_shade_manipulate(cos(70 * M_PI / 180.0)), "70 deg");
}

TEST(cel_shade_manipulate, _75_to_90)
{
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(cos_75,
		cel_shade_manipulate(cos_75), "75 deg");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(cos_75,
		cel_shade_manipulate(cos(89 * M_PI / 180.0)), "89 deg");
}

TEST(cel_shade_manipulate, gte_90)
{
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.0,
		cel_shade_manipulate(0.0), "90 deg");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.0,
		cel_shade_manipulate(cos(91 * M_PI / 180.0)), "91 deg");
}

TEST_GROUP_RUNNER(cel_shade_manipulate)
{
	RUN_TEST_CASE(cel_shade_manipulate, _0_to_60);
	RUN_TEST_CASE(cel_shade_manipulate, _60_to_75);
	RUN_TEST_CASE(cel_shade_manipulate, _75_to_90);
	RUN_TEST_CASE(cel_shade_manipulate, gte_90);
}
