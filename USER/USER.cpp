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

// enum UserStatus
enum class UserStatus {ACTIVE, LOCKED, PENDING_KYC, DELETED}; // 0, 1, 2, 3
// ABSTRACT CLASS
class User
{
    private:
    // Identification
    CitizenID citizenID;
    // Name
    Name name;
    // Date Of Birth
    Date dateOfBirth;
    // Phone Number
    PhoneNumber phoneNumber;
    // Address
    Address address;
    // EMAIL
    // Status
    UserStatus Status; 
    // SO ACCOUNT
    vector<Account> accounts;
    public:
    // constructor
    User(CitizenID citizen_id, Name namee, Date date_of_birth, PhoneNumber phone_number, Address addr) : citizenID(citizen_id), name(namee), dateOfBirth(date_of_birth), phoneNumber(phone_number), address(addr)
    {
        // check for age validation
        // check for age 
    };
    // destructor
    ~User(){};
    
};
#endif