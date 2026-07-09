#include <iostream>
using namespace std;
#include "MilitarySystem.h"
#include "BaseFacility.h"
#include "Soldier.h"
#include "Unit.h"
#include "Mission.h"
#include "Warehouse.h"
#include "Vehicle.h"
#include "Equipment.h"
#include "Report.h"

MilitarySystem::MilitarySystem():base(), soldiersCount(0), soldiersCapacity(10),
      unitsCount(0), unitsCapacity(10),
      missionsCount(0), missionsCapacity(10)
{
    this->soldiers = new Soldier*[this->soldiersCapacity];
    for (int i = 0; i < this->soldiersCapacity; i++) {
        this->soldiers[i] = nullptr;
    }

    this->units = new Unit*[this->unitsCapacity];
    for (int i = 0; i < this->unitsCapacity; i++) {
        this->units[i] = nullptr;
    }

    this->missions = new Mission*[this->missionsCapacity];
    for (int i = 0; i < this->missionsCapacity; i++) {
        this->missions[i] = nullptr;
    }
}

MilitarySystem::~MilitarySystem()
{
    for (int i = 0; i < this->soldiersCount; i++) {
        delete this->soldiers[i];
    }
    delete[] this->soldiers;

    for (int i = 0; i < this->unitsCount; i++) {
        delete this->units[i];
    }
    delete[] this->units;

    for (int i = 0; i < this->missionsCount; i++) {
        delete this->missions[i];
    }
    delete[] this->missions;
}

bool MilitarySystem::addSoldier(const char* name, const Date& birthDate, const char* role, Soldier::eRank rank)
{
    if (this->soldiersCount >= this->soldiersCapacity) {
        int newCapacity = this->soldiersCapacity * 2;
        Soldier** temp = new Soldier*[newCapacity];
        for (int i = 0; i < this->soldiersCapacity; i++) {
            temp[i] = this->soldiers[i];
        }
        for (int i = this->soldiersCapacity; i < newCapacity; i++) {
            temp[i] = nullptr;
        }
        delete[] this->soldiers;
        this->soldiers = temp;
        this->soldiersCapacity = newCapacity;
    }
    return false;
}

bool MilitarySystem::addOfficer(const char* name, const Date& birthDate, const char* role, Soldier::eRank rank)
{
    return false;
}

const Soldier* MilitarySystem::findSoldier(int personalNumber) const
{
    for (int i = 0; i < this->soldiersCount; i++) {
        if (this->soldiers[i]->getPersonalNumber() == personalNumber) {
            return this->soldiers[i];
        }
    }
    return nullptr;
}

bool MilitarySystem::addUnit(const char* unitName)
{
    if (this->unitsCount >= this->unitsCapacity) {
        int newCapacity = this->unitsCapacity * 2;
        Unit** temp = new Unit*[newCapacity];
        for (int i = 0; i < this->unitsCapacity; i++) {
            temp[i] = this->units[i];
        }
        for (int i = this->unitsCapacity; i < newCapacity; i++) {
            temp[i] = nullptr;
        }
        delete[] this->units;
        this->units = temp;
        this->unitsCapacity = newCapacity;
    }
    return false;
}

const Unit* MilitarySystem::findUnit(int unitId) const
{
    for (int i = 0; i < this->unitsCount; i++) {
        if (this->units[i]->getUnitId() == unitId) {
            return this->units[i];
        }
    }
    return nullptr;
}

bool MilitarySystem::assignSoldierToUnit(int personalNumber, int unitId)
{
    return false;
}

bool MilitarySystem::transferSoldier(int personalNumber, int newUnitId)
{
    return false;
}

bool MilitarySystem::addWarehouse(const char* name)
{
    return false;
}

const Warehouse* MilitarySystem::findWarehouse(const char* name) const
{
    return this->base.findWarehouse(name);
}

bool MilitarySystem::addEquipment(const char* warehouseName, const char* equipmentName, const char* serialNumber, int quantity, Equipment::eEquipmentStatus status)
{
    return false;
}

Vehicle* MilitarySystem::findVehicle(const char* vehicleNumber) const
{
    return const_cast<Vehicle*>(this->base.findVehicle(vehicleNumber));
}

bool MilitarySystem::setVehicleDriver(const char* vehicleNumber, int personalNumber)
{
    return false;
}

bool MilitarySystem::addTrainingMission(const char* missionName, int unitId, TrainingMission::eTrainingType trainingType, TrainingMission::eDifficultyLevel difficultyLevel)
{
    if (this->missionsCount >= this->missionsCapacity) {
        int newCapacity = this->missionsCapacity * 2;
        Mission** temp = new Mission*[newCapacity];
        for (int i = 0; i < this->missionsCapacity; i++) {
            temp[i] = this->missions[i];
        }
        for (int i = this->missionsCapacity; i < newCapacity; i++) {
            temp[i] = nullptr;
        }
        delete[] this->missions;
        this->missions = temp;
        this->missionsCapacity = newCapacity;
    }
    return false;
}

int MilitarySystem::addLogisticsMission(const char* missionName, int unitId)
{
    return -1;
}

Mission* MilitarySystem::findMission(int missionId) const
{
    for (int i = 0; i < this->missionsCount; i++) {
        if (this->missions[i]->getMissionId() == missionId) {
            return this->missions[i];
        }
    }
    return nullptr;
}

bool MilitarySystem::setMissionVehicle(int missionId, const char* vehicleNumber)
{
    return false;
}

bool MilitarySystem::addMissionEquipment(int missionId, const char* warehouseName, const char* equipmentName)
{
    return false;
}

BaseFacility& MilitarySystem::getBase()
{
    return this->base;
}

const BaseFacility& MilitarySystem::getBase() const
{
    return this->base;
}

void MilitarySystem::printAllUnits() const
{
    for (int i = 0; i < this->unitsCount; i++) {
        cout<< *this->units[i];
    }
}

void MilitarySystem::printAllMissions() const
{
    for (int i = 0; i < this->missionsCount; i++) {
        cout << *this->missions[i] << "\n";
    }
}

int MilitarySystem::getMissionsCount() const
{
    return this->missionsCount;
}

Report MilitarySystem::generateReport() const
{
    int totalEquipment = 0;
    for (int i = 0; i < this->base.getWarehouseCount(); i++) {
        if (this->base.getWarehouse(i) != nullptr) {
            totalEquipment += this->base.getWarehouse(i)->getEquipmentCount();
        }
    }
    return Report(this->soldiersCount,this->unitsCount,this->base.getVehicleCount(),totalEquipment,this->missionsCount);
}

void MilitarySystem::printAllData() const
{
    this->base.print();
    this->printAllUnits();
    this->printAllMissions();
}

/*
class MilitarySystem {
private:
    Soldier**   soldiers;
    int         soldiersCount;
    int         soldiersCapacity;

    Unit**      units;
    int         unitsCount;
    int         unitsCapacity;

    Mission**   missions;
    int         missionsCount;
    int         missionsCapacity;

    BaseFacility base;

public:
    MilitarySystem();
    ~MilitarySystem();

    MilitarySystem(const MilitarySystem& other) = delete;
    MilitarySystem& operator=(const MilitarySystem& other) = delete;

    bool addSoldier(const char* name,
                    const Date& birthDate,
                    const char* role,
                    Soldier::eRank rank);
    bool addOfficer(const char* name,
                    const Date& birthDate,
                    const char* role,
                    Soldier::eRank rank);
    const Soldier* findSoldier(int personalNumber) const;

    bool addUnit(const char* unitName);
    const Unit* findUnit(int unitId) const;
    bool assignSoldierToUnit(int personalNumber, int unitId);
    bool transferSoldier(int personalNumber, int newUnitId);

    bool addWarehouse(const char* name);
    const Warehouse* findWarehouse(const char* name) const;
    bool addEquipment(const char* warehouseName,
                      const char* equipmentName,
                      const char* serialNumber,
                      int quantity,
                      Equipment::eEquipmentStatus status);

    Vehicle* findVehicle(const char* vehicleNumber) const;
    bool setVehicleDriver(const char* vehicleNumber, int personalNumber);

    bool addTrainingMission(const char* missionName,
                            int unitId,
                            TrainingMission::eTrainingType trainingType,
                            TrainingMission::eDifficultyLevel difficultyLevel);
    int addLogisticsMission(const char* missionName, int unitId);
    Mission* findMission(int missionId) const;
    bool setMissionVehicle(int missionId, const char* vehicleNumber);
    bool addMissionEquipment(int missionId,
                             const char* warehouseName,
                             const char* equipmentName);

    BaseFacility&       getBase();
    const BaseFacility& getBase() const;

    void printAllUnits() const;
    void printAllMissions() const;
    int  getMissionsCount() const;
    Report generateReport() const;
    void   printAllData() const;
};

#endif // MILITARY_SYSTEM_H
 */