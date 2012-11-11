#ifndef BASEALGORITHM_H_INCLUDED
#define BASEALGORITHM_H_INCLUDED

#include "Algorithm.hpp"

namespace SpotifyPuzzles { namespace Bilateral { namespace Algorithms {
    class  BaseAlgorithm: public AlgorithmBase {
        protected:
            void Run(std::istream& in);
    };
}}}

#endif // BASEALGORITHM_H_INCLUDED
