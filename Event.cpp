#include "Event.h"

Event::Event()
{
    
}
Event::Event(int time_, std::vector<char> &data_)
{
    time = time_;
    data = data_;
}
Event::Event(int time_, std::vector<char> &&data_)
{
    time = time_;
    data = data_;
}

//write own data
void Event::Export(std::vector<char> &output, int ptime)
{
    //export delay
    int delay = time - ptime;
    char byteor = 0;
    
    std::vector<char> delay_bytes;
    do
    {
        delay_bytes.push_back((delay & 0x7F) | byteor);
        delay >>= 7;
        if (!byteor) byteor = 0x80;
    }
    while (delay); //!= 0
    
    for (int i = delay_bytes.size() - 1; i >= 0; i--)
        output.push_back(delay_bytes[i]);
        
    //add rest of bytes
    output.insert(output.end(), data.begin(), data.end());
}
