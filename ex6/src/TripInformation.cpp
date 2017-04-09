#include "TripInformation.h"
#include "easylogging++.h"

pthread_mutex_t trackLock2 = PTHREAD_MUTEX_INITIALIZER;
TripInformation::TripInformation() {

}

TripInformation::TripInformation(int newRideId, Point newStartPoint,
                                 Point newEndPoint, int newNumOfPassenger, double newTariff,
                                 Grid *newMap, int newTime) {
    this->rideId = newRideId;
    this->driver = NULL;
    this->totalMetersPassed = 0; // Reset the total meter passed to "0".
    this->time = newTime;
    this->startPoint = newStartPoint;
    this->endPoint = newEndPoint;
    this->numOfPassenger = newNumOfPassenger;
    this->tariff = newTariff;
    this->map = newMap;
    this->bfs = new Bfs();
    this->tripThread = new pthread_t();
    this->finishCalcTrack = false;
}

TripInformation::~TripInformation() {
    delete bfs;
    delete tripThread;
}

int TripInformation::getRideId() {
    return this->rideId;
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

void* TripInformation::settingTrack(void *ptr) {

    TripInformation *trip= (TripInformation *) ptr;
    pthread_mutex_lock(&trackLock2);
    LINFO << "start trip\n";
    stack<AbstractNode *> track = trip->getBfs()->BfsAlgorithm
            (trip->getMap()->getSourceElement(trip->getStartPoint()),
             trip->getMap()->getSourceElement(trip->getEndPoint()));

    trip->setTrack(track);
    trip->getMap()->setDistanceNeighbors();
    pthread_mutex_unlock(&trackLock2);
    trip->setIsFinishCalcTrack(true);
    LINFO << "end bfs\n";
}

Grid *TripInformation::getMap() {
    return this->map;
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
    // TODO empty
    // if (*(this->driver->getcurrentPoint()) != this->endPoint)

    if (track.empty()){
        this->driver->setOccupied(false);
    }
     else if (*(this->driver->getcurrentPoint()) != this->endPoint) {
        this->driver->moveOneStep(&track, this->endPoint);
    } else{
        this->driver->setOccupied(false);
    }

}

void TripInformation::moveTrail() {
    while (*(this->driver->getcurrentPoint()) != this->endPoint) {
        this->moveOneStep();
    }
    this->driver->setOccupied(false);

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

void TripInformation::setTrack(stack<AbstractNode *> newTrack) {
    track = newTrack;
}

Searchable *TripInformation::getBfs() const {
    return bfs;
}

bool TripInformation::isFinishCalcTrack() const {
    return finishCalcTrack;
}

void TripInformation::setIsFinishCalcTrack(bool isFinishCalcTrack) {
    TripInformation::finishCalcTrack = isFinishCalcTrack;
}

pthread_t *TripInformation::getTripThread()  {
    return tripThread;
}

void TripInformation::join(){
    pthread_join(*tripThread, NULL);
}

void TripInformation::createTripThread(){
    int status = pthread_create(tripThread, NULL,
                                this->settingTrack, (void *) this);
    if (status){
        LINFO << "Didn't succeed to create thread";
    }
    LINFO << "createTripThread";
}
