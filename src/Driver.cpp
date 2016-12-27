
#include "Driver.h"

Driver::Driver(int newId, double newAge, MaritalStatus newMaterialStatus, double newExperience,
               int cabId, AbstractNode *newCurrentPoint) {
    this->id = newId;
    this->age = newAge;
    this->materialStatus = newMaterialStatus;
    this->experience = newExperience;
    this->satisfaction = 0;
    this->numOfCustomers = 0;
    this->cabId = cabId;
    this->currentPoint = newCurrentPoint;
    this->occupied = false;
    this->cab = NULL;
    this->validate();
}

Driver::~Driver() {
}

void Driver::validate() {
    // Check if the age and the experience are correct.
    if ((this->age < 0) || (this->experience < 0)) {
        throw std::invalid_argument("age or experience can't be negative");
    }
}

int Driver::getId() const {
    return this->id;
}

double Driver::getAge() {
    return this->age;
}

void Driver::setStatus(MaritalStatus newStatus) {
    this->materialStatus = newStatus;
}

MaritalStatus Driver::getStatus() {
    return this->materialStatus;
}

void Driver::setExp(double newExp) {
    this->experience = newExp;
}

double Driver::getExp() {
    return this->experience;
}

AbstractNode *Driver::getcurrentPoint() {
    return this->currentPoint;
}

void Driver::setCurrentPoint(AbstractNode *p) {
    this->currentPoint = p;
}

void Driver::setSatisfaction(int newSatisfaction) {
    this->satisfaction = newSatisfaction;
}

int Driver::getSatisfaction() {
    return this->satisfaction;
}

void Driver::setCab(Cab *newTaxiCabInformation) {
    this->cab = newTaxiCabInformation;
}

Cab *Driver::getCab() {
    return this->cab;
}

void Driver::addCustomers(int num) {
    this->numOfCustomers += num;
}

void Driver::removeCustomer(int num) {
    this->numOfCustomers -= num;
}


void Driver::moveOneStep(stack<AbstractNode *> *track, Point p) {
    this->currentPoint = this->cab->moveOneStep(track, p);
}


bool Driver::operator==(const Driver &driver) const {
    return id == driver.id &&
           age == driver.age &&
           experience == driver.experience &&
           satisfaction == driver.satisfaction &&
           numOfCustomers == driver.numOfCustomers;
}

bool Driver::operator!=(const Driver &driver) const {
    return !(driver == *this);
}

int Driver::getCabId() const {
    return cabId;
}

bool Driver::isOccupied() const {
    return occupied;
}

void Driver::setOccupied(bool occupied) {
    this->occupied = occupied;
}

ostream &operator<<(ostream &os, const Driver &driver) {
    return os<<driver.getId();
}


