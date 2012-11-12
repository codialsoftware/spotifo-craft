#include "Algorithm.hpp"

using namespace std;
void SpotifyPuzzles::Bilateral::Algorithms::AlgorithmBase::Run(istream& in) {
    int count;
    in >> count;

    m_Projects.Clear();
    while (count--) {
        int left, right;

        in >> left >> right;
        m_Projects.Assign(left, right);
    }
}

const vector<int>& SpotifyPuzzles::Bilateral::Algorithms::AlgorithmBase::Results() const {
    return m_Results;
}
