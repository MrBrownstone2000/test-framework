#include "UnitTests/test.hpp"
#include "UnitTests/toto/toto.hpp"

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
