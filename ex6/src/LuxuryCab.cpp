

#include "LuxuryCab.h"

LuxuryCab::LuxuryCab(int cabId1, CarManufacturer manufacturer1, Color color1) : Cab(cabId1,
                                                                                    manufacturer1,
                                                                                    color1) {
}

int LuxuryCab::getCoefficient() {
    return 2;
}

AbstractNode *LuxuryCab::moveOneStep(stack<AbstractNode *> *track, Point endPoint) {
    if (!track->empty() && *(track->top()) != endPoint) {
        track->pop();
        this->klmPassed++;
    }

    if (!track->empty() && *(track->top()) != endPoint) {
        track->pop();
        this->klmPassed++;
    }
    return track->top();
}

LuxuryCab::~LuxuryCab() {

}

BOOST_CLASS_EXPORT(LuxuryCab)