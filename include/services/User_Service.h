#ifndef USER_SERVICE_H
#define USER_SERVICE_H
#include "../models/USER.h"
class UserService
{
    public:
    // Cập nhật thông tin người dùng
    static void UpdateUserProfile(User &user, const string &name, Email &email, PhoneNumber &phone);
    // Thay đổi mật khẩu
    static void ChangePassword(User &user, const string &newPassword);
    // Link tài khoản với tài khoản ngân hàng
    static void LinkBankAccount(User &user, const Account &account);
    // Quản lý trạng thái tài khoản
    // Khóa tài khoản
    static void LockUserAccount(User &user);
    // Mở khóa tài khoản
    static void UnlockUserAccount(User &user);
};



#endif