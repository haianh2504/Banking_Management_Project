#include <iostream>
// #include "../COMPOSITION/Address/Address.h"
// #include "../COMPOSITION/CitizenID/CitizenID.h"
#include "../../include/models/Date.h"
#include "../../include/models/Name.h"
#include "../../include/models/PhoneNumber.h"
#include "../../include/models/ACCOUNT.h"
#include "../../include/models/Email.h"
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;
// Phân quyền
enum class UserRole{ADMIN, USER, GUEST};
// Trạng thái tài khoản
enum class AccountStatus{ACTIVE,SUSPENDED,LOCKED,CLOSED};
// ABSTRACT CLASS
class User
{
    private:
    string UserID;
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
    User(const string &username, const string &password, const Name &fullname, const Date &birthDay, const Email &email, const PhoneNumber &phonenum, UserRole role = UserRole::USER, AccountStatus status = AccountStatus::ACTIVE):Username(username), PasswordHash(password), FullName(fullname), BirthDate(birthDay), EmailAddress(email), PhoneNum(phonenum), Role(role), Status(status) {}
    // Getters ( chi tiết )
    const string& GetUserID() const { return UserID; }
    const string& GetUsername() const { return Username; }
    const Name& GetFullName() const { return FullName; }
    const Date& GetBirthDate() const { return BirthDate; }
    const Email& GetEmail() const { return EmailAddress; }
    const PhoneNumber& GetPhoneNumber() const { return PhoneNum; }
    const UserRole& GetRole() const { return Role; }
    const AccountStatus& GetStatus() const { return Status; }
    // Setter (cập nhật thông tin cá nhân tổng quát)
    void UpdateProfile(const Name &name, const Email &email, const PhoneNumber &phone)
    {
        // kiểm tra sau đó mới cập nhật
        FullName = name;
        EmailAddress = email;
        PhoneNum = phone;
    } 
    // Trạng thái tài khoản
    void lock()
    {
        Status = AccountStatus::LOCKED;
    }
    void unlock()
    {
        Status = AccountStatus::ACTIVE;
    }
    bool isLocked()const
    {
        return Status == AccountStatus::LOCKED;
    }
    // Destructor
    ~User() {};
};
