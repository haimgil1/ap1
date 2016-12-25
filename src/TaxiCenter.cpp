
#include "TaxiCenter.h"
#include <iostream>

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

vector <TripInformation *> TaxiCenter::getTripQueue() {
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
    for (int i = 0; i < (int)this->cabs.size(); i++) {
        if (this->cabs[i]->getCabId() == vehicleId) {
            return this->cabs[i];
        }
    }
    return NULL;
}

Driver *TaxiCenter::findClosestDriverByTripLocation(Point tripLocation) {
    for (int i = 0; i < (int)this->drivers.size(); i++) {
        if (*(this->drivers[i]->getcurrentPoint()) == tripLocation &&
            !this->drivers[i]->isOccupied()) {
            return this->drivers[i];
        }
    }
    return NULL;
}

Driver *TaxiCenter::findDriverById(int driverId) {
    for (int i = 0; i < (int)this->drivers.size(); i++) {
        if (this->drivers[i]->getId() == driverId) {
            return this->drivers[i];
        }
    }
    return NULL;
}

void TaxiCenter::startDriving() {

    for (int i = 0; i < (int)this->trips.size(); i++) {
        Driver *driver = this->findClosestDriverByTripLocation(this->trips[i]->getStartPoint());
        if (driver != NULL) {
            this->trips[i]->setDriver(driver);
        }
    }

    for (int i = 0; i < (int)this->trips.size(); i++) {
        if (this->trips[i]->getDriver() != NULL) {
            this->trips[i]->moveTrail();
            TripInformation * trip = this->trips[i];
            this->removeTrip(this->trips[i]);
            delete trip;
            i--;
        }
    }

}


TaxiCenter::~TaxiCenter() {

    for (int i = 0; i < (int)this->cabs.size(); i++) {
        delete this->cabs[i];
    }

    for (int i = 0; i < (int)this->drivers.size(); i++) {
        delete this->drivers[i];
    }

    for (int i = 0; i < (int)this->trips.size(); i++) {
        delete this->trips[i];
    }
}
