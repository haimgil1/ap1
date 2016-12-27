
#include "TaxiCenter.h"
#include <iostream>


TaxiCenter::TaxiCenter() {

}

TaxiCenter::TaxiCenter(Grid *newMap) {
    map = newMap;

}

void TaxiCenter::addDriver(Driver *newDriver) {
    this->drivers.push_back(newDriver);
}

void TaxiCenter::addCab(Cab *newCab) {
    this->cabs.push_back(newCab);
}

void TaxiCenter::addTrip(TripInformation *newTrip) {
    this->trips.push_back(newTrip);
}


vector<Driver *> TaxiCenter::getDriverVec() {
    return this->drivers;
}

vector<Cab *> TaxiCenter::getCabVec() {
    return this->cabs;
}

vector<TripInformation *> TaxiCenter::getTripQueue() {
    return this->trips;
}


void TaxiCenter::removeDriver(Driver *newDriver) {
    drivers.erase(std::remove(drivers.begin(), drivers.end(), newDriver), drivers.end());
}

void TaxiCenter::removeCab(Cab *newCab) {
    cabs.erase(std::remove(cabs.begin(), cabs.end(), newCab), cabs.end());
}

void TaxiCenter::removeTrip(TripInformation *newTrip) {
    trips.erase(std::remove(trips.begin(), trips.end(), newTrip), trips.end());
}

void TaxiCenter::printDriverLocation(int driverId) {

    // Printing the driver location.
    Driver *driver = this->findDriverById(driverId);
    if (driver != NULL) {
        cout << *(driver->getcurrentPoint());
    }
}

void TaxiCenter::answerCall(Passenger *p) {
    // In the next exercise we implements this function.
    return;
}

Cab *TaxiCenter::findCabById(int vehicleId) {

    // Assigning cab to a driver by his id.
    for (int i = 0; i < (int) this->cabs.size(); i++) {
        if (this->cabs[i]->getCabId() == vehicleId) {
            return this->cabs[i];
        }
    }
    return NULL;
}

Driver *TaxiCenter::findClosestDriverByTripLocation(Point tripLocation) {

    // Assigning driver to a trip by trip's location.
    for (int i = 0; i < (int) this->drivers.size(); i++) {
        if (*(this->drivers[i]->getcurrentPoint()) == tripLocation &&
            !this->drivers[i]->isOccupied()) {
            return this->drivers[i];
        }
    }
    return NULL;
}

Driver *TaxiCenter::findDriverById(int driverId) {

    // Finding a driver according to his id.
    for (int i = 0; i < (int) this->drivers.size(); i++) {
        if (this->drivers[i]->getId() == driverId) {
            return this->drivers[i];
        }
    }
    return NULL;
}

void TaxiCenter::driving(double time) {

    // Assigning driver to a trip.
    for (int i = 0; i < (int) this->trips.size(); i++) {
        Driver *driver = this->findClosestDriverByTripLocation(this->trips[i]->getStartPoint());
        if (driver != NULL) {
            this->trips[i]->setDriver(driver);
        }
    }

    // Starting the track and remove from list.
    for (int i = 0; i < (int) this->trips.size(); i++) {
        if (this->trips[i]->getDriver() != NULL && this->trips[i]->getTime() <= time) {
            this->trips[i]->moveOneStep();
            if (!this->trips[i]->getDriver()->isOccupied()){
                TripInformation *trip = this->trips[i];
                this->removeTrip(this->trips[i]);
                delete trip;
                i--;
            }

        }
    }

}


TaxiCenter::~TaxiCenter() {

    // Deleting every cab in taxi canter.
    for (int i = 0; i < (int) this->cabs.size(); i++) {
        delete this->cabs[i];
    }

    // Deleting every driver in taxi canter.
    for (int i = 0; i < (int) this->drivers.size(); i++) {
        delete this->drivers[i];
    }

    // Deleting every trip in taxi canter.
    for (int i = 0; i < (int) this->trips.size(); i++) {
        delete this->trips[i];
    }
}
