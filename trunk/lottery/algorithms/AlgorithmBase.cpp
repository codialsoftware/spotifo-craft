#include "AlgorithmBase.h"
#include <cmath>
#include <algorithm>
using namespace SpotifyPuzzles::Lottery::Algorithms::impl;

void AlgorithmBase::initialize(int attendees, int drawn, int tickets, int friends) {
    m_Friends = friends;
    m_Attendees = attendees;
    m_Drawns = drawn;
    m_Tickets = tickets;

    // minimum # of friends which must be drawn, so the entire group of friends can get tickets
    m_MinFriendsDrawn = (int)ceil((float)Friends() / Tickets());
    // # of additions
    m_NumeratorSteps = std::min(Friends(), Drawns()) - MinFriendsDrawn();
}

void AlgorithmBase::initialize(int attendees, int drawn, int tickets, int friends) const {
    const_cast<AlgorithmBase*>(this)->initialize(attendees, drawn, tickets, friends);
}
