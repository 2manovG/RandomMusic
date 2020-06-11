#include "MIDIFile.h"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);
    std::ofstream file(std::to_string(seed) + ".mid");
    
    MIDIFile m;
    
    for (int i = 0; i < 5; i++)
    {
        m.tracks.push_back(Track());
        m.tracks[i].events.push_back(Event(0, {char(0xc0 + i), char(rand() % 128)}));
    
        int pos = 1;
        int lenMin = rand() % 75 + 5, lenDelta = rand() % 200 + 10;
        
        int pitchMin = rand() % 80 + 8, pitchDelta = rand() % 32 + 1, pitch = pitchMin + rand() % pitchDelta;
        int volumeMin = rand() % 32 + 63, volumeDelta = rand() % 32 + 1, volume = volumeMin + rand() % volumeDelta;
        
        while (pos < 10000)
        {
            int len = lenMin + rand() % lenDelta;
            if (rand() % 10)
            {
                m.tracks[i].notes.push_back(Note(pos, len, i, pitch, volume));
            }
            pos += len;
            pitch = std::max(pitchMin, std::min(pitch + rand() % 11 - 5, pitchMin + pitchDelta));
            volume = std::max(volumeMin, std::min(volume + rand() % 7 - 3, volumeMin + volumeDelta));
        }
    }
    
    file << m;
    
    file.close();
	return 0;
}
