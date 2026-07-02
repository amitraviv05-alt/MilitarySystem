#ifndef ARMORED_TRANSPORT_H
#define ARMORED_TRANSPORT_H

#include <iostream>
#include "Jeep.h"
#include "Truck.h"

class ArmoredTransport : public Jeep, public Truck {
public:
    ArmoredTransport(const char* vehicleNumber,
                     int maxPassengers,
                     double maxWeightKG);

    ArmoredTransport(const ArmoredTransport& other) = delete;
    ArmoredTransport& operator=(const ArmoredTransport& other) = delete;

    friend std::ostream &operator<<(std::ostream &os, const ArmoredTransport &transport);
    // void print() const override;
};

#endif // ARMORED_TRANSPORT_H
