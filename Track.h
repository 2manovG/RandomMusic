#pragma once
#include <ostream>
#include <algorithm>
#include "Note.h"

class Track
{
public:
    std::vector<Event> events; //events themselves
    std::vector<Note> notes; //just pair of events
    
    Track();
    
    //track data
    void GetEvents(std::vector<char> &data);
};
//output
std::ostream& operator<<(std::ostream &os, Track &t);