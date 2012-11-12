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

            inline bool& WorkTogether(int londonId, int stockholmId) {
                if (TryConvertToLondonIndex(londonId) && TryConvertToStockholmIndex(stockholmId)) {
                    return m_Assosiations[londonId][stockholmId];
                }
                else {
                    throw std::out_of_range("londonId or stockholmId is out of its bounds");
                }
            }

            inline bool WorkTogether(int londonId, int stockholmId) const {
                return const_cast<ProjectGraph*>(this)->WorkTogether(londonId, stockholmId);
            }
        protected:
            bool ConvertIds(int &toLondon, int &toStockholm);
    };
}}

#endif // GRAPH_HPP_INCLUDED
