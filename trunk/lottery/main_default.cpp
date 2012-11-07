#include <iostream>
#include "shared/main.h"
#include "algorithms/MultiplicatoryAlgorithm.hpp"
#include "Lottery.hpp"

using namespace std;
using namespace SpotifyPuzzles::Lottery;
int run() {
    Calculator<Algorithms::MultiplicatoryAlgorithm> calculator;

    cin >> calculator;
    cout << calculator << endl;
    return 0;
}
