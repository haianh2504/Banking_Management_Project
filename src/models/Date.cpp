#include <iostream>
using namespace std;


// Followed strict rule -> COMPULSORY to be completed
class Date
{
    private:
    int day;
    int month;
    int year;
    // current Date
    
    static bool isLeapYear(int year)
    {
        return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? true : false;
    }

    public:
    // constructor
    Date(int dayy, int monthh, int yearr) : day(dayy), month(monthh), year(yearr)
    {
        // kiểm tra logic bên trong
        if(!(isValidDate(dayy, monthh, yearr)))
        {
            throw invalid_argument("Error: Date data is invalid!");
        }
    };
    // Check_Valid_Date
    static bool isValidDate(int dayy, int monthh, int yearr)
    {
        // GUARD CLAUSE
        // yearr, dayy, monthh > 0
        if(dayy <= 0 || dayy > 31 || monthh <= 0 || monthh > 12 || yearr <= 0) return false;
        // kiểm tra ngày hợp lệ
        if(monthh == 2)
        {
            if(isLeapYear(yearr))
            {
                return (dayy <= 29) ? true : false;
            }
            return (dayy <= 28) ? true : false;
        }
        else if(monthh == 1 || monthh == 3 || monthh == 5 || monthh == 7 || monthh == 8 || monthh == 10 || monthh == 12)
        {
            return (1 <= dayy && dayy <= 31) ? true : false;
        }
        else
        {
            return (1 <= dayy && dayy <= 30) ? true : false;
        }
    }
    // setter ( day - month - year )
    bool SetDate(int dayy, int monthh, int yearr)
    {
        if(!(isValidDate(dayy,monthh,yearr)))
        {
            cout << "Error: Date data is invalid" << endl;
            return false;
        }
        else
        {
            day = dayy;
            month = monthh;
            year = yearr;
        }
        return true;
    };
    Date GetDate()const
    {
        return *this;
    }
    // day
    bool SetDay(int dayy)
    {
        if(!(isValidDate(dayy, month, year)))
        {
            cout << "Error: Day is invalid!" << endl;
            return false;
        }
        day = dayy;
        return true;
    }
    int GetDay()const
    {
        return day;
    }
    // month
    bool SetMonth(int monthh)
    {
        if(!(isValidDate(day, monthh, year)))
        {
            cout << "Error: Month is invalid!" << endl;
            return false;
        }
        month = monthh;
        return true;
    }
    int GetMonth()const
    {
        return month;
    }
    // year
    bool SetYear(int yearr)
    {
        if(!(isValidDate(day, month, yearr)))
        {
            cout << "Error: Year is invalid!" << endl;
            return false;
        }
        year = yearr;
        return true;
    }
    int GetYear()const
    {
        return year;
    }
    // destructor
    ~Date(){};
};
