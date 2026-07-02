#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"
class Equipment;

class Truck : virtual public Vehicle {
public:
    static const int loadedCapacity = 10;
private:
    Equipment* loadedEquipment[loadedCapacity];
    int loadedCount;

    double maxWeightKG;

public:
    Truck(const char* vehicleNumber, double maxWeightKG);
    ~Truck();

    Truck(const Truck& other) = delete;
    Truck& operator=(const Truck& other) = delete;

    int        getLoadedCount() const;
    Equipment* getLoadedEquipment(int index) const;
    double     getMaxWeightKG() const;

    bool setMaxWeightKG(double maxWeightKG);

    bool loadEquipment(Equipment* equipment);
    bool unloadEquipment(const Equipment* equipment);

    //void print() const override;
};

#endif // TRUCK_H
