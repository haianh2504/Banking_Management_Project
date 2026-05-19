#include <iostream>
using namespace std;
#include "include/services/User_Service.h"
#include "../models/USER.h"
class UserService
{
    public:
    // Cập nhật thông tin người dùng
    static void UpdateUserProfile(User &user, const Name &name, Email &email, PhoneNumber &phone)
    {
        bool isProfileChanged = false;
        // Lập các điều kiện / Logic để kiểm tra tính hợp lệ của dữ liệu mới
        // Name
        Name userOldName = user.GetFullName();
        Email userOldEmail = user.GetEmail();
        if(userOldName.GetFullName() == name.GetFullName()) { 
            
        }
        else if()
        // vì dữ liệu mới sẽ luôn valid -> kiểm tra xem tên mới có trùng với tên cũ hay không -> tránh tốn kém thêm tài nguyên
        // 
        // sau cùng gọi hàm cập nhật thông tin cá nhân của User
    }
    // Thay đổi mật khẩu
    static void ChangePassword(User &user, const string &newPassword)
    {
       
    };
};