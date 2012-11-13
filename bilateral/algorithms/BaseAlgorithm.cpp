#include "BaseAlgorithm.h"

using namespace std;
void SpotifyPuzzles::Bilateral::Algorithms::BaseAlgorithm::Run(istream& in) {
    AlgorithmBase::Run(in);

    while (m_Projects.Degree(m_Projects.BestNode())) {
        m_Results.push_back(m_Projects.BestNode());
        m_Projects.UnAssignAll(m_Projects.BestNode());
    }
}
