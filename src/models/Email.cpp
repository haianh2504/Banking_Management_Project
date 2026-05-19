#include <iostream>
#include <string>
#include "../../include/models/Email.h"
#include <regex>
using namespace std;

class Email
{
    private:
    string emailAddress;
    public:
    // hàm checking validation - sử dụng regex để kiểm tra format email hợp lệ
    // Tầng 1: Format Checker - Hoàn thiện
    // Tàng 2: Domain Checker - ( Chưa hoàn thiện )
    // Tầng 3: OwnerShip Check - ( Chưa hoàn thiện )
    static bool isValidEmail(const string& newEmail){
        // Regex này cân bằng giữa tính thực tế và độ phức tạp theo tiêu chuẩn RFC 5322 bản đơn giản hóa
        // Kiểm tra cấu trúc: [Ký tự hợp lệ] @ [Tên miền] . [Phần mở rộng từ 2 ký tự trở lên]
        const std::regex emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
        return std::regex_match(newEmail, emailRegex);
    }
    // constructor
    Email() : emailAddress("") {}
    Email(const string& email) : emailAddress(email) {}
    // setter
    void setEmail(const string& email) { emailAddress = email; }
    // getter
    string getEmail() const { return emailAddress; }
    // destructor
    ~Email() {};
};