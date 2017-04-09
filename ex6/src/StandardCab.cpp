
#include "StandardCab.h"

StandardCab::StandardCab(int cabId1, CarManufacturer manufacturer1,
                         Color color1) : Cab(cabId1, manufacturer1, color1) {

}

int StandardCab::getCoefficient() {
    return 1;
}

AbstractNode *StandardCab::moveOneStep(stack<AbstractNode *> *track, Point endPoint) {
    if (!track->empty() && *(track->top()) != endPoint) {
        track->pop();
        this->klmPassed++;
    }
    return track->top();
}

StandardCab::~StandardCab() {

}

BOOST_CLASS_EXPORT(StandardCab)
