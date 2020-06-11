#pragma once
#include <vector>

class Event
{
public:
    int time; //time, when this event occures
    std::vector<char> data; //event itself

    Event();
    Event(int time_, std::vector<char> &data_);
    Event(int time_, std::vector<char> &&data_);
    
    //write own data
    void Export(std::vector<char> &output, int ptime);
};
