#ifndef ALGORITHMBASE_H_INCLUDED
#define ALGORITHMBASE_H_INCLUDED

namespace SpotifyPuzzles { namespace Lottery { namespace Algorithms {
    namespace impl {
        class AlgorithmBase {
                int m_Friends;
                int m_Attendees;
                int m_Drawns;
                int m_Tickets;
                int m_MinFriendsDrawn;
                int m_NumeratorSteps;

             protected:
               void initialize(int attendees, int drawn, int tickets, int friends);
               // a bit cheatty...
               void initialize(int attendees, int drawn, int tickets, int friends) const;

                inline int Friends() const { return m_Friends; }
                inline int Attendees() const { return m_Attendees; }
                inline int Drawns() const { return m_Drawns; }
                inline int Tickets() const { return m_Tickets; }
                inline int MinFriendsDrawn() const { return m_MinFriendsDrawn; }
                inline int NumeratorSteps() const { return m_NumeratorSteps; }
                inline int Opponents() const {
                    return Attendees() - Friends();
                }
        };
    }
}}}
#endif // ALGORITHMBASE_H_INCLUDED
