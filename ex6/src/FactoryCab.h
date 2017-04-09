//
// Created by haim gil on 28 Nov 2016.
//

#ifndef TASK2BFS_FACTORYCAB_H
#define TASK2BFS_FACTORYCAB_H

#include "Cab.h"
#include "CarManufacturer.h"
#include "Color.h"
#include "Cab.h"
#include <string>

using namespace std;

/* Class - factory cab.
 * has function the return new cab.*/
class FactoryCab {

public:
    // Default constructor.
    FactoryCab();

    // The function get parameters and return a new cab - standard of luxury type.
    Cab *getCab(int cabType, int cabId, CarManufacturer manufacturer,
                Color color);

    virtual ~FactoryCab();
};


#endif //TASK2BFS_FACTORYCAB_H
