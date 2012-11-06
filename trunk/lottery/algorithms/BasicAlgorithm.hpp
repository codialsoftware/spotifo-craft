#ifndef BASICALGORITHM_HPP_INCLUDED
#define BASICALGORITHM_HPP_INCLUDED

#include "AlgorithmBase.h"
namespace SpotifyPuzzles { namespace Lottery { namespace Algorithms {

    template <class ChooseAlgorithm>
    class BasicAlgorithm: impl::AlgorithmBase {
        ChooseAlgorithm m_Choose;
        public:
            BasicAlgorithm()
                : m_Choose(ChooseAlgorithm()) {}

            double operator()(int attendees, int drawn, int tickets, int friends) const {
                initialize(attendees, drawn, tickets, friends);

                double factor = 1.0 / m_Choose(Attendees(), Drawns());
                double fraction = 0.0;
                for (int i = 0; i <= NumeratorSteps(); ++i) {
                    int iteration = MinFriendsDrawn() + i;

                    double f1 = m_Choose(Friends(), iteration) * factor;
                    double f2 = m_Choose(Oponents(), Drawns() - iteration);
                    fraction += f1 * f2;
                }

                return fraction;
            }
    };
}}}

#endif // BASICALGORITHM_HPP_INCLUDED
