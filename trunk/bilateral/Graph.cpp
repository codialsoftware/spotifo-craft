#include "Graph.hpp"
#include <cstring>

using namespace SpotifyPuzzles::Bilateral;
//SpotifyPuzzles::Bilateral::
ProjectGraph::ProjectGraph() {
    Clear();
}

void ProjectGraph::Clear() {
    memset(m_Assosiations, 0, sizeof(bool) * DivisionEmployeesCount * DivisionEmployeesCount);
}

void ProjectGraph::Assign(int idA, int idB) {
    int london = idA;
    int stockholm = idB;

    if (ConvertIds(london, stockholm)) {
        WorkTogether(london, stockholm);
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

bool ProjectGraph::ConvertIds(int &toLondon, int &toStockholm) {
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
