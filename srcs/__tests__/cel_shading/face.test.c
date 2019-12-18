#include "rt.test.h"

static double		cos_60 = 0.5;
static double		cos_75 = 0.25881904510252074;

TEST_GROUP(round_n_dot_l);

TEST_SETUP(round_n_dot_l) {}

TEST_TEAR_DOWN(round_n_dot_l) {}

TEST(round_n_dot_l, _0_to_60)
{
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(1.0,
		round_n_dot_l(1.0), "0 deg");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(1.0,
		round_n_dot_l(cos(M_PI / 4.0)), "45 deg");
}

TEST(round_n_dot_l, _60_to_75)
{
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.5,
		round_n_dot_l(cos_60), "60 deg");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.5,
		round_n_dot_l(cos(70 * M_PI / 180.0)), "70 deg");
}

TEST(round_n_dot_l, _75_to_90)
{
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(cos_75,
		round_n_dot_l(cos_75), "75 deg");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(cos_75,
		round_n_dot_l(cos(89 * M_PI / 180.0)), "89 deg");
}

TEST(round_n_dot_l, gte_90)
{
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.0,
		round_n_dot_l(0.0), "90 deg");
	TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.0,
		round_n_dot_l(cos(91 * M_PI / 180.0)), "91 deg");
}

TEST_GROUP_RUNNER(round_n_dot_l)
{
	RUN_TEST_CASE(round_n_dot_l, _0_to_60);
	RUN_TEST_CASE(round_n_dot_l, _60_to_75);
	RUN_TEST_CASE(round_n_dot_l, _75_to_90);
	RUN_TEST_CASE(round_n_dot_l, gte_90);
}
