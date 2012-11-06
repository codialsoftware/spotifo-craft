#ifndef LOTTERY_H_INCLUDED
#define LOTTERY_H_INCLUDED
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

namespace SpotifyPuzzles { namespace Lottery {
    namespace impl {
        std::string convert(double value);
    }

    template <class Func2>
    double calculate (int attendees, int drawn, int tickets, int friends,  const Func2& choose) {
        // T = minimum # of friends which must be drawn, so the entire group of friends can get tickets
        int T = (int)ceil((float)friends / tickets);
        // N = # of additions
        int N = std::min(friends, drawn) - T;
        int nonFriends = attendees - friends;

        double factor = 1.0 / choose(attendees, drawn);
        double fraction = 0.0;
        for (int i = 0; i <= N; ++i) {
            int iteration = T + i;

            double f1 = choose(friends, iteration) * factor;
            double f2 = choose(nonFriends, drawn - iteration);
            fraction += f1 * f2;
        }

        return fraction;
    }
}}

#endif // LOTTERY_H_INCLUDED
