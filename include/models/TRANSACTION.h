#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include "DateTime.h"
#include "ACCOUNT.h"
using namespace std;
// Transaction là bản ghi ( không thể chỉnh sửa ) của một hành động tài chính đã diễn ra
// Không được sửa đổi sau khi đã tạo ra, chỉ có thể đọc thông tin hay append thêm record mới
enum type_of_transaction{DEPOSIT, WITHDRAW, TRANSFER};
enum transaction_status{PENDING, SUCCESS, FAILED, CANCELLED};
class Transaction
{
    private:
    string TransactionID;
    DateTime timestamp; // sự kết hợp giữa dd/mm/yyyy và hh:mm::ss
    type_of_transaction type;
    long long amount;
    string description;
    string senderAccountId;
    string receiverAccountId;
    transaction_status status;
    public:
    Transaction(string transaction_id, DateTime timestamp, type_of_transaction type, long long amount, string description, string sender_account_id, string receiver_account_id);
    // Getters
    // ID
    string GetTransactionID() const;
    // Timestamp
    DateTime GetTimestamp() const;
    // Transaction Type
    type_of_transaction GetType() const;
    // Amount
    long long GetAmount() const;
    // Status
    transaction_status GetStatus() const;
    // Description
    string GetDescription() const;
    // destructor
    ~Transaction();
};

#endif