#ifndef TRANSACTION_SERVICE_H
#define TRANSACTION_SERVICE_H
#include "../models/TRANSACTION.h"
class TransactionService
{
    public:
    // Tạo giao dịch mới - hàm này có thể thực hiện cho cả 3 loại giao dịch (DEPOSIT, WITHDRAW, TRANSFER)
    static Transaction CreateTransaction(DateTime timestamp, type_of_transaction type, long long amount, string description, string sender_account_id, string receiver_account_id);
    // Xử lý giao dịch (thực hiện các bước cần thiết để hoàn thành giao dịch)
    static void ProcessTransaction(Transaction &transaction);
    // Hủy giao dịch
    static void CancelTransaction(Transaction &transaction);
    // Deposit tiền vào tài khoản
    static void Deposit(string account_id, long long amount, string description);
    // withdraw tiền từ tài khoản
    static void WithDraw(string account_id, long long amount, string description);
    // Transfer tiền giữa 2 tài khoản
    static void Transfer(string sender_account_id, string receiver_account_id, long long amount, string description);
};
#endif