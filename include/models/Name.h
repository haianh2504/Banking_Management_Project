#ifndef NAME_H
#define NAME_H
#include <string>
class Name
{
    private:
    std::string FirstName;
    std::string MiddleName;
    std::string Surname;
    // trim spaces
    static std::string Trim(std::string &s);
    public:
    // constructor
    Name(std::string firstName, std::string middleName, std::string surName);
    // Check_Valid_Name
    static bool isValidName(std::string &name);
    static bool isValidName(std::string &firstName, std::string &middleName, std::string &surName);
    static void standardizeName(std::string &firstName, std::string &middleName, std::string &surName);
    static void standardizeName(std::string &name);
    // FULL NAME
    bool SetFullName(std::string firstName, std::string middleName, std::string surName);
    Name getName();
    // First Name
    bool SetFirstName(std::string firstName);
    std::string GetFirstName()const;
    // Middle Name
    bool SetMiddleName(std::string middleName);
    std::string GetMiddleName()const;
    // Surname
    bool SetSurName(std::string surName);
    std::string GetSurName()const;
    // destructor
    ~Name();
    
};
#endif