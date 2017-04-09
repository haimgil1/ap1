

#ifndef TASK2BFS_LUXURYCAB_H
#define TASK2BFS_LUXURYCAB_H

#include "Cab.h"
#include <string>

using namespace std;

/* Class: LuxuryCab.
 * The class implements the getCoefficient and moveOneStep
 * functions of the Cab. */
class LuxuryCab : public Cab {
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & boost::serialization::base_object<Cab>(*this);
    }

private:

public:
    // Constructor.
    LuxuryCab(int cabId = 1, CarManufacturer manufacturer = CarManufacturer::FIAT,
              Color color = Color::RED);

    // The function calculate the new tariff of luxury cabs.
    int getCoefficient();

    // The function change the block moveOneStep accordingly luxury cabs.
    AbstractNode *moveOneStep(stack<AbstractNode *> *track, Point endPoint);

    virtual ~LuxuryCab();
};


#endif //TASK2BFS_LUXURYCAB_H
