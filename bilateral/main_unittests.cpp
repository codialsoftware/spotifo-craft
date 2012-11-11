#include "shared/unittest.h"
#include "testhelper.h"
#include "algorithms/BaseAlgorithm.h"

namespace {
    using namespace Tests;
    using namespace SpotifyPuzzles::Bilateral::Algorithms;

    TEST(SpotifyWebPageTests) {
        BaseAlgorithm alg;

        TestHelper::test(alg, "spotify01");
        TestHelper::test(alg, "spotify02");
    }
}


int run_unittest() {
    return UnitTest::RunAllTests();
}
