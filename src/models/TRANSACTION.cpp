#include <iostream>
#include "ACCOUNT.h"
#include "DateTime.h"
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
    Transaction(string transaction_id, DateTime timestamp, type_of_transaction type, long long amount, string description, string sender_account_id, string receiver_account_id) : TransactionID(transaction_id), timestamp(timestamp), type(type), amount(amount), description(description), senderAccountId(sender_account_id), receiverAccountId(receiver_account_id), status(PENDING)
    {
        // kiểm tra logic
    };
    // Getters
    // ID
    string GetTransactionID() const
    {
        return TransactionID;
    }
    // Timestamp
    DateTime GetTimestamp() const
    {
        return timestamp;
    }
    // Transaction Type
    type_of_transaction GetType() const
    {
        return type;
    }
    // Amount
    long long GetAmount() const
    {
        return amount;
    }
    // Status
    transaction_status GetStatus() const
    {
        return status;
    }
    // Description
    string GetDescription() const
    {
        return description;
    };
    // destructor
    ~Transaction(){};
};