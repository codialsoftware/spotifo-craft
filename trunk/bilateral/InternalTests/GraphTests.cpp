#if defined(UNITTEST)
#include <UnitTest++.h>
#include "..\Graph.hpp"
#include <stdexcept>

using namespace SpotifyPuzzles::Bilateral;
using namespace std;

SUITE(ProjectGraph) {
	TEST(LondonIndexConverters_GoodValues) {
		CHECK_EQUAL(0, ProjectGraph::ConvertToLondonIndex(ProjectGraph::LondonMinId));
		CHECK_EQUAL(ProjectGraph::DivisionEmployeesCount-1, ProjectGraph::ConvertToLondonIndex(ProjectGraph::LondonMaxId));

		int value = ProjectGraph::LondonMinId;
		CHECK_EQUAL(true, ProjectGraph::TryConvertToLondonIndex(value));
		value = ProjectGraph::LondonMaxId;
		CHECK_EQUAL(true, ProjectGraph::TryConvertToLondonIndex(value));
	}
	TEST(LondonIndexConverters_InvalidValues) {
		CHECK_EQUAL((int)ProjectGraph::InvalidId, ProjectGraph::ConvertToLondonIndex(ProjectGraph::LondonMinId-1));
		CHECK_EQUAL((int)ProjectGraph::InvalidId, ProjectGraph::ConvertToLondonIndex(ProjectGraph::LondonMaxId+1));

		int valueIn = ProjectGraph::LondonMinId-1;
		int valueOut = valueIn;
		CHECK_EQUAL(false, ProjectGraph::TryConvertToLondonIndex(valueOut));
		CHECK_EQUAL(valueIn, valueOut);

		valueIn =
		valueOut = ProjectGraph::LondonMaxId+1;
		CHECK_EQUAL(false, ProjectGraph::TryConvertToLondonIndex(valueOut));
		CHECK_EQUAL(valueIn, valueOut);
	}
	TEST(StockholmIndexConverters_GoodValues) {
		CHECK_EQUAL(0, ProjectGraph::ConvertToStockholmIndex(ProjectGraph::StockholmMinId));
		CHECK_EQUAL(ProjectGraph::DivisionEmployeesCount-1, ProjectGraph::ConvertToStockholmIndex(ProjectGraph::StockholmMaxId));

		int value = ProjectGraph::StockholmMinId;
		CHECK_EQUAL(true, ProjectGraph::TryConvertToStockholmIndex(value));
		value = ProjectGraph::StockholmMaxId;
		CHECK_EQUAL(true, ProjectGraph::TryConvertToStockholmIndex(value));
	}
	TEST(StockholmIndexConverters_InvalidValues) {
		CHECK_EQUAL((int)ProjectGraph::InvalidId, ProjectGraph::ConvertToStockholmIndex(ProjectGraph::StockholmMinId-1));
		CHECK_EQUAL((int)ProjectGraph::InvalidId, ProjectGraph::ConvertToStockholmIndex(ProjectGraph::StockholmMaxId+1));

		int valueIn = ProjectGraph::StockholmMinId-1;
		int valueOut = valueIn;
		CHECK_EQUAL(false, ProjectGraph::TryConvertToStockholmIndex(valueOut));
		CHECK_EQUAL(valueIn, valueOut);

		valueIn =
		valueOut = ProjectGraph::StockholmMaxId+1;
		CHECK_EQUAL(false, ProjectGraph::TryConvertToStockholmIndex(valueOut));
		CHECK_EQUAL(valueIn, valueOut);
	}

	TEST_FIXTURE(ProjectGraph, GetAssign_OutOfBounds_IndexOutOfRange) {
	    CHECK_THROW(WorkTogether(ProjectGraph::LondonMinId, ProjectGraph::StockholmMinId), out_of_range);
	    CHECK_THROW(WorkTogether(ProjectGraph::LondonMaxId, 0), out_of_range);
	    CHECK_THROW(WorkTogether(0, ProjectGraph::DivisionEmployeesCount), out_of_range);
	}

//	TEST_FIXTURE(ProjectGraph, GetAssign_OutOfBounds_TwoEmployeesInTheSameLocation) {
//	    CHECK_THROW(WorkTogether(ProjectGraph::LondonMinId, ProjectGraph::LondonMinId), out_of_range);
//	    CHECK_THROW(WorkTogether(ProjectGraph::LondonMaxId, ProjectGraph::LondonMinId), out_of_range);
//	    CHECK_THROW(WorkTogether(ProjectGraph::StockholmMinId, ProjectGraph::StockholmMinId), out_of_range);
//	    CHECK_THROW(WorkTogether(ProjectGraph::StockholmMaxId, ProjectGraph::StockholmMinId), out_of_range);
//	}
//
	TEST_FIXTURE(ProjectGraph, ClearObjectOnInitialization) {
	    for (int i = 0; i < ProjectGraph::DivisionEmployeesCount; ++i) {
            for (int j = 0; j < ProjectGraph::DivisionEmployeesCount; ++j) {
                CHECK_EQUAL(false, WorkTogether(i, j));
            }
	    }
	}

	TEST_FIXTURE(ProjectGraph, GetAssign_Inbounds_ModifyValue) {
	    int a = ProjectGraph::DivisionEmployeesCount / 2;
	    int b = a;

	    CHECK_EQUAL(false, WorkTogether(a, b));
	    WorkTogether(a, b) = true;
	    CHECK_EQUAL(true, WorkTogether(a, b));
	}

	TEST_FIXTURE(ProjectGraph, Clear_ResetsValue) {
	    int a = ProjectGraph::DivisionEmployeesCount-1;
        int b = a;

	    CHECK_EQUAL(false, WorkTogether(a, b));
	    WorkTogether(a, b) = true;
	    CHECK_EQUAL(true, WorkTogether(a, b));
	    Clear();
	    CHECK_EQUAL(false, WorkTogether(a, b));
	}
}

#endif
