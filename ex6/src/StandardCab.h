

#ifndef TASK2BFS_STANDARDCAB_H
#define TASK2BFS_STANDARDCAB_H

#include "Cab.h"
#include <string>

using namespace std;

/* Class: StandardCab.
 * The class implements the getCoefficient and moveOneStep
 * functions of the Cab. */
class StandardCab : public Cab {
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & boost::serialization::base_object<Cab>(*this);
    }

private:

public:
    // Constructor.
    StandardCab(int cabId = 0, CarManufacturer manufacturer = CarManufacturer::FIAT,
                Color color = Color::RED);

    // the function calculate the new tariff of standard cabs.
    int getCoefficient();

    // the function change the block moveOneStep accordingly standard cabs.
    AbstractNode *moveOneStep(stack<AbstractNode *> *track, Point endPoint);

    virtual ~StandardCab();
};

#endif //TASK2BFS_STANDARDCAB_H
