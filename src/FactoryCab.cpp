

#include "FactoryCab.h"
#include "StandardCab.h"
#include "LuxuryCab.h"

FactoryCab::FactoryCab() {

}

Cab *
FactoryCab::getCab(string cabType, int cabId, CarManufacturer manufacturer,
                   Color color) {
    if (cabType == "StandardCab") { // Check if the type if standard.
        return new StandardCab(cabId, manufacturer, color);
    } else if (cabType == "LuxuryCab") { // Check if the type is luxury.
        return new LuxuryCab(cabId, manufacturer, color);
    }
    return NULL;

}

FactoryCab::~FactoryCab() {

}
