#if defined(UNITTEST)
#include "shared/unittest.h"
#include "Lottery.hpp"
#include <string>
#include <sstream>
#include "combinatorics/all.h"

namespace {
    const double EPSILON = 10e-9;
    void check(double exp, double actual) {
        CHECK_CLOSE(exp, actual, EPSILON);
    }

    using namespace SpotifyPuzzles;
    using namespace SpotifyPuzzles::Combinatorics;

    template <class T>
    void doCertaintyForSmallValues(const T& mThis) {
        check(1.0, Lottery::calculate(1,1,1,1, mThis));
        check(1.0, Lottery::calculate(5, 1, 5, 5, mThis));
    }
    TEST_FIXTURE(CombinationsNaive, CertaintyForSmallValues) {
        doCertaintyForSmallValues(*this);
    }
    TEST_FIXTURE(CombinationsRecursive, CertaintyForSmallValues) {
        doCertaintyForSmallValues(*this);
    }
    TEST_FIXTURE(CombinationsRecursiveBuffered, CertaintyForSmallValues) {
        doCertaintyForSmallValues(*this);
    }

    template <class T>
    void doSpotifyWebPageExamples(const T& mThis) {
        check(0.1, Lottery::calculate(100, 10, 2, 1, mThis));
        check(189.0/990.0, Lottery::calculate(100, 10, 2, 2, mThis)); // analitically calculated result: 189/990 = 0.1(90)
        check(1, Lottery::calculate(10, 10, 5, 1, mThis));
    }
//    TEST_FIXTURE(CombinationsNaive, SpotifyWebPageExamples) {
//        doSpotifyWebPageExamples(*this);
//    }
//    TEST_FIXTURE(CombinationsRecursive, SpotifyWebPageExamples) {
//        doSpotifyWebPageExamples(*this);
//    }
    TEST_FIXTURE(CombinationsRecursiveBuffered, SpotifyWebPageExamples) {
        doSpotifyWebPageExamples(*this);
    }

	template <class T>
	void doLongLongOverflowTest(const T& mThis) {
	}
    TEST_FIXTURE(CombinationsRecursiveBuffered, LongLongOverflowTest) {
        doSpotifyWebPageExamples(*this);
    }
}




int run_unittest() {
    return UnitTest::RunAllTests();
}
#endif
