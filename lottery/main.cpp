#include <iostream>
#include "shared/unittest.h"
using namespace std;

int run() {
//    cout << SpotifyPuzzles::DateTime::parseEarliest2000(cin).str() << endl;
    return 0;
}

int main() {
    #if defined(UNITTEST)
        return run_unittest();
    #else
        return run();
    #endif
}
