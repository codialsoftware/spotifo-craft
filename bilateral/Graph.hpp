#ifndef GRAPH_HPP_INCLUDED
#define GRAPH_HPP_INCLUDED

#include <stdexcept>
namespace SpotifyPuzzles { namespace Bilateral {
    class ProjectGraph {
        public:
            enum {
                DivisionEmployeesCount = 1000,
                LondonMinId = 2000,
                LondonMaxId = 2999,
                StockholmMinId = 1000,
                StockholmMaxId = 1999,
                EmployeeMinId = StockholmMinId,
                EmployeeMaxId = LondonMaxId,
                InvalidId = -1
            };
        private:
            bool m_Assosiations[DivisionEmployeesCount][DivisionEmployeesCount];
            #if !defined AssertIndex
            # define AssertIndex(idx) if ((idx) < 0 || SpotifyPuzzles::Bilateral::ProjectGraph::DivisionEmployeesCount <= (idx)) \
                                        throw std::out_of_range("Index " #idx " is out of range!");
            #endif

        public:
            ProjectGraph();

            void Clear();
            void Assign(int idA, int idB);

            inline static bool TryConvertToLondonIndex(int &id) {
                return TryConvertToIndex(id, LondonMinId, LondonMaxId);
            }

            inline static int ConvertToLondonIndex(int id) {
                return ConvertToIndex(id, LondonMinId, LondonMaxId);
            }

            inline static bool TryConvertToStockholmIndex(int &id) {
                return TryConvertToIndex(id, StockholmMinId, StockholmMaxId);
            }

            inline static int ConvertToStockholmIndex(int id) {
                return ConvertToIndex(id, StockholmMinId, StockholmMaxId);
            }

            inline static bool TryConvertToIndex(int &value, int rangeInf, int rangeSup) {
                if (rangeInf <= value && value <= rangeSup) {
                    value -= rangeInf;
                    return true;
                }
                else {
                    return false;
                }
            }

            inline static int ConvertToIndex(int value, int rangeInf, int rangeSup) {
                if (TryConvertToIndex(value, rangeInf, rangeSup)) {
                    return value;
                }
                else {
                    return InvalidId;
                }
            }

            inline bool& WorkTogether(int londonIndex, int stockholmIndex) {
                AssertIndex(londonIndex);
                AssertIndex(stockholmIndex);

                return m_Assosiations[londonIndex][stockholmIndex];
            }

            inline bool WorkTogether(int londonIndex, int stockholmIndex) const {
                return const_cast<ProjectGraph*>(this)->WorkTogether(londonIndex, stockholmIndex);
            }
        protected:
            bool ConvertIds(int &toLondon, int &toStockholm);

    };
}}

#endif // GRAPH_HPP_INCLUDED
