#include <iostream>
using namespace std;
#include "LogisticsMission.h"



LogisticsMission::LogisticsMission(const char* missionName, Unit* assignedUnit)
    : Mission(missionName, assignedUnit), assignedVehicle(nullptr), requiredCount(0), requiredCapacity(10)
{
    this->requiredEquipment = new Equipment*[this->requiredCapacity];
    for (int i = 0; i < this->requiredCapacity; i++) {
        this->requiredEquipment[i] = nullptr;
    }
}

LogisticsMission::~LogisticsMission()
{
    delete[] this->requiredEquipment;
}
Vehicle* LogisticsMission:: getAssignedVehicle() const
{
    return this->assignedVehicle;
}
int LogisticsMission::getRequiredEquipmentCount() const
{
    return this->requiredCount;
}

Equipment* LogisticsMission::getRequiredEquipment(int index) const
{
    if (index < 0 || index >= this->requiredCount) {
        return nullptr;
    }
    return this->requiredEquipment[index];
}

bool LogisticsMission::setAssignedVehicle(Vehicle* vehicle)
{
    this->assignedVehicle = vehicle;
    return true;
}

bool LogisticsMission::addEquipment(Equipment* equipment)
{
    if (equipment == nullptr) {
        return false;
    }

    if (this->requiredCount >= this->requiredCapacity) {
        int newCapacity = this->requiredCapacity * 2;
        Equipment** temp = new Equipment*[newCapacity];
        for (int i = 0; i < this->requiredCapacity; i++) {
            temp[i] = this->requiredEquipment[i];
        }
        for (int i = this->requiredCapacity; i < newCapacity; i++) {
            temp[i] = nullptr;
        }
        delete[] this->requiredEquipment;
        this->requiredEquipment = temp;
        this->requiredCapacity = newCapacity;
    }

    this->requiredEquipment[this->requiredCount] = equipment;
    this->requiredCount++;
    return true;
}

bool LogisticsMission::removeEquipment(const Equipment* equipment)
{
    if (equipment == nullptr) {
        return false;
    }

    int targetIndex = -1;
    for (int i = 0; i < this->requiredCount; i++) {
        if (this->requiredEquipment[i] == equipment) {
            targetIndex = i;
            break;
        }
    }

    if (targetIndex == -1) {
        return false;
    }

    for (int i = targetIndex; i < this->requiredCount - 1; i++) {
        this->requiredEquipment[i] = this->requiredEquipment[i + 1];
    }

    this->requiredEquipment[this->requiredCount - 1] = nullptr;
    this->requiredCount--;
    return true;
}
/*
#ifndef LOGISTICS_MISSION_H
#define LOGISTICS_MISSION_H

#include "Mission.h"
class Equipment;

class Vehicle;

class LogisticsMission : public Mission {
private:
    Vehicle* assignedVehicle;

    Equipment** requiredEquipment;
    int requiredCount;
    int requiredCapacity;

public:
    LogisticsMission(const char* missionName, Unit* assignedUnit);
    ~LogisticsMission();

    LogisticsMission(const LogisticsMission& other) = delete;
    LogisticsMission& operator=(const LogisticsMission& other) = delete;

    Vehicle*   getAssignedVehicle() const;
    int        getRequiredEquipmentCount() const;
    Equipment* getRequiredEquipment(int index) const;

    bool setAssignedVehicle(Vehicle* vehicle);

    bool addEquipment(Equipment* equipment);
    bool removeEquipment(const Equipment* equipment);

    void print() const override;
};

#endif // LOGISTICS_MISSION_H

*/