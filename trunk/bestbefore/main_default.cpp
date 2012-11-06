#include <iostream>
#include "shared/main.h"
#include "DateTime.h"
using namespace std;

int run() {
    cout << SpotifyPuzzles::DateTime::parseEarliest2000(cin).str() << endl;
    return 0;
}