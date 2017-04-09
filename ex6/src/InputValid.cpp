#include <sstream>
#include "InputValid.h"

vector<string> InputValid::splitString(char c) {
    stringstream ss(str);
    string item;
    vector<string> tokens;
    while (getline(ss, item, c)) {
        tokens.push_back(item);
    }
    return tokens;
}


bool InputValid::isDigits(string s) {

    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) < '0' || s.at(i) > '9') {
            return false;
        }
    }
    return true;
}

int InputValid::checkInt(string s) {
    if (isDigits(s)) {
        return atoi(s.c_str());
    }
    return -1;
}


double InputValid::checkDouble(string s) {
    int point =0;
    for (int i = 0; i < s.size(); ++i) {
        if(s.at(i) == '.') {
            point ++;
        } else if (s.at(i) < '0' || s.at(i) > '9'){
            return -1;
        }
    }
    if (point >1) {
        return -1;
    }
    return strtod(s.c_str(), NULL);
}

bool InputValid::isValidDriver(int id, int age, string maritalStatus, int experience,
                               int vehicleId) {
    char status = maritalStatus.at(0);

    if (maritalStatus.size() != 1 || id < 0 || age < 0 || experience < 0 || vehicleId < 0) {
        return false;
    }
    return !(status != 'S' && status != 'M' && status != 'D'
             && status != 'W');
}


bool InputValid::isValidTrip(int mapX, int mapY, int id,
                             int startX, int startY, int endX, int endY,
                             int numOfPassengers, double tariff, int time) {
    if (id < 0 || numOfPassengers < 0 || tariff < 0 || time <0) {
        return false;
    }

    // Trip can't be negative and more than map coordinate.
    if (startX >= mapX || startY >= mapY || startX < 0 || startY < 0
        || endX >= mapX || endY >= mapY || endX < 0 || endY < 0) {
        return false;
    }
    return true;
}

bool InputValid::isValidCab(int cabId, int cabType, string carManufacturer, string color1){

    char color = color1.at(0), manufacturer = carManufacturer.at(0);
    if (cabId<0){
        return false;
    }
    if(cabType != 1 && cabType != 2){
        return false;
    }
    if (color1.size() != 1 || carManufacturer.size() !=1){
        return false;
    }
    if (color != 'R' && color != 'B' && color != 'G'
        &&color != 'P' && color != 'W'){
        return false;
    }
    return !(manufacturer != 'H' && manufacturer != 'S' &&
            manufacturer != 'T' && manufacturer != 'F');

}

bool InputValid::isValidMap(unsigned long size, int mapX, int mapY){
    if (size!=2 || mapX > 1000 || mapX<0 ||
        mapY > 1000 || mapY<0){
        return false;
    }
    return true;
}

InputValid::InputValid(const string &str) : str(str) {}

void InputValid::setStr(const string &str) {
    InputValid::str = str;
}

InputValid::~InputValid() {

}

string InputValid::getInput() {
    string input;
    while (input.size()== 0){
        getline(cin, input);
    }
    return input;
}
