#ifndef DateTime_H
#define DateTime_H
#include <iostream>
#include <string>
#include "Time.h"
#include <Date.h>
using namespace std;
class DateTime
{
    private:
    Date date;
    Time time;
    public:
    // constructor
    DateTime(Date datee, Time timee);
    // setter
    bool SetDateTime(Date datee, Time timee);
    // getter
    Date GetDate() const;
    Time GetTime() const;
    DateTime GetDateTime() const; // cách lấy 1
    string GetDateTimeString() const; // cách lấy 2 ( dd/mm/yyyy hh:mm:ss )
    // destructor
    ~DateTime(){};
};
#endif