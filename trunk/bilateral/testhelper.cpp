#if defined(UNITTEST)

#include "testhelper.h"
#include <fstream>
#include <sstream>
using namespace std;
using namespace SpotifyPuzzles::Bilateral::Algorithms;

void openFile(ifstream& input, const string& testName);
void runAlgorithm(AlgorithmBase& algorithm, istream& input, ostream& output);
void checkResults(const string& testName, istream& input);

void Tests::TestHelper::runTest(AlgorithmBase& algorithm, const string& testName) {
    ifstream input;
    openFile(input, testName);

    stringstream results;
    try {
        runAlgorithm(algorithm, input, results);
        input.close();
    }
    catch (...) {
        input.close();
        TEST_FAILED("Unexpected exception while launching current algorithm.");
    }

    checkResults(testName, results);
}

void runAlgorithm(AlgorithmBase& algorithm, istream& input, ostream& output) {
    input >> algorithm;
    output << algorithm;
}

string getPath(const string& fileName) {
//    return "bin\\UnitTest-Debug\\" + fileName;
    return fileName;
}

void openFile(ifstream& input, const string& testName) {
    string fileName = getPath(testName + ".in");
    input.open(fileName.c_str());
//    string path = ExePath();
//    fstream::iostate s = input.rdstate();
    if (input.is_open()) {
        input.exceptions(fstream::failbit | fstream::eofbit);
    }
}

void readResults(vector<int>& results, istream& input);

struct ByCheckEqualComparer {
    template <class T>
    inline bool operator()(T l, T r) {
        ostringstream oss;
        oss << "Algorithm result set's data does not match! Expected: " << l << " Actual: " << r;
        CHECK_ASSERT_EX(l == r, oss.str());
        return true;
    }
};

void checkResults(const string& testName, istream& input) {
    string fileName = getPath(testName + ".out");
    fstream refInput;
    refInput.open(fileName.c_str(), fstream::in);

    string errorMessage = "";
    try {
        vector<int> refResults;
        readResults(refResults, refInput);

        vector<int> actResults;
        readResults(actResults, input);

        CHECK_ASSERT_EX(refResults.size() == actResults.size(), "Algorithm result set's size is incorrect!");
        sort(refResults.begin(), refResults.end());
        sort(actResults.begin(), actResults.end());
        equal(refResults.begin(), refResults.end(), actResults.begin(), ByCheckEqualComparer());
    }
    catch (const string& message) {
        errorMessage = message;
    }
    catch (const char* message) {
        errorMessage = message;
    }
    catch (...) {
        errorMessage = "No further information available.";
    }

    refInput.close();

    if (!errorMessage.empty()) {
        errorMessage.insert(0, "Test " + testName + " failed. ");
        TEST_FAILED(errorMessage.c_str());
    }
}

void readResults(vector<int>& results, istream& input) {
    input.exceptions(istream::failbit);
    int count;
    input >> count;

    results.resize(count);
    while (--count >= 0) {
        input >> results[count];
    }
}

#endif
