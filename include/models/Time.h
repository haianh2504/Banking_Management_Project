#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;
class Time
{
    private:
    int hour;
    int minute;
    int second;
    public:
    Time(int h, int m, int s);
    // Setters
    bool SetTime(int h, int m, int s);
    // Getters
    int GetHour() const;
    int GetMinute() const;
    int GetSecond() const;
    Time GetTime() const;
    // destructor
    ~Time(){};
};
#endif