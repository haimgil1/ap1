
#include "TaxiCenter.h"
#include "easylogging++.h"

using namespace std;
using namespace boost::iostreams;
using namespace boost::archive;

TaxiCenter::TaxiCenter() {

}

TaxiCenter::TaxiCenter(Grid *newMap) {
    map = newMap;

}

TaxiCenter::~TaxiCenter() {

    // Deleting every driver in taxi canter.
    for (int i = 0; i < (int) this->drivers.size(); i++) {
        delete this->drivers[i];
    }

    // Deleting every trip in taxi canter.
    for (int i = 0; i < (int) this->trips.size(); i++) {
        delete this->trips[i];
    }
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

void TaxiCenter::addDescriptor(int descriptor) {
    this->descriptors.push_back(descriptor);
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

const vector<int> &TaxiCenter::getDescriptors() const {
    return descriptors;
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
    } else {
        cout << "-1" << endl;
    }
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
   /* // Assigning driver to a trip.
    for (int i = 0; i < (int) this->trips.size(); i++) {
        TripInformation *trip = this->trips[i];
        if (trip->getTime() <= time && trip->getDriver() == NULL) {
            Driver *driver = this->findClosestDriverByTripLocation(trip->getStartPoint());
            if (driver != NULL) {
                trip->setDriver(driver);
            }
        }
    }*/
    
        // Assigning driver to a trip.
    for (int i = 0; i < (int) this->trips.size(); i++) {
        TripInformation *trip = this->trips[i];
        if (trip->getTime() <= time && trip->getDriver() == NULL) {
            while (true) {
                if (trip->isFinishCalcTrack()) {
                    Driver *driver = this->findClosestDriverByTripLocation(trip->getStartPoint());
                    if (driver != NULL) {
                        trip->setDriver(driver);
                    }
                    break;
                }
            }
        }
    }

    // Starting the track and remove from list.
    for (int i = 0; i < (int) this->trips.size(); i++) {
        TripInformation *trip = this->trips[i];
        if (trip->getDriver() != NULL && trip->getTime() < time) {
/*            if (!trips[i]->isFinishCalcTrack()){
                //trips[i]->join();
                LINFO << "join\n";
            }*/
            while (!trip->isFinishCalcTrack()) {
                sleep(1);
            }
            LINFO << "before move one step\n";
            trip->moveOneStep();
            // Checking if the trip is done.
            if (!trip->getDriver()->isOccupied()) {
                this->removeTrip(trip);
                delete trip;
                i--;
            }
        }
    }
}


