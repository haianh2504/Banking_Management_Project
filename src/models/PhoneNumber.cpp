#include <iostream>
#include <string>
#include <regex>
#include <stdexcept>

using namespace std;

class PhoneNumber
{
    private:
    string phoneNumber;
    public:
    // Hàm checking validation
    static bool isValidPhoneNumber(const string &newPhoneNumber)
    {
        // Biểu thức chính quy kiểm tra định dạng số điện thoại Việt Nam
        const std::regex phoneRegex(R"(^0[35789][0-9]{8}$)");
        
        return std::regex_match(newPhoneNumber, phoneRegex);
    }
    // constructor
    PhoneNumber(string phoneNum) : phoneNumber(phoneNum){
        // check for validation
        if(!isValidPhoneNumber(phoneNum)) throw invalid_argument("Error: Invalid PhoneNumber");
    }
    // setter
    bool SetPhoneNumber(string phoneNum)
    {
        // check for validation
        // null
        if(phoneNum.empty() || phoneNum.length() != 10)
        {
            throw invalid_argument("Error: PHONE's NUMBER is invalid!" );
        }
        // contain only number 0 -> 9
        for(int i = 0; i < phoneNum.length(); i++)
        {
            if(phoneNum[i] != '0' && phoneNum[i] != '1' && phoneNum[i] != '2' && phoneNum[i] != '3' && phoneNum[i] != '4' && phoneNum[i] != '5' && phoneNum[i] != '6' && phoneNum[i] != '7' && phoneNum[i] != '8' && phoneNum[i] != '9')
            {
                throw invalid_argument("Error: PHONE's NUMBER is invalid!");
                
            }
        };
        phoneNumber = phoneNum;
        return true;
    }
    // getter
    string GetPhoneNumber() const
    {
        return phoneNumber;
    }
    // destructor
    ~PhoneNumber(){};
};