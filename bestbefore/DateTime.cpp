#include "DateTime.h"
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

namespace SpotifyPuzzles {
    DateTime::DateTime(int day, int month, int year) {
        m_day = day;
        m_month = month;
        m_year = year;
    }

    bool DateTime::isLegal() {
        static int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (0 < m_month && m_month <= 12) {
            return 0 < m_day && m_day <= daysInMonth[m_month - 1];
        }

        return false;
    }

    string DateTime::toString() {
        if (!isLegal())
            return "is illegal";

        stringstream ss;

        ss << m_year << '-'
            << setfill('0') << setw(2) << m_month << '-'
            << setw(2) << m_day;
        return ss.str();
    }
}
