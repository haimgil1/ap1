

#include "FactoryCab.h"
#include "StandardCab.h"
#include "LuxuryCab.h"

FactoryCab::FactoryCab() {

}

Cab *
FactoryCab::getCab(int cabType, int cabId, CarManufacturer manufacturer,
                   Color color) {
    if (cabType == 1) { // Check if the type if standard.
        return new StandardCab(cabId, manufacturer, color);
    } else if (cabType == 2) { // Check if the type is luxury.
        return new LuxuryCab(cabId, manufacturer, color);
    }
    return NULL;

}

FactoryCab::~FactoryCab() {

}
