#include <cassert>
#include <string>
#include <sstream>
#include <iomanip>
#include "Lottery.hpp"
using namespace std;

string SpotifyPuzzles::Lottery::impl::convert(double value) {
    static ostringstream buffer;

    buffer.clear();
    buffer.str("");

    buffer << fixed << setw(12) << setprecision(10) << value << flush;
    return buffer.str();
}

