#include <iostream>
#include "Unit.h"
using namespace std;


Unit::Unit(const char* unitName)
{
    setUnitName(unitName);
    count = 0;
    capacity = 0;
    soldiers = nullptr;
}

Unit::~Unit()
{
    delete[] soldiers;
}

const char* Unit::getUnitName() const
{
    return unitName;
};

int Unit::getUnitId() const
{
    return unitId;
};

int Unit::getSoldierCount() const
{
    return count;
};

Soldier* Unit::getSoldier(int index) const
{
    return soldiers[index];
}

bool Unit::setUnitName(const char* name)
{
    if (name == nullptr)
    {
        return false;
    }
    delete[] unitName;
    unitName = new char[strlen(name) + 1];
    strcpy(unitName, name);
    return true;
}

/* bool Unit::addSoldier(Soldier* soldier)
{
    if (soldier == nullptr)
    {
        return false;
    }

    soldiers[count] = soldier;
    count++;
    return true;
} */

bool Unit::addSoldier(Soldier& soldier)
{
    if (count < capacity)
    {
        soldiers[count++] = &soldier;
    }
    else
    {
        int newCapacity;
        if (capacity == 0)
        {
            newCapacity = 1;
        }    
        else
        {
            newCapacity = 2 * capacity;
        }
        Soldier** tempSoldiers = new Soldier*[newCapacity];
        for (int i = 0; i < count; i++)
        {
            tempSoldiers[i] = soldiers[i];
        }
        tempSoldiers[count] = &soldier;
        delete[] soldiers;
        soldiers = tempSoldiers;
        count++;
        capacity = newCapacity;
    }
    return true;
};

bool Unit::removeSoldier(const Soldier* soldier)
{
    for (int i = 0; i < count; i++)
    {
        if (soldiers[i] == soldier)
        {
            for (int j = i; j < count - 1; j++)
            {
                soldiers[j] = soldiers[j + 1];
            }
            count--;
            return true;
        }
    }
    return false;
};

void Unit::printSoldiers() const
{
    for (int i = 0; i < count; i++)
    {
        cout << soldiers[i] << endl;
    }
};

std::ostream &operator<<(std::ostream &os, const Unit &unit)
{
    os << "Unit Name: " << unit.unitName
       << ", Unit ID: " << unit.unitId
       << ", Soldier Count: " << unit.count;
    return os;
};
