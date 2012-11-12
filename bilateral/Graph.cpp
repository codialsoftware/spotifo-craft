#include "Graph.hpp"
#include <cstring>
#include <stdexcept>
#include <algorithm>

using namespace SpotifyPuzzles::Bilateral;
using namespace std;
//SpotifyPuzzles::Bilateral::
ProjectGraph::ProjectGraph() {
    Clear();
}

void ProjectGraph::Clear() {
    memset(m_Assosiations, 0, sizeof(bool) * DivisionEmployeesCount * DivisionEmployeesCount);
    memset(m_NodesDegree, 0, sizeof(int) * NodesCount);
}

void ProjectGraph::Assign(int idA, int idB) {
    areAssigned(idA, idB) = true;
    ++degree(idA);
    ++degree(idB);
}

template <class It, class Comp>
It findMaxElement(It begin, It end, Comp comparer) {
    It max = begin;
    size_t dist = ProjectGraph::EmployeeMinId;

    for (It current = begin; ++current != end; ) {
        int cdist = current - begin + ProjectGraph::EmployeeMinId;
        if (comparer(*current, *max, cdist, dist)) {
            max = current;
            dist = cdist;
        }
    }

    return max;
}

int findBestNodeId(const int *begin, const int *end) {
    int result = findMaxElement(begin, end, NodeDegreeGreaterComparer()) - begin;
    return result + ProjectGraph::EmployeeMinId;
}

int ProjectGraph::BestNode() const {
    return findBestNodeId(m_NodesDegree, m_NodesDegree + NodesCount);
}

void ProjectGraph::UnAssign(int idA, int idB) {
    areAssigned(idA, idB) = false;
    --degree(idA);
    --degree(idB);
}

void ProjectGraph::UnAssignAll(int id) {
    int dl = 0, londonIdx = 0;
    int ds = 0, stockholmIdx = 0;

    if (TryConvertToLondonIndex(id)) {
        londonIdx = id;
        ds = 1;
    }
    else if (TryConvertToStockholmIndex(id)) {
        stockholmIdx = id;
        dl = 1;
    }

    for (;
        londonIdx != DivisionEmployeesCount && stockholmIdx != DivisionEmployeesCount;
        londonIdx += dl, stockholmIdx += ds) {
        if (WorkTogether(londonIdx, stockholmIdx)) {
            --degree(londonIdx + LondonMinId);
            --degree(stockholmIdx + StockholmMinId);

            WorkTogether(londonIdx, stockholmIdx) = false;
        }
    }
}

bool& ProjectGraph::areAssigned(int idA, int idB) {
    int london = idA;
    int stockholm = idB;

    if (convertIds(london, stockholm)) {
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

bool ProjectGraph::convertIds(int &toLondon, int &toStockholm) const {
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
