//
// Created by haim gil on 28 Nov 2016.
//

#ifndef TASK2BFS_STANDARDCAB_H
#define TASK2BFS_STANDARDCAB_H

#include "Cab.h"
#include <string>

using namespace std;

/* Class: StandardCab.
 * The class implements the getCoefficient and moveOneStep
 * functions of the Cab. */
class StandardCab : public Cab {

private:

public:
    // Constructor.
    StandardCab(int cabId, CarManufacturer manufacturer, Color color);

    // the function calculate the new tariff of standard cabs.
    int getCoefficient();

    // the function change the block moveOneStep accordingly standard cabs.
    AbstractNode *moveOneStep(stack<AbstractNode *> *track, Point endPoint);

    virtual ~StandardCab();
};


#endif //TASK2BFS_STANDARDCAB_H
