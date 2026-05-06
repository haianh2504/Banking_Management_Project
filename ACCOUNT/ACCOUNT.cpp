#include <iostream>
using namespace std;

class Account
{
    private:
    string AccountNumber;
    string PasswordAccount;
    // is_Valid_Account_Number
    static bool isValidAccountNumber(string account_number)
    {
        // empty / spaces / words / symbols / dots.. -> only numbers 0 -> 9
        if(account_number.length() != 14) return false;
        for(int i = 0; i < account_number.length(); i++)
        {
            if('0' <= account_number[i] && account_number[i] <= '9') return false;
        };
        // if pass
        return true;
    };
    // is_Secured_Valid_Password
    static bool isSecuredPassword(string password)
    {
        // 
        return true;
    }
    public:
    Account(string account_number, string password_account) : AccountNumber(account_number),PasswordAccount(password_account)
    {
        // kiểm tra logic
        if(!(isValidAccountNumber(account_number)) || !(isSecuredPassword(password_account)))
        {
            throw invalid_argument("Error: Invalid account properties");
        }
    };
    // Account Number
    string GetAccountNumber()
    {
        return AccountNumber;
    };
    // Account password
    bool SetAccountPassword(string newPassword)
    {
        if(!(isSecuredPassword(newPassword))) return false;
        PasswordAccount = newPassword;
        return true;
    }
    string GetAccountPassword()
    {
        return PasswordAccount;
    }
    // destructor
    ~Account(){};
};