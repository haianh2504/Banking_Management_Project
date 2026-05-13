#ifndef DATE_H
#define DATE_H
#include <string>
class Date
{
    private:
    int day;
    int month;
    int year;
    // Leap year
    static bool isLeapYear(int year);

    public:
    // constructor
    Date(int dayy, int monthh, int yearr);
    // Check_Valid_Date
    static bool isValidDate(int dayy, int monthh, int yearr);
    // setter ( day - month - year )
    bool SetDate(int dayy, int monthh, int yearr);
    Date GetDate()const;
    // day
    bool SetDay(int dayy);
    int GetDay()const;
    // month
    bool SetMonth(int monthh);
    int GetMonth()const;
    // year
    bool SetYear(int yearr);
    int GetYear()const;
    // destructor
    ~Date();
    
};
#endif