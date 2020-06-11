#pragma once
#include "Event.h"

class Note
{
public:
    int start, duration, channel, pitch, volume; //properties of note

    Note(int s, int d, int c, int p, int v);
    
    //convert to events
    void ToEvents(std::vector<Event> &events);
};
