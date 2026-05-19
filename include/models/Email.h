#ifndef EMAIL_H
#define EMAIL_H
#include <regex>
#include <string>
#include <iostream>
using namespace std;
class Email
{
    // Basic setup
    private:
    string emailAddress;
    public:
    // hàm checking validation 
    static bool isValidEmail(const string& newEmail);
    // constructor
    Email();
    Email(const string& email);
    // setter
    void setEmail(const string& email);
    // getter
    string getEmail() const;
    // destructor
    ~Email();
};
#endif