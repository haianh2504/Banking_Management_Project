#ifndef PHONENUMBER_H
#define PHONENUMBER_H
#include <string>
using namespace std;
class PhoneNumber
{
    private:
    std::string phoneNumber;
    public:
    // Hàm checking validation
    static bool isValidPhoneNumber(const std::string& newPhoneNumber);
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