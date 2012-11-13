#ifndef TESTHELPER_H_INCLUDED
#define TESTHELPER_H_INCLUDED

#if defined(UNITTEST)
#include "shared/unittest.h"
#include <string>
#include "algorithms/Algorithm.hpp"
namespace Tests {
    struct TestHelper {
        template <class Algorithm>
        static void Test(Algorithm alg, const std::string& testName) {
            runTest(alg, testName);
        }

        private:
            static void runTest(SpotifyPuzzles::Bilateral::Algorithms::AlgorithmBase& algorithm, const std::string& testName);
    };
}
#endif
#endif // TESTHELPER_H_INCLUDED
