#if !defined(DATE_TIME_H)
#define DATE_TIME_H

#include <string>

namespace SpotifyPuzzles {
    struct DateTime {
        private:
            int m_day, m_month, m_year;

        public:
            DateTime(int day, int month, int year);

            std::string str();

        private:
            bool isLegal();
    };
}
#endif
