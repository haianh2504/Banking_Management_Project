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
#include <stdexcept>
using namespace std;
// Phân quyền
enum class UserRole{ADMIN, USER, GUEST};
// Trạng thái tài khoản
enum class AccountStatus{ACTIVE, LOCKED, PENDING};
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
    User(string username, string password, Name fullname, Date birthDay, Email email, PhoneNumber phonenum, UserRole role = UserRole::USER, AccountStatus status = AccountStatus::PENDING):Username(username), Password(password), FullName(fullname), BirthDate(birthDay), EmailAddress(email), PhoneNum(phonenum), Role(role), Status(status) { UserID++; }
    // Getters
    long long GetUserID() const { return UserID; }
    string GetUsername() const { return Username; }
    Name GetFullName() const { return FullName; }
    Date GetBirthDate() const { return BirthDate; }
    Email GetEmail() const { return EmailAddress; }
    PhoneNumber GetPhoneNumber() const { return PhoneNum; }
    UserRole GetRole() const { return Role; }
    AccountStatus GetStatus() const { return Status; }
    vector<string> GetLinkedAccounts() const { return LinkedAccounts; }
    // Setters
    void SetPassword(string newPassword) { Password = newPassword; }
    void SetFullName(Name newFullName) { FullName = newFullName; }
    void SetBirthDate(Date newBirthDate) { BirthDate = newBirthDate; }
    void SetEmail(Email newEmail) { EmailAddress = newEmail; }
    void SetPhoneNumber(PhoneNumber newPhoneNumber) { PhoneNum = newPhoneNumber; }
    void SetRole(UserRole newRole) { Role = newRole; }
    void SetStatus(AccountStatus newStatus) { Status = newStatus; }
    void AddLinkedAccount(const string& account) { LinkedAccounts.push_back(account); }
    // Destructor
    ~User() {};
};