#ifndef CITIZENID_H
#define CITIZENID_H
#include <string>
class CitizenID
{
    private:
    std::string ID; // chuỗi số ID ( 12 ký tự số )
    public:
    // constructor
    CitizenID(std::string id);
    // ID
    bool SetID(std::string id);
    std::string GetID()const;
    // destructor
    ~CitizenID();
    
};
#endif