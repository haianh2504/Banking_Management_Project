#ifndef ACCOUNT_SERVICE_H
#define ACCOUNT_SERVICE_H
#include "../models/ACCOUNT.h"
class AccountService
{
    public:
    // Tạo tài khoản mới
    static Account CreateAccount(string account_number, string password);
    // Cập nhật mật khẩu tài khoản
    static bool UpdateAccountPassword(Account &account, string newPassword);
    // Kiểm tra số dư tài khoản
    static long long CheckBalance(const Account &account);
    // Liệt kê giao dịch của tài khoản (sẽ cần thêm TransactionService để lấy thông tin giao dịch)
    static void ListTransactions(const Account &account);
};
#endif