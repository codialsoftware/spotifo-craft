#include "DateTime.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "StringToIntConverter.hpp"
using namespace std;

namespace SpotifyPuzzles {
    void DateTime::initialize(int day, int month, int year) {
        m_day = day;
        m_month = month;
        m_year = normalizedYear(year);
    }

    void DateTime::initialize(const string& parseString, int day, int month, int year) {
        initialize(day, month, year);
        m_parseString = parseString;
    }

    DateTime::DateTime(const string& parseString, int day, int month, int year) {
        initialize(parseString, day, month, year);
    }

    DateTime::DateTime(int day, int month, int year) {
        initialize(day, month, year);
    }

    template <class T, class Func>
    vector<T> tokenize(const string& input, const string& tokens, Func converter) {
        vector<T> results;

        string::size_type split = 0;
        for (;;) {
            string::size_type newsplit = input.find(tokens, split);
            if (newsplit == string::npos) {
                results.push_back(converter(input.substr(split)));
                break;
            }
            else {
                results.push_back(converter(input.substr(split, newsplit - split)));
                split = newsplit + 1;
            }
        }

        return results;
    }

    DateTime DateTime::createDateTime(vector<int>& tokens, const string& str) {
        sort(tokens.begin(), tokens.end());
        do {
            DateTime result(tokens[2], tokens[1], tokens[0]);
            if (result.isValid())
                return result;
        } while (next_permutation(tokens.begin(), tokens.end()));

        return DateTime(str);
    }

    DateTime DateTime::parseEarliest2000(const std::string& str) {
        vector<int> tokens = tokenize<int>(str, "/", StringToIntConverter());
        if (tokens.size() != 3)
            return DateTime(str);

        return createDateTime(tokens, str);
    }

    DateTime DateTime::parseEarliest2000(std::istream& istr) {
        string line;
        istr >> line;
//        std::getline(istr, line);

        return parseEarliest2000(line);
    }

    bool DateTime::isValid() {
        if (m_day < 0)
            return false;

        return 0 < m_day && m_day <= daysInMonth(m_month, m_year);
    }

    int DateTime::daysInMonth(int month, int year) {
        static const int leapDays = 29;
        static const int nonleapDays = 28;
        static const int daysMap[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (month != 2) {
            // not February
            if (0 < month && month <= 12)
                return daysMap[month - 1];
            else
                return -1;
        }
        else {
            // February... check if in a leap year
            if (year % 400 == 0)
                return leapDays;
            else if (year % 100 == 0)
                return nonleapDays;
            else if (year % 4 == 0)
                return leapDays;
            else
                return nonleapDays;
        }
    }

    string DateTime::str() {
        if (!isValid()) {
            if (m_parseString.empty())
                return "is illegal";
            else
                return m_parseString + " is illegal";
        }

        stringstream ss;

        ss << m_year << '-'
            << setfill('0') << setw(2) << m_month << '-'
            << setw(2) << m_day;
        return ss.str();
    }

    int DateTime::normalizedYear(int year) {
        if (0 < year && year < 100)
            return year + 2000;

        return year;
    }
}
