#ifndef SOLDIER_H
#define SOLDIER_H

#include "Date.h"

class Unit;

class Soldier {
public:
    enum class eRank {
        PRIVATE,
        CORPORAL,
        SERGEANT,
        LIEUTENANT,
        CAPTAIN,
        MAJOR
    };

private:
    static int s_nextId;
    static int s_nextPersonalNumber;

    char* name;
    int   id;
    Date  birthDate;

    int   personalNumber;
    char* role;
    eRank rank;
    Unit* unit;

public:
    Soldier(const char* name,
            const Date& birthDate,
            const char* role,
            eRank rank);
    virtual ~Soldier();

    Soldier(const Soldier& other) = delete;
    Soldier& operator=(const Soldier& other) = delete;

    const char* getName() const;
    int         getId() const;
    const Date& getBirthDate() const;
    int         getPersonalNumber() const;
    const char* getRole() const;
    eRank       getRank() const;
    Unit*       getUnit() const;

    bool setName(const char* name);
    bool setBirthDate(const Date& birthDate);
    bool setRole(const char* role);
    bool setRank(eRank rank);
    bool setUnit(Unit* newUnit);

    virtual void print() const;
};


inline std::ostream& operator<<(std::ostream& os, const Soldier::eRank& rank) {
    switch (rank) {
        case Soldier::eRank::PRIVATE:    os << "PRIVATE"; break;
        case Soldier::eRank::CORPORAL:   os << "CORPORAL"; break;
        case Soldier::eRank::SERGEANT:   os << "SERGEANT"; break;
        case Soldier::eRank::LIEUTENANT: os << "LIEUTENANT"; break;
        case Soldier::eRank::CAPTAIN:    os << "CAPTAIN"; break;
        case Soldier::eRank::MAJOR:      os << "MAJOR"; break;
        default:                         os << "UNKNOWN"; break;
    }
    return os;
}

#endif // SOLDIER_H
