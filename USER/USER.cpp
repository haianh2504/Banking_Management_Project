#include <iostream>
// #include "../COMPOSITION/Address/Address.h"
// #include "../COMPOSITION/CitizenID/CitizenID.h"
#include "../COMPOSITION/Date/Date.h"
#include "../COMPOSITION/Name/Name.h"
#include "../COMPOSITION/Phone_Number/PhoneNumber.h"
#include "../ACCOUNT/ACCOUNT.h"
#include "../COMPOSITION/Email/Email.h"
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
    User(string username, string password, Name fullname, Date birthDay, Email email, PhoneNumber phonenum, UserRole role = UserRole::USER, AccountStatus status = AccountStatus::ACTIVE):Username(username), Password(password), FullName(fullname), BirthDate(birthDay), EmailAddress(email), PhoneNum(phonenum), Role(role), Status(status) { UserID++; }
    // Getters ( chi tiết )
    long long GetUserID() const { return UserID; }
    string GetUsername() const { return Username; }
    Name GetFullName() const { return FullName; }
    Date GetBirthDate() const { return BirthDate; }
    Email GetEmail() const { return EmailAddress; }
    PhoneNumber GetPhoneNumber() const { return PhoneNum; }
    UserRole GetRole() const { return Role; }
    AccountStatus GetStatus() const { return Status; }
    vector<string> GetLinkedAccounts() const { return LinkedAccounts; }
    // Setter (cập nhật thông tin cá nhân tổng quát)
    void UpdateProfile(const Name &name, Email &email, PhoneNumber &phone)
    {
        // kiểm tra sau đó mới cập nhật
        FullName = name;
        EmailAddress = email;
        PhoneNum = phone;
    }
    // Xác thực mật khẩu
    bool verifyPassword(const string &password) const
    {
        return Password == password;
    }
    // Quản lý tài khoản liên kết
    void LinkAccount(const string &accountNumber)
    {
        LinkedAccounts.push_back(accountNumber);
    }
    void UnlinkAccount(const string &accountNumber)
    {
        LinkedAccounts.erase(remove(LinkedAccounts.begin(), LinkedAccounts.end(), accountNumber), LinkedAccounts.end());
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
long long User::UserID = 0;