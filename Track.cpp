#include "Track.h"

Track::Track()
{
}

//track data
void Track::GetEvents(std::vector<char> &data)
{
    //make vector of events
    std::vector<Event> output = events;
    
    //add notes
    for (Note &n : notes) n.ToEvents(output);
    
    //sort events
    std::sort(output.begin(), output.end(), [](Event &a, Event &b) { return a.time < b.time; });
    
    //write events
    int ptime = 0;
    for (Event &e : output)
    {
        e.Export(data, ptime);
        ptime = e.time;
    }
    
    //end
    data.push_back(0x7f);
    data.push_back(0xff);
    data.push_back(0x2f);
    data.push_back(0x00);
}

//output
std::ostream& operator<<(std::ostream &os, Track &t)
{
    //first few bytes
    char header[] = { 0x4d, 0x54, 0x72, 0x6b };
    os.write(header, sizeof(header));
    
    //events
    std::vector<char> data;
    t.GetEvents(data);
    
    //write length
    int len = data.size();
    for (int i = 3; i >= 0; i--) os.write((char*)(&len) + i, sizeof(char));
    
    //write data
    os.write(&(data[0]), sizeof(char) * len);
    return os;
}