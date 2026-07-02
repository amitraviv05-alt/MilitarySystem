#include <iostream>
#include <string.h>
#include "Soldier.h"
using namespace std;

const char *Soldier::getName() const
{
    return name;
};

int Soldier::getId() const
{
    return id;
};

const Date &Soldier::getBirthDate() const
{
    return birthDate;
};

int Soldier::getPersonalNumber() const
{
    return personalNumber;
};

const char *Soldier::getRole() const
{
    return role;
};

Soldier::eRank Soldier::getRank() const
{
    return rank;
};

Unit *Soldier::getUnit() const
{
    return unit;
};

bool Soldier::setName(const char *name)
{
    if (name == nullptr)
    {
        return false;
    }
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    return true;
};

bool Soldier::setBirthDate(const Date& birthDate)
{
    this->birthDate = birthDate;
    return true;
};

bool Soldier::setRole(const char* role)
{
    if (role == nullptr)
    {
        return false;
    }
    delete[] this->role;
    this->role = new char[strlen(role) + 1];
    strcpy(this->role, role);
    return true;
};

bool Soldier::setRank(eRank rank)
{
    this->rank = rank;
    return true;
};

bool Soldier::setUnit(Unit* newUnit)
{
    this->unit = newUnit;
    return true;
};

void Soldier::print() const
{
    cout << "name: " << name
     << " ,birthDate: " << birthDate 
     << " ,role: " << role << " ,rank: " << rank;
};

Soldier::Soldier(const char* name, const Date& birthDate, const char* role, eRank rank)
: birthDate(birthDate)
{
    // ensure pointers are in a safe state before calling setters that delete[]
    this->name = nullptr;
    this->role = nullptr;
    this->unit = nullptr;

    setName(name);
    setBirthDate(birthDate);
    setRole(role);
    setRank(rank);
};