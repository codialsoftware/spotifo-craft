#include <UnitTest++.h>
#include "..\DateTime.h"

namespace {
    TEST(GetToStringOfCorrectNotLeapDate) {
        SpotifyPuzzles::DateTime dt(31, 3, 1970);
        CHECK_EQUAL("1970-03-31", dt.toString());

        SpotifyPuzzles::DateTime dt2(28, 2, 2011);
        CHECK_EQUAL("2011-02-28", dt2.toString());
    }

    TEST(GetToStringOfIncorrectNotLeapDate) {
        {
            SpotifyPuzzles::DateTime dt(32, 2, 2011); // February usually has 28 days
            CHECK_EQUAL("is illegal", dt.toString());
        }
        {
            SpotifyPuzzles::DateTime dt(32, 3, 2011); // March  has 31 days
            CHECK_EQUAL("is illegal", dt.toString());
        }
        {
            SpotifyPuzzles::DateTime dt(31, 4, 2011); // April has 30 days
            CHECK_EQUAL("is illegal", dt.toString());
        }
        {
            SpotifyPuzzles::DateTime dt(0, 2, 2011); // None of months has 0 day.
            CHECK_EQUAL("is illegal", dt.toString());
        }
        {
            SpotifyPuzzles::DateTime dt(10, 0, 2011); // Months only in 1-12 range.
            CHECK_EQUAL("is illegal", dt.toString());
        }
        {
            SpotifyPuzzles::DateTime dt(10, 13, 2011); // Months only in 1-12 range.
            CHECK_EQUAL("is illegal", dt.toString());
        }
    }
}
