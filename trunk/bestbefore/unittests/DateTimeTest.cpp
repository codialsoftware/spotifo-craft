#include <UnitTest++.h>
#include "..\DateTime.h"

namespace {
    TEST(GetToStringOfCorrectNotLeapDate) {
        SpotifyPuzzles::DateTime dt(31, 3, 1970);
        CHECK_EQUAL("1970-03-31", dt.str());

        SpotifyPuzzles::DateTime dt2(28, 2, 2011);
        CHECK_EQUAL("2011-02-28", dt2.str());

        SpotifyPuzzles::DateTime dt3(5, 5, 1999);
        CHECK_EQUAL("1999-05-05", dt3.str());
    }

    TEST(GetToStringOfIncorrectNotLeapDate) {
        {
            SpotifyPuzzles::DateTime dt(32, 2, 2011); // February usually has 28 days
            CHECK_EQUAL("is illegal", dt.str());
        }
        {
            SpotifyPuzzles::DateTime dt(32, 3, 2011); // March  has 31 days
            CHECK_EQUAL("is illegal", dt.str());
        }
        {
            SpotifyPuzzles::DateTime dt(31, 4, 2011); // April has 30 days
            CHECK_EQUAL("is illegal", dt.str());
        }
        {
            SpotifyPuzzles::DateTime dt(0, 2, 2011); // None of months has 0 day.
            CHECK_EQUAL("is illegal", dt.str());
        }
        {
            SpotifyPuzzles::DateTime dt(10, 0, 2011); // Months only in 1-12 range.
            CHECK_EQUAL("is illegal", dt.str());
        }
        {
            SpotifyPuzzles::DateTime dt(10, 13, 2011); // Months only in 1-12 range.
            CHECK_EQUAL("is illegal", dt.str());
        }
    }

    TEST(CheckLeapYearWithToString) {
        {
            SpotifyPuzzles::DateTime dt(29, 2, 2012);
            CHECK_EQUAL("2012-02-29", dt.str());
        }
        {
            SpotifyPuzzles::DateTime dt(29, 2, 2011);
            CHECK_EQUAL("is illegal", dt.str());
        }
        {
            SpotifyPuzzles::DateTime dt(29, 2, 2000);
            CHECK_EQUAL("2000-02-29", dt.str());
        }
        {
            SpotifyPuzzles::DateTime dt(29, 2, 1900);
            CHECK_EQUAL("is illegal", dt.str());
        }
        {
            SpotifyPuzzles::DateTime dt(29, 2, 1600);
            CHECK_EQUAL("1600-02-29", dt.str());
        }
        {
            SpotifyPuzzles::DateTime dt(29, 2, 2400);
            CHECK_EQUAL("2400-02-29", dt.str());
        }
        {
            SpotifyPuzzles::DateTime dt(29, 2, 2300);
            CHECK_EQUAL("is illegal", dt.str());
        }
    }

    TEST(ParseEarliestIn2000) {
            CHECK_EQUAL("2011-11-11", SpotifyPuzzles::DateTime::parseEarliest2000("11/11/11").str());
            CHECK_EQUAL("2010-11-12", SpotifyPuzzles::DateTime::parseEarliest2000("12/10/11").str());
            CHECK_EQUAL("2072-01-02", SpotifyPuzzles::DateTime::parseEarliest2000("2/1/72").str());
            CHECK_EQUAL("2001-02-07", SpotifyPuzzles::DateTime::parseEarliest2000("7/1/2").str());
            CHECK_EQUAL("8/40/40 is illegal", SpotifyPuzzles::DateTime::parseEarliest2000("8/40/40").str());
            CHECK_EQUAL("2040-08-30", SpotifyPuzzles::DateTime::parseEarliest2000("8/40/30").str());
    }
}
