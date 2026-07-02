#ifndef MISSION_H
#define MISSION_H

class Unit;

class Mission {
public:
    enum class eMissionStatus {
        NOT_STARTED,
        IN_PROGRESS,
        COMPLETED
    };

private:
    static int s_nextMissionId;
    char* missionName;
    int   missionId;
    eMissionStatus status;
    Unit* assignedUnit;

public:
    Mission(const char* missionName, Unit* assignedUnit);
    virtual ~Mission();

    Mission(const Mission& other) = delete;
    Mission& operator=(const Mission& other) = delete;

    const char*    getMissionName() const;
    int            getMissionId() const;
    eMissionStatus getStatus() const;
    Unit*          getAssignedUnit() const;

    bool setMissionName(const char* missionName);
    bool setStatus(eMissionStatus newStatus);

    friend std::ostream &operator<<(std::ostream &os, const Mission &mission);
    //virtual void print() const = 0;
};

inline std::ostream& operator<<(std::ostream& os, const Mission::eMissionStatus& status) {
    switch (status) {
        case Mission::eMissionStatus::NOT_STARTED: os << "NOT_STARTED"; break;
        case Mission::eMissionStatus::IN_PROGRESS: os << "IN_PROGRESS"; break;
        case Mission::eMissionStatus::COMPLETED:   os << "COMPLETED";   break;
        default:                                   os << "UNKNOWN";    break;
    }
    return os;
};

#endif // MISSION_H
