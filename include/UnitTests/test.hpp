#ifndef __TEST_HPP__
#define __TEST_HPP__

#include "asserts.hpp"
#include "base.hpp"
#include "factory.hpp"
#include "runner.hpp"

#include <iostream>
#include <string>

#define TEST_MODULE(_MODULE_NAME_)                                                                  \
namespace { const char _TEST_MODULE_[] = #_MODULE_NAME_; }                                          \
namespace


#define TEST(_TEST_NAME_)                                                                           \
void test_##_TEST_NAME_();                                                                          \
class _TEST_NAME_ : public test::TestBase, test::RegisteredInFactory<_TEST_MODULE_, _TEST_NAME_>    \
{                                                                                                   \
public:                                                                                             \
    _TEST_NAME_()                                                                                   \
    {                                                                                               \
        TEST_FACTORY_INIT;                                                                          \
    }                                                                                               \
                                                                                                    \
    static TestBase* CreateInstance()                                                               \
    {                                                                                               \
        return new _TEST_NAME_();                                                                   \
    }                                                                                               \
                                                                                                    \
    bool Run() override                                                                             \
    {                                                                                               \
        return test::RunIndividualTest(#_TEST_NAME_, test_##_TEST_NAME_);                           \
    }                                                                                               \
};                                                                                                  \
                                                                                                    \
void test_##_TEST_NAME_()                                                                           \


#endif
