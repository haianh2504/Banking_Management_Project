#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


// NAME (Base class)
class Name
{
    private:
    string FirstName;
    string MiddleName;
    string Surname; 
    // trim spaces
    static string Trim(string &s)
    {
        // both head - tail spaces
        size_t first = s.find_first_not_of(' ');
        if (std::string::npos == first) return "";
        size_t last = s.find_last_not_of(' ');
        return s.substr(first, (last - first + 1));

        // middle (if has ) - only 1 space between 
        auto it = std::unique(s.begin(), s.end(), [](char a, char b) {
            return isspace(a) && isspace(b);
        });
        s.erase(it, s.end());
        // return
        return s;
    };

    public:
    // constructor
    Name(string firstName, string middleName, string surName) : FirstName(firstName), MiddleName(middleName), Surname(surName)
    {
        if(!(isValidName(firstName, middleName, surName))) throw invalid_argument("Error: USER's name is invalid!");
        // if pass
        standardizeName(FirstName, MiddleName, Surname);
    }
    // Check_Valid_Name
    static bool isValidName(string &name)
    {
        name = Trim(name);
        if(name.empty()) return false;
        for(int i = 0; i < name.length(); i++)
        {
            if(name[i] == '@' || name[i] == '#' || name[i] == '$' || name[i] == '.' || (name[i] >= '0' && name[i] <= '9'))
            {
                return false;
            }
        }
        if(name.length() < 2 || name.length() > 50) return false;
        return true;
    }
    static bool isValidName(string &firstName, string &middleName, string &surName)
    {
        // Trim
        firstName = Trim(firstName);
        middleName = Trim(middleName);
        surName = Trim(surName);
        // Null input
        if(firstName.empty() || middleName.empty() || surName.empty()) return false;
        // Contain restricted symbols and numbers
        for(int i = 0; i < firstName.length(); i++)
        {
            if(firstName[i] == '@' || firstName[i] == '#' || firstName[i] == '$' || firstName[i] == '.' || (firstName[i] >= '0' && firstName[i] <= '9'))
            {
                return false;
            }
        }
        for(int i = 0; i < middleName.length(); i++)
        {
            if(middleName[i] == '@' || middleName[i] == '#' || middleName[i] == '$' || middleName[i] == '.' || (middleName[i] >= '0' && middleName[i] <= '9'))
            {
                return false;
            }
        }
        for(int i = 0; i < surName.length(); i++)
        {
            if(surName[i] == '@' || surName[i] == '#' || surName[i] == '$' || surName[i] == '.' || (surName[i] >= '0' && surName[i] <= '9'))
            {
                return false;
            }
        }
        // invalid length 
        if(firstName.length() < 2 || firstName.length() > 50 || middleName.length() < 2 || middleName.length() > 50 || surName.length() < 2 || surName.length() > 50)
        {
            return false;
        }
        // valid
        return true;
    }
    // Standardize format
    static void standardizeName(string &name)
    {
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        name[0] = toupper(name[0]);
    }
    static void standardizeName(string &firstName, string &middleName, string &surName)
    {
        // Standardize format
        transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);
        transform(middleName.begin(), middleName.end(), middleName.begin(), ::tolower);
        transform(surName.begin(), surName.end(), surName.begin(), ::tolower);
        firstName[0] = toupper(firstName[0]);
        middleName[0] = toupper(middleName[0]);
        surName[0] = toupper(surName[0]);
    }
 
    // FULL NAME
    bool SetFullName(string firstName, string middleName, string surName)
    {
        if(!(isValidName(firstName, middleName, surName))){
           cout << "Error: USER's name is invalid!" << endl;
           return false;
        }
        // if pass
        FirstName = firstName;
        MiddleName = middleName;
        Surname = surName;
        standardizeName(FirstName, MiddleName, Surname);
        
    }
    Name getName(){
        return *this;
    }
    // First Name
    bool SetFirstName(string firstName)
    {
        if(!(isValidName(firstName))){
            cout << "Error: First name is invalid!" << endl;
            return false;
        }
        standardizeName(firstName);
        FirstName = firstName;
        return true;
    }
    string GetFirstName()const
    {
        return FirstName;
    }
    // Middle Name
    bool SetMiddleName(string middleName)
    {
        if(!(isValidName(middleName))){
            cout << "Error: Middle name is invalid!" << endl;
            return false;
        }
        standardizeName(middleName);
        MiddleName = middleName;
        return true;
    }
    string GetMiddleName()const
    {
        return MiddleName;
    }
    // Surname
    bool SetSurName(string surName)
    {
        if(!(isValidName(surName))){
            cout << "Error: Surname is invalid!" << endl;
            return false;
        }
        standardizeName(surName);
        Surname = surName;
        return true;
    }
    string GetSurName()const
    {
        return Surname;
    }
    
    // destructor
    ~Name(){};
};