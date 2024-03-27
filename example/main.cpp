#include "UnitTests/test.hpp"

TEST_MODULE(Test_module)
{
    TEST(ExampleSuccess)
    {
        test::expect_lt(69, 666);
    }

    TEST(ExampleFail)
    {
        test::expect_eq(69, 666);
    }
}
