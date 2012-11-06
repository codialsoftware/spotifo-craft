#ifndef BASICALGORITHM_HPP_INCLUDED
#define BASICALGORITHM_HPP_INCLUDED

namespace SpotifyPuzzles { namespace Lottery { namespace Algorithms {

    template <class ChooseAlgorithm>
    class BasicAlgorithm {
        ChooseAlgorithm m_Choose;
        public:
            BasicAlgorithm()
                : m_Choose(ChooseAlgorithm()) {}

            double operator()(int attendees, int drawn, int tickets, int friends) const {
                // T = minimum # of friends which must be drawn, so the entire group of friends can get tickets
                int T = (int)ceil((float)friends / tickets);
                // N = # of additions
                int N = std::min(friends, drawn) - T;
                int nonFriends = attendees - friends;

                double factor = 1.0 / m_Choose(attendees, drawn);
                double fraction = 0.0;
                for (int i = 0; i <= N; ++i) {
                    int iteration = T + i;

                    double f1 = m_Choose(friends, iteration) * factor;
                    double f2 = m_Choose(nonFriends, drawn - iteration);
                    fraction += f1 * f2;
                }

                return fraction;
            }
    };
}}}

#endif // BASICALGORITHM_HPP_INCLUDED
