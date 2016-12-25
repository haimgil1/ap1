//
// Created by chen on 30/11/16.
//

#include "Passenger.h"

Passenger::Passenger(Point newSource, Point newDestination) {
    this->sourcePoint = newSource;
    this->destinationPoint = newDestination;
}

Point Passenger::getSourcePoint() const {
    return this->sourcePoint;
}

void Passenger::setDestinationPoint(Point dstP) {
    this->destinationPoint = dstP;
}

Point Passenger::getDestinationPoint() const {
    return this->destinationPoint;
}

int Passenger::getFeedback() {
    return rand() % 5 + 1;
}

bool Passenger::operator==(const Passenger &p1) const {
    return ((sourcePoint == p1.getSourcePoint()) && (destinationPoint == p1.getDestinationPoint()));
}

Passenger::Passenger() {

}

Passenger::~Passenger() {

}

