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
    string PasswordHash; // sau này sẽ được mã hóa
    // Thông tin cá nhân
    Name FullName;
    Date BirthDate;
    Email EmailAddress;
    PhoneNumber PhoneNum;
    // Phân quyền và trạng thái
    UserRole Role;
    AccountStatus Status;
  
    public:
    // Constructor
    User(string username, string password, Name fullname, Date birthDay, Email email, PhoneNumber phonenum, UserRole role = UserRole::USER, AccountStatus status = AccountStatus::ACTIVE); 
    // Getters
    long long GetUserID() const;
    const string& GetUsername() const;
    const Name& GetFullName() const;
    const Date& GetBirthDate() const;
    const Email& GetEmail() const;
    const PhoneNumber& GetPhoneNumber() const;
    const UserRole& GetRole() const;
    const AccountStatus& GetStatus() const;
    // Setters (Update thông tin cá nhân)
    void UpdateProfile(const string &name, Email &email, PhoneNumber &phone);
    // Trạng thái tài khoản
    void lock();
    void unlock();
    bool isLocked()const;

    // Destructor
    ~User();
};

#endif