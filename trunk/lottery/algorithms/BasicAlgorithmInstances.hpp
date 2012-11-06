#ifndef BASICALGORITHMINSTANCES_HPP_INCLUDED
#define BASICALGORITHMINSTANCES_HPP_INCLUDED

#include "../combinatorics/all.h"
#include "BasicAlgorithm.hpp"
namespace SpotifyPuzzles { namespace Lottery { namespace Algorithms {
    using namespace SpotifyPuzzles::Combinatorics;

    class NaiveAlgorithm: public BasicAlgorithm<CombinationsNaive> {};
    class BasicRecursiveAlgorithm: public BasicAlgorithm<CombinationsRecursive> {};
    class BufferedRecursiveAlgorithm: public BasicAlgorithm<CombinationsRecursiveBuffered> {};
}}}

#endif // BASICALGORITHMINSTANCES_HPP_INCLUDED
