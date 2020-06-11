#include "MIDIFile.h"

MIDIFile::MIDIFile()
{
}

//output
std::ostream& operator<<(std::ostream &os, MIDIFile &m)
{
    //first few bytes
    char header[] = { 0x4d, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x01, 0x00 };
    os.write(header, sizeof(header));
    
    //number of tracks
    char num = (char)m.tracks.size();
    os.write(&num, sizeof(num));
    
    //number of pulses will be 96
    char pulses[] = { 0x00, 0x60 };
    os.write(pulses, sizeof(pulses));
    
    //write all tracks
    for (Track &t : m.tracks) os << t;
    return os;
}