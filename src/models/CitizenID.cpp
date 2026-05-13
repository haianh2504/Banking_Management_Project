#include <iostream>
using namespace std;

class CitizenID
{
    private:
    string ID; // chuỗi số ID ( 12 ký tự số )
    public:
    // constructor
    CitizenID(string id) : ID(id)
    {
        // check for validation
        // null
        if(id.empty() || id.length() != 12)
        {
            throw invalid_argument("Error: USER's ID is invalid!" );
        }
        // contain only number 0 -> 9
        for(int i = 0; i < id.length(); i++)
        {
            if(id[i] != '0' && id[i] != '1' && id[i] != '2' && id[i] != '3' && id[i] != '4' && id[i] != '5' && id[i] != '6' && id[i] != '7' && id[i] != '8' && id[i] != '9')
            {
                throw invalid_argument("Error: USER's ID is invalid!");
                
            }
        };
    }
    // ID
    bool SetID(string id)
    {
        // null
        if(id.empty() || id.length() != 12)
        {
            cout << "Error: USER's ID is invalid!" << endl;
            return false;
        }
        // contain only number 0 -> 9
        for(int i = 0; i < id.length(); i++)
        {
            if(id[i] != '0' && id[i] != '1' && id[i] != '2' && id[i] != '3' && id[i] != '4' && id[i] != '5' && id[i] != '6' && id[i] != '7' && id[i] != '8' && id[i] != '9')
            {
                cout << "Error: USER's ID is invalid!" << endl;
                return false;
            }
        };
        // if passes
        ID = id;
        return true;
    }
    string GetID()const
    {
        return ID;
    }
    // destructor
    ~CitizenID(){};
    
};