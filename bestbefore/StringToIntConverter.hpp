#if !defined(STRING_TO_INT_CONVERTER_HPP)
#define STRING_TO_INT_CONVERTER_HPP
#include <string>
#include <sstream>

using namespace std;

class StringToIntConverter {
    public:
        int operator() (const string& input) {
            int result;
            if ( !(istringstream(input) >> result) )
                return -1;

            return result;
        }
};
#endif
