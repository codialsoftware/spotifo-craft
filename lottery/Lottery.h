#ifndef LOTTERY_H_INCLUDED
#define LOTTERY_H_INCLUDED
#include <string>
#include <sstream>

namespace SpotifyPuzzles {
    class LotteryCalc {
        public:
            static std::string calculate(int attendees, int drawn, int friends, int tickets);
    };
}

#endif // LOTTERY_H_INCLUDED
