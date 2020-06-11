#pragma once
#include "Track.h"

//the whole midi file
class MIDIFile
{
public:
    std::vector<Track> tracks; //midi tracks
    
    MIDIFile();
};
//output
std::ostream& operator<<(std::ostream &os, MIDIFile &m);