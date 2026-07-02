#include <iostream>
#include <cstring>
#include "Truck.h"
#include "Equipment.h"

using namespace std;

Truck::Truck(const char* vehicleNumber, double maxWeightKG)
    : Vehicle(vehicleNumber), 
      loadedCount(0),
      maxWeightKG(maxWeightKG)
{
    for (int i = 0; i < loadedCapacity; i++) {
        this->loadedEquipment[i] = nullptr;
    }
}

Truck::~Truck()
{
}

int Truck::getLoadedCount() const
{
    return this->loadedCount;
}

Equipment* Truck::getLoadedEquipment(int index) const
{
    if (index < 0 || index >= this->loadedCount) {
        return nullptr;
    }
    return this->loadedEquipment[index];
}

double Truck::getMaxWeightKG() const
{
    return this->maxWeightKG;
}

bool Truck::setMaxWeightKG(double maxWeightKG)
{
    if (maxWeightKG < 0) {
        return false;
    }
    this->maxWeightKG = maxWeightKG;
    return true;
}

bool Truck::loadEquipment(Equipment* equipment)
{
    if (equipment == nullptr || this->loadedCount >= loadedCapacity) {
        return false;
    }

    this->loadedEquipment[this->loadedCount] = equipment;
    this->loadedCount++;
    return true;
}

bool Truck::unloadEquipment(const Equipment* equipment)
{
    if (equipment == nullptr) {
        return false;
    }

    int targetIndex = -1;

    for (int i = 0; i < this->loadedCount; i++) {
        if (this->loadedEquipment[i] == equipment) {
            targetIndex = i;
            break;
        }
    }

    if (targetIndex == -1) {
        return false;
    }

    for (int i = targetIndex; i < this->loadedCount - 1; i++) {
        this->loadedEquipment[i] = this->loadedEquipment[i + 1];
    }

    this->loadedEquipment[this->loadedCount - 1] = nullptr;
    this->loadedCount--;
    return true;
}