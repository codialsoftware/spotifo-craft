#include <iostream>
#include "unittest.h"
#include "main.h"
using namespace std;

int main() {
    #if defined(UNITTEST)
        return run_unittest();
    #else
        return run();
    #endif
}
