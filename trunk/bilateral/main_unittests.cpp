#include "shared/unittest.h"
#include "testhelper.h"
#include "algorithms/BaseAlgorithm.h"

namespace {
    using namespace Tests;
    using namespace SpotifyPuzzles::Bilateral::Algorithms;

    TEST_LOGGED(SpotifyWebPageTests) {
        TestHelper::Test(BaseAlgorithm(), "spotify01");
        TestHelper::Test(BaseAlgorithm(), "spotify02");
    }
    TEST_LOGGED(MyTest_NoFriend) {
        TestHelper::Test(BaseAlgorithm(), "myTest01");
    }
    TEST_LOGGED(MyTest_WithFriend) {
        TestHelper::Test(BaseAlgorithm(), "myTest02");
    }
//    TEST_LOGGED(SpotifyWebPageTests_DataSet03) {
//        TestHelper::Test(BaseAlgorithm(), "spotify03");
//    }
}


int run_unittest() {
    return UnitTest::RunAllTests();
}
