
#ifndef TASK2BFS_LUXURYCAB_H
#define TASK2BFS_LUXURYCAB_H
#include <iostream>
#include <vector>
#include "MaritalStatus.h"

using namespace std;
class InputValid {
private:
    string str;
public:
    // Constructor.
    InputValid(const string &str);

    // Split the string by char into vector.
    vector<string> splitString(char c);

    // Checking if string is digit.
    bool isDigits(string s);

    // Checking if string is an int.
    int checkInt(string s);

    // Checking if string is double.
    double checkDouble(string s);

    // Checking if the driver is valid.
    bool isValidDriver(int id, int age, string maritalStatus, int experience, int vehicleId);

    // Checking if the trip is valid.
    bool isValidTrip(int mapX, int mapY, int id,
                     int startX, int startY, int endX, int endY,
                     int numOfPassengers, double tariff, int time);

    // Checking if the cab is valid.
    bool isValidCab(int cabId, int cabType, string carManufacturer, string color);

    // Checking if the map is valid.
    bool isValidMap(unsigned long size, int mapX, int mapY);

    // Returning the input.
    string getInput();

    // Setter.
    void setStr(const string &str);

    // Distructor.
    virtual ~InputValid();
};

#endif //TASK2BFS_ENUMSTATUS_H
