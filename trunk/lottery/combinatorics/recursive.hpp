#ifndef RECURSIVE_HPP_INCLUDED
#define RECURSIVE_HPP_INCLUDED

#include <string>
namespace SpotifyPuzzles { namespace Combinatorics {
    struct CombinationsRecursive {
        unsigned long long operator() (int n, int k) const {
            if (n == k || k == 0)
                return 1;
            if (k == 1 || n-k == 1)
                return n;

            return (*this)(n - 1, k) + (*this)(n - 1, k - 1);
        }
    };
}}
#endif // RECURSIVE_HPP_INCLUDED
