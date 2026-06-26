#include <iostream>
using namespace std;
#include "Equipment.h";

/*
   char* name;
    char* serialNumber;
    int quantity;
    eEquipmentStatus status;
*/
 
Equipment::Equipment(const char* name,
              const char* serialNumber,
              int quantity,
              eEquipmentStatus status) : quantity(quantity),status(status)
{
    strcpy(this->name,name);
    strcpy(this->serialNumber,serialNumber);
};
Equipment::~Equipment()
{
    delete[](this->name);    
    delete[](this->serialNumber);
};
const char* Equipment::getName() const
{
    return this->name;
};
const char* Equipment::getSerialNumber() const
{
    return this->serialNumber;
};
int Equipment::getQuantity() const
{
    return this->quantity;
};
eEquipmentStatus Equipment::getStatus() const
{

};

/*
    
    
    

    bool setName(const char* name);
    bool setSerialNumber(const char* serialNumber);
    bool setQuantity(int quantity);
    bool setStatus(eEquipmentStatus status);

    void print() const;
};
*/
