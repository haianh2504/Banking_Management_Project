#ifndef PHONENUMBER_H
#define PHONENUMBER_H
#include <string>

class PhoneNumber
{
    private:
    std::string phoneNumber;
    public:
    // constructor
    PhoneNumber(std::string phoneNum);
    // setter
    bool SetPhoneNumber(std::string phoneNum);
    // getter
    std::string GetPhoneNumber() const;
    // destructor
    ~PhoneNumber();
};

#endif