#include "shared/unittest.h"
#if defined(UNITTEST)
int run_unittest() {
    return UnitTest::RunAllTests();
}
#endif
