#include <iostream>
using namespace std;

class PhoneNumber
{
    private:
    string phoneNumber;
    public:
    // constructor
    PhoneNumber(string phoneNum) : phoneNumber(phoneNum){
        // check for validation

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