#include <iostream>
#include "DateTime.h"
using namespace std;
class DateTime
{
    private:
    Date date;
    Time time;
    public:
    // constructor
    DateTime(Date datee, Time timee) : date(datee), time(timee)
    {
        // kiểm tra logic
        if(!SetDateTime(datee, timee))
        {
            throw invalid_argument("Error: Invalid datetime properties");
        }
    };
    // setter
    bool SetDateTime(Date datee, Time timee)
    {
        if(!date.SetDate(datee.GetDay(), datee.GetMonth(), datee.GetYear()) || !time.SetTime(timee.GetHour(), timee.GetMinute(), timee.GetSecond())) return false;
        date = datee;
        time = timee;
        return true;
    }
    // getter
    Date GetDate() const
    {
        return date;
    }
    Time GetTime() const
    {
        return time;
    }
    // lấy cả đối tượng
    DateTime GetDateTime() const
    {
        return *this;
    }
    // lấy hiển thị
    string GetDateTimeString()const{
        string dateTimeStr = "";
        // dd/mm/yyyy
        dateTimeStr += (date.GetDay() < 10 ? "0" : "") + to_string(date.GetDay()) + "/";
        dateTimeStr += (date.GetMonth() < 10 ? "0" : "") + to_string(date.GetMonth()) + "/";
        dateTimeStr += to_string(date.GetYear()) + " ";
        // hh:mm:ss
        dateTimeStr += (time.GetHour() < 10 ? "0" : "") + to_string(time.GetHour()) + ":";
        dateTimeStr += (time.GetMinute() < 10 ? "0" : "") + to_string(time.GetMinute()) + ":";
        dateTimeStr += (time.GetSecond() < 10 ? "0" : "") + to_string(time.GetSecond());
        return dateTimeStr;
    }
    // destructor
    ~DateTime(){};
};