#ifndef LOTTERY_H_INCLUDED
#define LOTTERY_H_INCLUDED
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

namespace SpotifyPuzzles { namespace Lottery {
    namespace impl {
        std::string convert(double value);
    }

    template <class Algorithm>
    class Calculator {
        Algorithm m_tmpAlg;
        Algorithm& m_Algorithm;

        int m_Friends;
        int m_Attendees;
        int m_Drawns;
        int m_Tickets;

        public:
            Calculator()
                : m_tmpAlg(Algorithm())
                , m_Algorithm(m_tmpAlg) {}

            Calculator(const Algorithm& alg)
                : m_Algorithm(alg) {}

            double operator()(int attendees, int drawn, int tickets, int friends) {
                return m_Algorithm(attendees, drawn, tickets, friends);
            }

            operator std::string() const {
                return impl::convert(m_Algorithm(m_Attendees, m_Drawns, m_Tickets, m_Friends));
            }

            friend std::ostream& operator<< (std::ostream& out, const Calculator& mThis) {
                 out << (std::string)mThis;
                 return out;
            }

            friend std::istream& operator>> (std::istream& in, Calculator& mThis) {
                in >> mThis.m_Attendees >> mThis.m_Drawns >> mThis.m_Tickets >> mThis.m_Friends;
                return in;
            }
    };
}}

#endif // LOTTERY_H_INCLUDED
