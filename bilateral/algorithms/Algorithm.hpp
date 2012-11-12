#ifndef ALGORITHM_HPP_INCLUDED
#define ALGORITHM_HPP_INCLUDED

#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include "..\\Graph.hpp"
namespace SpotifyPuzzles { namespace Bilateral { namespace Algorithms {
    class AlgorithmBase {
        protected:
            std::vector<int> m_Results;
            ProjectGraph m_Projects;

            virtual void Run(std::istream& in);
        public:
            const std::vector<int>& Results() const;

            friend std::istream& operator>>(std::istream& in, AlgorithmBase& o) {
                o.Run(in);
                return in;
            }
            friend std::ostream& operator<<(std::ostream& out, const AlgorithmBase& o) {
                out << o.Results().size() << std::endl;

                std::copy(o.Results().begin(),
                    o.Results().end(),
                    std::ostream_iterator<int>(out, "\n"));
                return out;
            }
    };
}}}

#endif // ALGORITHM_HPP_INCLUDED
