#ifndef ALGORITHM_HPP_INCLUDED
#define ALGORITHM_HPP_INCLUDED

#include <iostream>
namespace SpotifyPuzzles { namespace Bilateral { namespace Algorithms {
    class AlgorithmBase {
        protected:
            virtual void run(std::istream& in);
        public:
            friend std::istream& operator>>(std::istream& in, AlgorithmBase& o) {
                o.run(in);
                return in;
            }

            friend std::ostream& operator<<(std::ostream& out, const AlgorithmBase& o) {
                return out;
            }
    };
}}}

#endif // ALGORITHM_HPP_INCLUDED
