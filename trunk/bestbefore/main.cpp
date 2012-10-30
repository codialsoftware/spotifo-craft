#include <iostream>
#include "unittest.h"
using namespace std;

int run() {
    return 0;
}

int main() {
    #if defined(UNITTEST)
        return run_unittest();
    #else
        return run();
    #endif
}
