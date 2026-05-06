#ifndef USER_H
#define USER_H
#include <iostream>
#include "../COMPOSITION/Address/Address.h"
#include "../COMPOSITION/CitizenID/CitizenID.h"
#include "../COMPOSITION/Date/Date.h"
#include "../COMPOSITION/Name/Name.h"
#include "../COMPOSITION/Phone_Number/PhoneNumber.h"
#include "../ACCOUNT/ACCOUNT.h"
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class User
{
    private:
    // Identification
    CitizenID citizenID;
    // Name
    Name name;
    // DateBirth
    Date dateOfBirth;
    // PhoneNumber
    PhoneNumber phoneNumber;
    // Address address;
    Address address;
    // Account Quantity
    vector<Account> accounts;
    public:
    // constructor
    User(CitizenID citizen_id, Name namee, Date date_of_birth, PhoneNumber phone_number, Address addr) : citizenID(citizen_id), name(namee), dateOfBirth(date_of_birth), phoneNumber(phone_number), address(addr){};
    
};

#endif