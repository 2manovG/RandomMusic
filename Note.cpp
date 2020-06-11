#include "Note.h"

Note::Note(int s, int d, int c, int p, int v) :
    start(s), duration(d), channel(c), pitch(p), volume(v)
{
    
}

//convert to events
void Note::ToEvents(std::vector<Event> &events)
{
    char p = char(pitch), v = char(volume);
    
    events.push_back(Event(start, {char(0x90 + channel), p, v}));
    events.push_back(Event(start + duration, {char(0x80 + channel), p, v}));
}