
#include "Cab.h"

Cab::Cab() {

}

Cab::Cab(int cabId1, CarManufacturer manufacturer1,
         Color color1) {
    this->cabId = cabId1;
    this->klmPassed = 0;
    this->manufacturer = manufacturer1;
    this->color = color1;
}

Cab::~Cab() {

}

int Cab::getCabId() {
    return this->cabId;
}

int Cab::getKilometerPassed() {
    return this->klmPassed;
}

CarManufacturer Cab::getManufacturer() {
    return this->manufacturer;
}

Color Cab::getColor() {
    return this->color;
}

void Cab::setCabId(int cabID1) {
    cabId = cabID1;
}


void Cab::setKilometerPassed(int klm) {
    klmPassed = klm;
}

void Cab::setManufacturer(CarManufacturer manufacturer1) {
    manufacturer = manufacturer1;
}

void Cab::setColor(Color color1) {
    color = color1;
}

bool Cab::operator==(const Cab &cab) const {
    return cabId == cab.cabId &&
           klmPassed == cab.klmPassed &&
           manufacturer == cab.manufacturer &&
           color == cab.color;
}

bool Cab::operator!=(const Cab &cab) const {
    return !(cab == *this);
}
