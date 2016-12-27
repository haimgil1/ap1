

#include "TripInformation.h"

TripInformation::TripInformation() {

}

TripInformation::TripInformation(int newRideId, Point newStartPoint,
                                 Point newEndPoint, int newNumOfPassenger, double newTariff,
                                 Grid *newMap, double newTime) {
    this->rideId = newRideId;
    this->driver = NULL;
    this->totalMetersPassed = 0; // Reset the total meter passed to "0".
    this->time=newTime;
    this->startPoint = newStartPoint;
    this->endPoint = newEndPoint;
    this->numOfPassenger = newNumOfPassenger;
    this->tariff = newTariff;
    this->map = newMap;
    this->validate(); // Check validate of the parameters.
    this->bfs = new Bfs();
    this->settingTrack();
}

TripInformation::~TripInformation() {
    delete bfs;
}

void TripInformation::validate() {
    // Check that tariff is positive and the num of passengers is maximum 4.
    if (numOfPassenger > 5 || tariff < 0 || numOfPassenger < 0) {
        throw invalid_argument("tariff can't be negative and can't get more than 5 passenger");
    }
}

int TripInformation::getRideId() {
    return this->rideId;
}

void TripInformation::setMeterPassed(int meters) {
    this->totalMetersPassed += meters;
}

void TripInformation::setEndPoint(Point p) {
    this->endPoint = p;
}

Point TripInformation::getEndPoint() {
    return this->endPoint;
}

Point TripInformation::getStartPoint() {
    return this->startPoint;
}

int TripInformation::getMeterPassed() {
    return this->totalMetersPassed;
}

void TripInformation::setNumOfPassenger(int numPass) {
    this->numOfPassenger = numPass;
}


int TripInformation::getNumOfPassenger() {
    return this->numOfPassenger;
}

void TripInformation::setTariff(double newTariff) {
    this->tariff = newTariff;
}

double TripInformation::getTariff() {
    return this->tariff;
}

void TripInformation::addPassenger(Passenger *pass) {
    this->passengers.push_back(pass);
}

void TripInformation::removePassenger(Passenger *pass) {
    passengers.erase(std::remove(passengers.begin(), passengers.end(), pass), passengers.end());
    //this->passengers.erase(pass);
}

vector<Passenger *> TripInformation::getPassenger() {
    return this->passengers;
}

void TripInformation::settingTrack() {
    track = bfs->BfsAlgorithm(map->getSourceElement(this->startPoint),
                              map->getDestinationElement(this->endPoint));
    this->map->setDistanceNeighbors();

}

Grid *TripInformation::getMap() {
    return this->map;
}

void TripInformation::setMap(Grid *map) {
    this->map = map;
}

Driver *TripInformation::getDriver() const {
    return driver;
}

void TripInformation::setDriver(Driver *driver) {
    if (driver != NULL) {
        this->driver = driver;
        this->driver->setOccupied(true);
    } else {
        this->driver = NULL;
    }
}

void TripInformation::moveOneStep() {
    if (*(this->driver->getcurrentPoint()) != this->endPoint){
        this->driver->moveOneStep(&track, this->endPoint);
    }else{
        this->driver->setOccupied(false);
    }

}

void TripInformation::moveTrail() {
    while (*(this->driver->getcurrentPoint()) != this->endPoint) {
        this->moveOneStep();
    }
    //this->driver->setOccupied(false);

}

double TripInformation::rideCost() {
    return this->tariff * (this->driver->getCab()->getCoefficient());
}

bool TripInformation::operator==(const TripInformation &trip) const {
    return rideId == trip.rideId &&
           totalMetersPassed == trip.totalMetersPassed &&
           startPoint == trip.startPoint &&
           endPoint == trip.endPoint &&
           numOfPassenger == trip.numOfPassenger &&
           tariff == trip.tariff;
}

bool TripInformation::operator!=(const TripInformation &trip) const {
    return !(trip == *this);
}

double TripInformation::getTime() const {
    return time;
}
