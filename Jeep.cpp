#include <iostream>
#include <string.h>
#include "Jeep.h"
using namespace std;

Jeep::Jeep(const char *vehicleNumber, int maxPassengers)
    : Vehicle(vehicleNumber), passengers(nullptr), passengerCount(0), maxPassengers(maxPassengers)
{
    if (maxPassengers > 0)
    {
        passengers = new Soldier *[maxPassengers];
    }
};

Jeep::~Jeep()
{
    if (passengers)
    {
        delete[] passengers;
    }
};

int Jeep::getMaxPassengers() const
{
    return maxPassengers;
};

int Jeep::getPassengerCount() const
{
    return passengerCount;
};

Soldier *Jeep::getPassenger(int index) const
{
    if (index >= 0 && index < passengerCount)
    {
        return passengers[index];
    }
    return nullptr;
}

bool Jeep::setMaxPassengers(int maxPassengers)
{
    if (maxPassengers <= 0)
    {
        return false;
    }

    Soldier **newPassengers = new Soldier* [maxPassengers];
    int newPassengerCount = (passengerCount < maxPassengers) ? passengerCount : maxPassengers;

    for (int i = 0; i < newPassengerCount; ++i)
    {
        newPassengers[i] = passengers[i];
    }

    delete[] passengers;
    passengers = newPassengers;
    passengerCount = newPassengerCount;
    this->maxPassengers = maxPassengers;

    return true;
}

bool Jeep::loadPassenger(Soldier *soldier)
{
    if (soldier == nullptr || passengerCount >= maxPassengers)
    {
        return false;
    }

    passengers[passengerCount++] = soldier;
    return true;
}

bool Jeep::unloadPassenger(const Soldier *soldier)
{
    if (soldier == nullptr)
    {
        return false;
    }

    for (int i = 0; i < passengerCount; ++i)
    {
        if (passengers[i] == soldier)
        {
            for (int j = i; j < passengerCount - 1; ++j)
            {
                passengers[j] = passengers[j + 1];
            }
            passengerCount--;
            return true;
        }
    }
    return false;
}

// void print() const override;