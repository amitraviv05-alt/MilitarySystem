#include <iostream>
#include "Officer.h"
using namespace std;

Officer::Officer(const char* name, const Date& birthDate, const char* role, eRank rank)
: Soldier(name, birthDate, role, rank),commandedSoldiers(nullptr), commandedCount(0), commandedCapacity(0){};

int Officer::getCommandedCount() const
{
    return commandedCount;
};

Soldier* Officer::getCommandedSoldier(int index) const
{
    return commandedSoldiers[index];
};

bool Officer::addCommandedSoldier(Soldier* soldier)
{
    if (commandedCount < commandedCapacity)
    {
        commandedSoldiers[commandedCount++] = soldier;
    }
    else
    {
        int newCapacity;
        if (commandedCapacity == 0)
        {
            newCapacity = 1;
        }    
        else
        {
            newCapacity = 2 * commandedCapacity;
        }
        Soldier** tempCommandedSoldiers = new Soldier*[newCapacity];
        for (int i = 0; i < commandedCount; i++)
        {
            tempCommandedSoldiers[i] = commandedSoldiers[i];
        }
        tempCommandedSoldiers[commandedCount] = soldier;
        delete[] commandedSoldiers;
        commandedSoldiers = tempCommandedSoldiers;
        commandedCount++;
        commandedCapacity = newCapacity;
    }
    return true;
};

// bool Officer::removeCommandedSoldier(const Soldier* soldier);
// void Officer::printCommandedSoldiers() const;

// void Officer::print() const override;