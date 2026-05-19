#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
using namespace std;
class Account
{
    private:
    string AccountNumber;
    string PasswordAccount;
    // Money
    long long balance;
    // is_Valid_Account_Number
    static bool isValidAccountNumber(string account_number);
    // is_Secured_Valid_Password
    static bool isSecuredPassword(string password);
    
    public:
    Account(string account_number, string password_account);
    // Account Number
    const string& GetAccountNumber() const;
    // Account password
    bool SetAccountPassword(string newPassword);
    const string& GetAccountPassword() const;
    // destructor
    ~Account();
};
#endif