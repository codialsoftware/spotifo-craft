#include "Graph.hpp"
#include <cstring>
#include <stdexcept>

using namespace SpotifyPuzzles::Bilateral;
using namespace std;
//SpotifyPuzzles::Bilateral::
ProjectGraph::ProjectGraph() {
    Clear();
}

void ProjectGraph::Clear() {
    memset(m_Assosiations, 0, sizeof(bool) * DivisionEmployeesCount * DivisionEmployeesCount);
}

void ProjectGraph::UnAssign(int idA, int idB) {
    AreAssigned(idA, idB) = false;
}

void ProjectGraph::Assign(int idA, int idB) {
    AreAssigned(idA, idB) = true;
}

bool& ProjectGraph::AreAssigned(int idA, int idB) {
    int london = idA;
    int stockholm = idB;

    if (ConvertIds(london, stockholm)) {
        return WorkTogether(london, stockholm);
    }
    else {
        throw invalid_argument("idA or idB are either out of bounds or indicate employees from the same location!");
    }
}

int getFirstValidIndex(int v1, int v2, int rangeInf, int rangeSup) {
    int result = ProjectGraph::ConvertToIndex(v1, rangeInf, rangeSup);
    if (result != ProjectGraph::InvalidId)
        return result;

    result = ProjectGraph::ConvertToIndex(v2, rangeInf, rangeSup);
    if (result != ProjectGraph::InvalidId)
        return result;

    return ProjectGraph::InvalidId;
}

bool ProjectGraph::ConvertIds(int &toLondon, int &toStockholm) const {
    int resultLondon = getFirstValidIndex(toLondon, toStockholm, LondonMinId, LondonMaxId);
    int resultStockholm = getFirstValidIndex(toLondon, toStockholm, StockholmMinId, StockholmMaxId);
    if (resultLondon != InvalidId && resultStockholm != InvalidId) {
        toLondon = resultLondon;
        toStockholm = resultStockholm;

        return true;
    }
    else {
        return false;
    }
}
