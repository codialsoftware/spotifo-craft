#if defined(UNITTEST)

#include "testhelper.h"
#include <fstream>
#include <sstream>
using namespace std;
using namespace SpotifyPuzzles::Bilateral::Algorithms;

void openFile(fstream& input, const string& testName);
void runAlgorithm(AlgorithmBase& algorithm, istream& input, ostream& output);
void checkResults(const string& testName, istream& input);

void Tests::TestHelper::test(AlgorithmBase& algorithm, const string& testName) {
    fstream input;
    openFile(input, testName);

    stringstream results;
    try {
        runAlgorithm(algorithm, input, results);
        input.close();
    }
    catch (...) {
        input.close();
        CHECK(false);
    }

    checkResults(testName, results);
}

void openFile(fstream& input, const string& testName) {
    string fileName = testName + ".in";
    input.open(fileName.c_str(), fstream::in);
    if (input.is_open()) {
        input.exceptions(fstream::failbit | fstream::eofbit);
    }
}

void runAlgorithm(AlgorithmBase& algorithm, istream& input, ostream& output) {
    input >> algorithm;
    output << algorithm;
}

void checkResults(const string& testName, istream& input) {
    string fileName = testName + ".out";
    fstream refInput;
    refInput.open(fileName.c_str(), fstream::in);

    try {
        input.seekg(0);

    }
    catch (...) {
    }
}

#endif
