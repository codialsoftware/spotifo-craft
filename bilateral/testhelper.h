#ifndef TESTHELPER_H_INCLUDED
#define TESTHELPER_H_INCLUDED

#if defined(UNITTEST)
#include "shared/unittest.h"
#include <string>
#include "algorithms/Algorithm.hpp"
namespace Tests {
    struct TestHelper {
        static void test(SpotifyPuzzles::Bilateral::Algorithms::AlgorithmBase& algorithm, const std::string& testName);
    };
}
#endif
#endif // TESTHELPER_H_INCLUDED
