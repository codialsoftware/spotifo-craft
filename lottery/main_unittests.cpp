#if defined(UNITTEST)
#include "shared/unittest.h"
#include "Lottery.hpp"
#include "algorithms/BasicAlgorithmInstances.hpp"
#include <string>
#include <sstream>

namespace {
    const double EPSILON = 10e-9;
    void check(double exp, double actual) {
        CHECK_CLOSE(exp, actual, EPSILON);
    }

    using namespace SpotifyPuzzles;
    using namespace SpotifyPuzzles::Lottery::Algorithms;

    template <class T>
    void doCertaintyForSmallValues(const T& mThis) {
        check(1.0, mThis(1,1,1,1));
        check(1.0, mThis(5, 1, 5, 5));
    }
    TEST_FIXTURE(NaiveAlgorithm, CertaintyForSmallValues) {
        doCertaintyForSmallValues(*this);
    }
    TEST_FIXTURE(BasicRecursiveAlgorithm, CertaintyForSmallValues) {
        doCertaintyForSmallValues(*this);
    }
    TEST_FIXTURE(BufferedRecursiveAlgorithm, CertaintyForSmallValues) {
        doCertaintyForSmallValues(*this);
    }

    template <class T>
    void doSpotifyWebPageExamples(const T& mThis) {
        check(0.1, mThis(100, 10, 2, 1));
        check(189.0/990.0, mThis(100, 10, 2, 2)); // analitically calculated result: 189/990 = 0.1(90)
        check(1, mThis(10, 10, 5, 1));
    }
//    TEST_FIXTURE(CombinationsNaive, SpotifyWebPageExamples) {
//        doSpotifyWebPageExamples(*this);
//    }
//    TEST_FIXTURE(CombinationsRecursive, SpotifyWebPageExamples) {
//        doSpotifyWebPageExamples(*this);
//    }
    TEST_FIXTURE(BufferedRecursiveAlgorithm, SpotifyWebPageExamples) {
        doSpotifyWebPageExamples(*this);
    }

	template <class T>
	void doLongLongOverflowTest(const T& mThis) {
		check( (7.0 * 11 * 27 * 61 * 2741) / (4.0 * 71 * 491 * 493 * 499), mThis(500, 10, 30, 250));
	}
    TEST_FIXTURE(BufferedRecursiveAlgorithm, LongLongOverflowTest) {
        doLongLongOverflowTest(*this);
    }
}




int run_unittest() {
    return UnitTest::RunAllTests();
}
#endif
