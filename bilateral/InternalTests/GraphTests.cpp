#if defined(UNITTEST)
#include "..\shared\unittest.h"
#include "..\Graph.hpp"
#include <stdexcept>
#include <iostream>

using namespace SpotifyPuzzles::Bilateral;
using namespace std;
SUITE(ProjectGraph) {
    void checkClean(ProjectGraph const& graph) {
	    for (int i = 0; i < ProjectGraph::DivisionEmployeesCount; ++i) {
            for (int j = 0; j < ProjectGraph::DivisionEmployeesCount; ++j) {
                CHECK_EQUAL(false, graph.WorkTogether(i, j));
            }
	    }

	    CHECK_EQUAL((int)ProjectGraph::FriendId, graph.BestNode());
    }

	TEST_LOGGED(LondonIndexConverters_GoodValues) {
		CHECK_EQUAL(0, ProjectGraph::ConvertToLondonIndex(ProjectGraph::LondonMinId));
		CHECK_EQUAL(ProjectGraph::DivisionEmployeesCount-1, ProjectGraph::ConvertToLondonIndex(ProjectGraph::LondonMaxId));

		int value = ProjectGraph::LondonMinId;
		CHECK_EQUAL(true, ProjectGraph::TryConvertToLondonIndex(value));
		value = ProjectGraph::LondonMaxId;
		CHECK_EQUAL(true, ProjectGraph::TryConvertToLondonIndex(value));
	}
	TEST_LOGGED(LondonIndexConverters_InvalidValues) {
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
	TEST_LOGGED(StockholmIndexConverters_GoodValues) {
		CHECK_EQUAL(0, ProjectGraph::ConvertToStockholmIndex(ProjectGraph::StockholmMinId));
		CHECK_EQUAL(ProjectGraph::DivisionEmployeesCount-1, ProjectGraph::ConvertToStockholmIndex(ProjectGraph::StockholmMaxId));

		int value = ProjectGraph::StockholmMinId;
		CHECK_EQUAL(true, ProjectGraph::TryConvertToStockholmIndex(value));
		value = ProjectGraph::StockholmMaxId;
		CHECK_EQUAL(true, ProjectGraph::TryConvertToStockholmIndex(value));
	}
	TEST_LOGGED(StockholmIndexConverters_InvalidValues) {
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

	TEST_FIXTURE_LOGGED(ProjectGraph, GetAssign_OutOfBounds_IndexOutOfRange) {
	    CHECK_THROW(WorkTogether(ProjectGraph::LondonMinId, ProjectGraph::StockholmMinId), out_of_range);
	    CHECK_THROW(WorkTogether(ProjectGraph::LondonMaxId, 0), out_of_range);
	    CHECK_THROW(WorkTogether(0, ProjectGraph::DivisionEmployeesCount), out_of_range);
	}

//	TEST_FIXTURE_LOGGED(ProjectGraph, GetAssign_OutOfBounds_TwoEmployeesInTheSameLocation) {
//	    CHECK_THROW(WorkTogether(ProjectGraph::LondonMinId, ProjectGraph::LondonMinId), out_of_range);
//	    CHECK_THROW(WorkTogether(ProjectGraph::LondonMaxId, ProjectGraph::LondonMinId), out_of_range);
//	    CHECK_THROW(WorkTogether(ProjectGraph::StockholmMinId, ProjectGraph::StockholmMinId), out_of_range);
//	    CHECK_THROW(WorkTogether(ProjectGraph::StockholmMaxId, ProjectGraph::StockholmMinId), out_of_range);
//	}
//

	TEST_FIXTURE_LOGGED(ProjectGraph, ClearObjectOnInitialization) {
	    checkClean(*this);
	}

    #define assignTestSymetry(a,  b) {\
        Clear();\
        checkClean(*this);\
        Assign((a), (b));\
        CHECK_EQUAL(true, AreAssigned((a), (b)));\
        CHECK_EQUAL(true, AreAssigned((b), (a)));\
    }
	TEST_FIXTURE_LOGGED(ProjectGraph, Assign) {
	    int lon = ProjectGraph::LondonMinId;
	    int sto = ProjectGraph::StockholmMaxId;

        assignTestSymetry(lon, sto);
        CHECK_EQUAL(true, WorkTogether(lon - ProjectGraph::LondonMinId, sto - ProjectGraph::StockholmMinId));

        assignTestSymetry(sto, lon);
        CHECK_EQUAL(true, WorkTogether(lon - ProjectGraph::LondonMinId, sto - ProjectGraph::StockholmMinId));
        CHECK_EQUAL(min(lon, sto), BestNode());
	}

	TEST_FIXTURE_LOGGED(ProjectGraph, AreAssignTwoEmployeesFromSameLocation_Failes) {
	    CHECK_THROW(Assign(ProjectGraph::LondonMinId, ProjectGraph::LondonMinId+1), invalid_argument);
	    CHECK_THROW(Assign(ProjectGraph::StockholmMinId, ProjectGraph::StockholmMinId+1), invalid_argument);
	    CHECK_THROW(AreAssigned(ProjectGraph::LondonMinId, ProjectGraph::LondonMinId+1), invalid_argument);
	    CHECK_THROW(AreAssigned(ProjectGraph::StockholmMinId, ProjectGraph::StockholmMinId+1), invalid_argument);
	    checkClean(*this);
	}

	TEST_FIXTURE_LOGGED(ProjectGraph, CheckAreAssigned_Assign_Equality) {
	    int lon = ProjectGraph::LondonMaxId;
	    int sto = ProjectGraph::StockholmMaxId;

	    Assign(lon, sto);
	    CHECK_EQUAL(true, AreAssigned(lon, sto));
	    CHECK_EQUAL(true, WorkTogether(lon - ProjectGraph::LondonMinId, sto - ProjectGraph::StockholmMinId));
        CHECK_EQUAL(min(lon, sto), BestNode());

	    Clear();
	    checkClean(*this);
	}

	TEST_FIXTURE_LOGGED(ProjectGraph, Assign_UnAssign) {
	    int lon = ProjectGraph::LondonMaxId;
	    int sto = ProjectGraph::StockholmMaxId;

	    Assign(lon, sto);
        CHECK_EQUAL(min(lon, sto), BestNode());
	    UnAssign(sto, lon);
	    checkClean(*this);
	}

	TEST_FIXTURE_LOGGED(ProjectGraph, AssignToAll_thenNodeDegree_thenClear) {
	    int lon = ProjectGraph::LondonMinId + ProjectGraph::DivisionEmployeesCount/2;

	    for (int i = ProjectGraph::StockholmMinId; i <= ProjectGraph::StockholmMaxId; ++i) {
	        Assign(i, lon);
	    }
	    CHECK_EQUAL((int)ProjectGraph::DivisionEmployeesCount, Degree(lon));
	    CHECK_EQUAL(lon, BestNode());

	    UnAssignAll(lon);
	    checkClean(*this);
	    CHECK_EQUAL((int)ProjectGraph::FriendId, BestNode());
	}

	TEST_FIXTURE_LOGGED(ProjectGraph, BestNodeForMyFriend) {
	    int startId = ProjectGraph::StockholmMaxId;
	    int myId = ProjectGraph::LondonMinId;

	    checkClean(*this);
	    Assign(myId, startId);
	    CHECK_EQUAL(min(myId, startId), BestNode());
	    UnAssign(myId, startId);
	    CHECK_EQUAL((int)ProjectGraph::FriendId, BestNode());

	    Assign(myId, startId);
	    Assign(myId, startId-1);
	    CHECK_EQUAL(myId, BestNode());
	    UnAssign(myId, startId - 1);
	    CHECK_EQUAL(min(myId, startId), BestNode());
	    UnAssign(myId, startId);
	    checkClean(*this);
	}
}

#endif
