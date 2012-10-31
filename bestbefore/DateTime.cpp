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
        if (!isLegal())
            return "is illegal";

        stringstream ss;

        ss << m_year << '-'
            << setfill('0') << setw(2) << m_month << '-'
            << setw(2) << m_day;
        return ss.str();
    }
}
