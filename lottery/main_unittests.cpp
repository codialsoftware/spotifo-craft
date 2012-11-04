#if defined(UNITTEST)
#include "shared/unittest.h"
#include "Lottery.h"
#include <string>
#include <sstream>

namespace {
    const double EPSILON = 10e-9;
    void check(double exp, std::string actual) {
        static std::istringstream buffer;

        buffer.clear();
        buffer.str(actual);
        double act;
        buffer >> act;


        CHECK_CLOSE(exp, act, EPSILON);
    }

    using namespace SpotifyPuzzles;
    TEST(CertaintyForSmallValues) {
        check(1.0, LotteryCalc::calculate(1, 1, 1, 1));
        check(1.0, LotteryCalc::calculate(5, 1, 5, 5));
    }
}


int run_unittest() {
    return UnitTest::RunAllTests();
}
#endif
