#ifndef ABSTRACT_CALCULATOR_HPP_INCLUDED
#define ABSTRACT_CALCULATOR_HPP_INCLUDED

#include <string>
#include "..\Lottery.h"
namespace SpotifyPuzzles { namespace Combinatorics { namespace impl {
    class AbstractCalculator {
        public:
             std::string calculate(int a, int b, int c, int d) const {
                return Lottery::calculate(a, b, c, d, *this);
            }
    };
}}}

#endif // ABSTRACT_CALCULATOR_HPP_INCLUDED
