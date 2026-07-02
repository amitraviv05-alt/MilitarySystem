#include <iostream>
#include <string.h>
#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle(const char *vehicleNumber)
{
    this->vehicleNumber = new char[strlen(vehicleNumber) + 1];
    strcpy(this->vehicleNumber, vehicleNumber);
};

Vehicle::~Vehicle()
{
    delete[] vehicleNumber;
    vehicleNumber = nullptr;
};

bool Vehicle::setVehicleNumber(const char* vehicleNumber)
{
    if (vehicleNumber == nullptr)
    {
        return false;
    }
    delete[] this->vehicleNumber;
    this->vehicleNumber = new char[strlen(vehicleNumber) + 1];
    strcpy(this->vehicleNumber, vehicleNumber);
    return true;
};

const char *Vehicle::getVehicleNumber() const
{
    return vehicleNumber;
};

bool Vehicle::getAvailable() const
{
    return available;
};

bool Vehicle::getNeedsMaintenance() const
{
    return needsMaintenance;
};

Soldier *Vehicle::getDriver() const
{
    return driver;
};

bool Vehicle::setAvailability(bool status)
{
    available = status;
    return true;
};

bool Vehicle::sendToMaintenance()
{
    needsMaintenance = true;
    return true;
};

bool Vehicle::setDriver(Soldier *driver)
{
    this->driver = driver;
    return true;
};

std::ostream &operator<<(std::ostream &os, const Vehicle &Vehicle)
    {
        os << "Vehicle Number: " << Vehicle.vehicleNumber
           << " ,Available: " << (Vehicle.available ? "Yes" : "No")
           << " ,Needs Maintenance: " << (Vehicle.needsMaintenance ? "Yes" : "No")
           << " ,Driver: " << (Vehicle.driver ? "Assigned" : "None");
        return os;
    }

//virtual void print() const = 0;