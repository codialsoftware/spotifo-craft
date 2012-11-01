#if !defined(DATE_TIME_H)
#define DATE_TIME_H

#include <string>

namespace SpotifyPuzzles {
    struct DateTime {
        private:
            int m_day, m_month, m_year;
            std::string m_parseString;

            DateTime(const std::string& parseString = 0, int day = -1, int month = -1, int year = -1);
            void initialize(const std::string& parseString, int day = -1, int month = -1, int year = -1);
            void initialize(int day = -1, int month = -1, int year = -1);

        public:
            DateTime(int day, int month, int year);
            static DateTime parseEarliest2000(const std::string& str);

            std::string str();

            static int normalizedYear(int year);

        private:
            bool isLegal();
            int daysInMonth(int month, int year);
    };
}
#endif
