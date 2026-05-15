#include <iostream>
#include "Time.h"
using namespace std;
class Time
{
    private:
    int hour;
    int minute;
    int second;
    // hàm kiểm tra
    static bool isValidTime(int h, int m, int s){
        if(h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) return false;
        return true;
    }
    public:
    Time(int h, int m, int s) : hour(h), minute(m), second(s)
    {
        // kiểm tra logic
        if(!SetTime(h, m, s))
        {
            throw invalid_argument("Error: Invalid time properties");
        }
    };
    // Setters
    bool SetTime(int h, int m, int s)
    {
        if(!isValidTime(h, m, s)) return false;
        hour = h;
        minute = m;
        second = s;
        return true;
    }
    // Getters
    int GetHour() const
    {
        return hour;
    }
    int GetMinute() const
    {
        return minute;
    }
    int GetSecond() const
    {
        return second;
    }
    Time GetTime() const
    {
        return *this;
    }
};