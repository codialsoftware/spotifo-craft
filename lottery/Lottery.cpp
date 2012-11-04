#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "Lottery.h"
using namespace std;

unsigned long long choose(unsigned long long n, unsigned long long k) {
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

string convert(double value) {
    static ostringstream buffer;

    buffer.clear();
    buffer.str("");

    buffer << setprecision(9) << value << flush;
    return buffer.str();
}

string SpotifyPuzzles::LotteryCalc::calculate(int attendees, int drawn, int friends, int tickets) {
    // T = minimum # of friends which must be drawn, so the entire group of friends can get tickets
    int T = (int)ceil((float)friends / tickets);
    // N = # of additions
    int N = friends - T;
    int nonFriends = attendees - friends;

    double factor = 1.0 / choose(attendees, drawn);
    double fraction = 0.0;
    for (int i = 0; i <= N; ++i) {
        int iteration = T + i;
        fraction += choose(friends, iteration) * factor * choose(nonFriends, drawn - iteration);
    }

    return convert(fraction);
}
