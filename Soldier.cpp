#include <iostream>
#include "Soldier.h"
using namespace std;

const char* Soldier::getName() const
{
    return name;
}

int Soldier::getId() const
{
    return id;
}
// const Date& Soldier::getBirthDate() const;
// int         Soldier::getPersonalNumber() const;
// const char* Soldier::getRole() const;
// eRank       Soldier::getRank() const;
// Unit*       Soldier::getUnit() const;

// bool Soldier::setName(const char* name);
// bool Soldier::setBirthDate(const Date& birthDate);
// bool Soldier::setRole(const char* role);
// bool Soldier::setRank(eRank rank);
// bool Soldier::setUnit(Unit* newUnit);

// virtual void Soldier::print() const;
