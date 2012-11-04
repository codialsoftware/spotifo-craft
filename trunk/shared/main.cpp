#include <iostream>
#include "unittest.h"
using namespace std;

int main() {
    #if defined(UNITTEST)
        return run_unittest();
    #else
        return run();
    #endif
}
