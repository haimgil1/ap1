//
// Created by haim gil on 28 Nov 2016.
//

#ifndef TASK2BFS_LUXURYCAB_H
#define TASK2BFS_LUXURYCAB_H

#include "Cab.h"
#include <string>

using namespace std;

/* Class: LuxuryCab.
 * The class implements the getCoefficient and moveOneStep
 * functions of the Cab. */
class LuxuryCab : public Cab {
private:

public:
    // Constructor.
    LuxuryCab(int cabId, CarManufacturer manufacturer, Color color);

    // The function calculate the new tariff of luxury cabs.
    int getCoefficient();

    // The function change the block moveOneStep accordingly luxury cabs.
    AbstractNode *moveOneStep(stack<AbstractNode *> *track, Point endPoint);

    virtual ~LuxuryCab();
};


#endif //TASK2BFS_LUXURYCAB_H
