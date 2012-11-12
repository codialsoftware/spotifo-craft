#ifndef UNITTEST_H_INCLUDED
#define UNITTEST_H_INCLUDED

#if defined(UNITTEST)
#include <UnitTest++.h>
#include <iostream>
#include <sstream>
#include <iomanip>

    int run_unittest();

    struct EmptyFixture {};

#define TEST_FIXTURE_LOGGED(Fixture,Name)                       \
    struct TestFixture##Name##LoggerHelper: public Fixture {    \
        void RunRealTest();                                     \
    };                                                          \
                                                                \
    TEST_FIXTURE(TestFixture##Name##LoggerHelper, Name) {       \
        std::ostringstream o;                                   \
        o << "(" << __LINE__ << ") Testing \"" #Name "\"...";   \
        std::cout << std::left << std::setw(70)                 \
            << o.str() << std::flush;                           \
        RunRealTest();                                          \
        std::cout << "[passed]" << std::endl;                   \
    }                                                           \
                                                                \
    void TestFixture##Name##LoggerHelper::RunRealTest()


#define TEST_LOGGED(Name) TEST_FIXTURE_LOGGED(EmptyFixture, Name)


#endif

#endif // UNITTEST_H_INCLUDED
