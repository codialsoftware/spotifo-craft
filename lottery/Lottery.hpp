#ifndef LOTTERY_H_INCLUDED
#define LOTTERY_H_INCLUDED
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <vector>

namespace SpotifyPuzzles { namespace Lottery {
    namespace impl {
        std::string convert(double value);
    }

    template <class Algorithm>
    class Calculator {
        Algorithm m_tmpAlg;
        Algorithm& m_Algorithm;

        public:
            Calculator()
                : m_tmpAlg(Algorithm())
                , m_Algorithm(m_tmpAlg) {}

            Calculator(const Algorithm& alg)
                : m_Algorithm(alg) {}

            double operator()(int attendees, int drawn, int tickets, int friends) {
                return m_Algorithm(attendees, drawn, tickets, friends);
            }
    };
}}

#endif // LOTTERY_H_INCLUDED
