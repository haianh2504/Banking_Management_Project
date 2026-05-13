#include <iostream>
using namespace std;

class Email
{
    private:
    string emailAddress;
    public:
    Email() : emailAddress("") {}
    Email(const string& email) : emailAddress(email) {}
    void setEmail(const string& email) { emailAddress = email; }
    string getEmail() const { return emailAddress; }
    ~Email() {};
};