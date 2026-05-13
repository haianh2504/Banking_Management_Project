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
enum class AccountStatus{ACTIVE,SUSPENDED,LOCKED,CLOSED};
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
    User(string username, string password, Name fullname, Date birthDay, Email email, PhoneNumber phonenum, UserRole role = UserRole::USER, AccountStatus status = AccountStatus::ACTIVE); 
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
    // Setters (Update thông tin cá nhân)
    void UpdateProfile(const string &name, Email &email, PhoneNumber &phone);
    // Xác thực mật khẩu
    bool verifyPassword(const string &password) const;
    // Quản lý tài khoản liên kết
    void LinkAccount(const string &accountNumber);
    void UnlinkAccount(const string &accountNumber);
    // Trạng thái tài khoản
    void lock();
    void unlock();
    bool isLocked()const;

    // Destructor
    ~User();
};

#endif