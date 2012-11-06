#if defined(UNITTEST)
#include <UnitTest++.h>
#include "..\recursive_buffered.hpp"

using namespace SpotifyPuzzles::Combinatorics::impl;
SUITE(Combinatorics) {
	TEST(CoordsToArrayIndex_ChooseValue) {
		CHECK_EQUAL(-1, PascalTriangle::Row::toIndex(0, 0));
		CHECK_EQUAL(-1, PascalTriangle::Row::toIndex(2, 0));
		CHECK_EQUAL(-1, PascalTriangle::Row::toIndex(2, 2));
		CHECK_EQUAL(-2, PascalTriangle::Row::toIndex(2, 1));

		CHECK_EQUAL(-1, PascalTriangle::Row::toIndex(3, 0));
		CHECK_EQUAL(-3, PascalTriangle::Row::toIndex(3, 1));
		CHECK_EQUAL(-3, PascalTriangle::Row::toIndex(3, 2));
		CHECK_EQUAL(-1, PascalTriangle::Row::toIndex(3, 3));

		CHECK_EQUAL(-1, PascalTriangle::Row::toIndex(30, 30));
		CHECK_EQUAL(-30, PascalTriangle::Row::toIndex(30, 29));
		CHECK_EQUAL(-30, PascalTriangle::Row::toIndex(30, 1));
		CHECK_EQUAL(-1, PascalTriangle::Row::toIndex(30, 0));
	}

	TEST(CoordsToArrayIndex_EvenRowOffset) {
		CHECK_EQUAL(0, PascalTriangle::Row::toIndex(4, 2));
		CHECK_EQUAL(20, PascalTriangle::Row::toIndex(12, 2));
	}

	TEST(CoordsToArrayIndex_OddRowOffset) {
		CHECK_EQUAL(1, PascalTriangle::Row::toIndex(5, 2));
		CHECK_EQUAL(25, PascalTriangle::Row::toIndex(13, 2));
	}

	TEST(CoordsToArrayIndex_RowSymetry) {
		CHECK_EQUAL(PascalTriangle::Row::toIndex(13, 0), PascalTriangle::Row::toIndex(13, 13));
		CHECK_EQUAL(PascalTriangle::Row::toIndex(13, 1), PascalTriangle::Row::toIndex(13, 12));
		CHECK_EQUAL(PascalTriangle::Row::toIndex(13, 2), PascalTriangle::Row::toIndex(13, 11));

		CHECK_EQUAL(PascalTriangle::Row::toIndex(12, 2), PascalTriangle::Row::toIndex(12, 10));

		// even and odd row symetry
		CHECK_EQUAL(PascalTriangle::Row::toIndex(10, 4), PascalTriangle::Row::toIndex(10, 6));
		CHECK_EQUAL(PascalTriangle::Row::toIndex(11, 5), PascalTriangle::Row::toIndex(11, 6));
	}
}


#endif