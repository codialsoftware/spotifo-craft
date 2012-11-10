#if defined(UNITTEST)
#include "shared/unittest.h"
#include "Lottery.hpp"
#include "algorithms/BasicAlgorithm.hpp"
#include "combinatorics/all.h"
#include "algorithms/MultiplicatoryAlgorithm.hpp"
#include <string>
#include <sstream>

namespace {
    // unfortunally UnitTest++ is f...ed a bit because of the macros TEST(), TEST_FIXTURE(). You
    // cannot use anything else except for a non-generic class name. Therefor we need following
    // placeholders for generic types, as well as using macros instead of inlined functions
	// so we get feedback about crashed tests' lines.
    using namespace SpotifyPuzzles::Lottery::Algorithms;
    using namespace SpotifyPuzzles::Combinatorics;
    class NaiveAlgorithm: public BasicAlgorithm<CombinationsNaive> {};
    class BasicRecursiveAlgorithm: public BasicAlgorithm<CombinationsRecursive> {};
    class BufferedRecursiveAlgorithm: public BasicAlgorithm<CombinationsRecursiveBuffered> {};

    const double EPSILON = 1e-9;
	#define check(exp, actual)	CHECK_CLOSE(exp, actual, EPSILON)

	using namespace SpotifyPuzzles;

//    template <class T>
//    void doCertaintyForSmallValues(const T& mThis) {
	#define doCertaintyForSmallValues(mThis) { 	\
        check(1.0, (mThis)(1,1,1,1)); \
        check(1.0, (mThis)(5, 1, 5, 5)); \
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

	#define doSpotifyWebPageExamples(mThis) {\
        check(0.1, (mThis)(100, 10, 2, 1)); \
        check(189.0/990.0, (mThis)(100, 10, 2, 2)); /* analitically calculated result: 189/990 = 0.1(90) */ \
        check(1, (mThis)(10, 10, 5, 1)); \
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

	#define doLongLongOverflowTest(mThis) { \
		check( (7.0 * 11 * 27 * 61 * 2741) / (4.0 * 71 * 491 * 493 * 499), (mThis)(500, 10, 30, 250)); \
	}
    TEST_FIXTURE(BufferedRecursiveAlgorithm, LongLongOverflowTest) {
        doLongLongOverflowTest(*this);
    }

    // MultiplicatoryAlgorithm tests
//    TEST_FIXTURE(MultiplicatoryAlgorithm, LongLongOverflowTest) {
//        doLongLongOverflowTest(*this);
//    }
    TEST_FIXTURE(MultiplicatoryAlgorithm, SpotifyWebPageExamples) {
        doSpotifyWebPageExamples(*this);
    }
    TEST_FIXTURE(MultiplicatoryAlgorithm, CertaintyForSmallValues) {
        doCertaintyForSmallValues(*this);
    }
}




int run_unittest() {
    return UnitTest::RunAllTests();
}
#endif
