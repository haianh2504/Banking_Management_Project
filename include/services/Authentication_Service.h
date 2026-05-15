#ifndef AUTHENTICATION_SERVICE_H
#define AUTHENTICATION_SERVICE_H
#include "../models/USER.h"
class AuthenticationService
{
    private:
    AuthenticationService(){}; // private constructor to prevent instantiation
    public:
    // Đăng nhập
    static bool Login(const string &username, const string &password);
    // Đăng xuất
    static void Logout(User &user);
    // Đăng ký
    static User Register(const string &username, const string &password, Name fullname, Date birthDay, Email email, PhoneNumber phonenum);
    // Xác thực mật khẩu
    static bool Authenticate(const User &user, const string &password);
    // Hash Password - làm sau khi có thuật toán hash
};

#endif