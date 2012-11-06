#ifndef NAIVE_HPP_INCLUDED
#define NAIVE_HPP_INCLUDED

#include <string>
namespace SpotifyPuzzles { namespace Combinatorics {
    struct CombinationsNaive {
        unsigned long long operator()(int n, int k) const {
            if (k > n) {
                return 0;
            }
            unsigned long long r = 1;
            for (unsigned long long d = 1; d <= k; ++d) {
                r *= n--;
                r /= d;
            }
            return r;
        }
    };
}}

#endif // NAIVE_HPP_INCLUDED
