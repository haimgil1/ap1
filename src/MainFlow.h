
#ifndef TASK2BFS_MAINFLOW_H
#define TASK2BFS_MAINFLOW_H

#include <iostream>
#include <string.h>
#include "Cab.h"
#include "TripInformation.h"
#include "Driver.h"
#include "Passenger.h"
#include "TaxiCenter.h"
#include <stdexcept>

using namespace std;

class MainFlow {

private:
    Cab *cab;
    Driver *driver;
    TripInformation *tripInformation;
    Grid *map;
    double time;
public:
    MainFlow();

    void startGame();

    virtual ~MainFlow();

    // The function gets parameters and return a cab.
    Cab *cabParser(int cabId, int cabType, char manufacturer, char color1);

    // The function gets parameters and return a driver.
    Driver *driverParser(int driverId, double age, char status, double experience,
                         int cabId);

    // The function gets parameters and return a trip information.
    TripInformation *tripInfoParser(int tripId, int startX, int startY, int endX, int endY,
                                    int numOfPassengers, double tariff,
                                    Grid *map,double time);

    // The function gets parameters and return a map.
    Grid *MapParser(int n, int m);
};


#endif //TASK2BFS_MAINFLOW_H
