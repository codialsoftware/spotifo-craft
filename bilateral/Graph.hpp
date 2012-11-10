#ifndef GRAPH_HPP_INCLUDED
#define GRAPH_HPP_INCLUDED

namespace SpotifyPuzzles { namespace BiProjects {
    class ProjectGraph {
        public:
            const int DivisionEmployeesCount = 1000;
        private:
            bool m_Assosiations[DivisionEmployeesCount][DivisionEmployeesCount];

        public:
            int Degree(int id) {

            }


        public:
            class NodeDescription {
                int m_EmployeeId;
                int m_ProjectsCount;

                NodeDescription(int id, int projects) {
                    m_EmployeeId = id;
                    m_ProjectsCount = projects;
                }

                inline int& ProjectsCount() {
                    return m_ProjectsCount;
                }

                public:
                    inline int EmployeeId() const {
                        return m_EmployeeId;
                    }

                    inline int ProjectsCount() const {
                        return m_ProjectsCount;
                    }
            }
}}

#endif // GRAPH_HPP_INCLUDED
