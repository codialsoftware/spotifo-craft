#if defined(UNITTEST)

#include "testhelper.h"
#include <fstream>
#include <sstream>
using namespace std;
using namespace SpotifyPuzzles::Bilateral::Algorithms;

void openFile(ifstream& input, const string& testName);
void runAlgorithm(AlgorithmBase& algorithm, istream& input, ostream& output);
void checkResults(const string& testName, istream& input);

void Tests::TestHelper::test(AlgorithmBase& algorithm, const string& testName) {
    ifstream input;
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

string getPath(const string& fileName) {
//    return "bin\\UnitTest-Debug\\" + fileName;
    return fileName;
}

void openFile(ifstream& input, const string& testName) {
    string fileName = getPath(testName + ".in");
    input.open(fileName.c_str());
//    string path = ExePath();
    fstream::iostate s = input.rdstate();
    if (input.is_open()) {
        input.exceptions(fstream::failbit | fstream::eofbit);
    }
}

void runAlgorithm(AlgorithmBase& algorithm, istream& input, ostream& output) {
    input >> algorithm;
    output << algorithm;
}

void checkResults(const string& testName, istream& input) {
    string fileName = getPath(testName + ".out");
    fstream refInput;
    refInput.open(fileName.c_str(), fstream::in);

    try {
        input.seekg(0);
        int exp, is;

        input.exceptions(istream::failbit);
        refInput.exceptions(istream::failbit);

        while (!refInput.eof()) {
            refInput >> exp;
            input >> is;

            CHECK_EQUAL(exp, is);
        }
    }
    catch (...) {
        CHECK(false);
    }

    refInput.close();
}

#endif
