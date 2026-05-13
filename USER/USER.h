#ifndef USER_H
#define USER_H
#include <iostream>
// #include "../COMPOSITION/Address/Address.h"
// #include "../COMPOSITION/CitizenID/CitizenID.h"
#include "../COMPOSITION/Date/Date.h"
#include "../COMPOSITION/Name/Name.h"
#include "../COMPOSITION/Phone_Number/PhoneNumber.h"
#include "../COMPOSITION/Email/Email.h"
#include "../ACCOUNT/ACCOUNT.h"
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

// Phân quyền
enum class UserRole{ADMIN, USER, GUEST};
// Trạng thái tài khoản
enum class AccountStatus{ACTIVE, LOCKED, PENDING};
class User
{
    // Định danh & định danh hệ thống
    private:
    static long long UserID;
    string Username;
    string Password; // sau này sẽ được mã hóa
    // Thông tin cá nhân
    Name FullName;
    Date BirthDate;
    Email EmailAddress;
    PhoneNumber PhoneNum;
    // Phân quyền và trạng thái
    UserRole Role;
    AccountStatus Status;
    // Tài khoản liên kết
    vector<string> LinkedAccounts;
    public:
    // Constructor
    User(string username, string password, Name fullname, Date birthDay, Email email, PhoneNumber phonenum, UserRole role = UserRole::USER, AccountStatus status = AccountStatus::PENDING); 
    // Getters
    long long GetUserID() const;
    string GetUsername() const;
    Name GetFullName() const;
    Date GetBirthDate() const;
    Email GetEmail() const;
    PhoneNumber GetPhoneNumber() const;
    UserRole GetRole() const;
    AccountStatus GetStatus() const;
    vector<string> GetLinkedAccounts() const;
    // Setters
    void SetPassword(string newPassword);
    void SetFullName(Name newFullName);
    void SetBirthDate(Date newBirthDate);
    void SetEmail(Email newEmail);
    void SetPhoneNumber(PhoneNumber newPhoneNumber);
    void SetRole(UserRole newRole);
    void SetStatus(AccountStatus newStatus);
    void AddLinkedAccount(const string& account);
    void RemoveLinkedAccount(const string& account);
    // Destructor
    ~User();
};

#endif