
#include "MainFlow.h"
#include "FactoryCab.h"

MainFlow::MainFlow() {
    this->cab = NULL;
    this->driver = NULL;
    this->tripInformation = NULL;
    this->map=NULL;
    this->time = 0;
}

MainFlow::~MainFlow() {
    delete map;
}

void MainFlow::startGame() {
    int sizeX, sizeY;
    char dummy;
    cin >> sizeX >> sizeY; // Get the n,m of the map.
    this->map = this->MapParser(sizeX, sizeY);;
    int numOfObstacles;
    cin >> numOfObstacles; // Get number of obstacles.
    while (numOfObstacles > 0) { // Get the points of the obstacles.
        int px, py;
        cin >> px >> dummy >> py;
        this->map->getSourceElement(px, py)->setObstacle(true);
        numOfObstacles--;
    }
    TaxiCenter taxiCenter(this->map); // Create taxi center.
    int mission; // the num of choice in the menu.
    do {
        cin >> mission;
        switch (mission) {

            case 3: // Get cab parameters.
                int cabId, cabType;
                char manufacturer, color1;
                cin >> cabId >> dummy >> cabType >> dummy >> manufacturer >> dummy >> color1;
                this->cab = this->cabParser(cabId, cabType, manufacturer, color1);
                taxiCenter.addCab(this->cab);
                break;

            case 1:  // Get driver parameters.
                int driverId, vehicleId;
                double age, experience;
                char status;
                cin >> driverId >> dummy >> age >> dummy >> status >> dummy >> experience >> dummy
                    >> vehicleId;
                this->driver = this->driverParser(driverId, age, status, experience, vehicleId);
                this->cab = taxiCenter.findCabById(vehicleId);
                this->driver->setCab(this->cab);
                taxiCenter.addDriver(this->driver);
                break;

            case 2:  // Get trip parameters.
                int tripId, startX, startY, endX, endY, numOfPassengers;
                double tariff,time;
                cin >> tripId >> dummy >> startX >> dummy >> startY >> dummy >> endX >> dummy
                    >> endY >> dummy >> numOfPassengers >> dummy >> tariff>> dummy >> time;

                // Trip can't be negative and more than map coordinate.
                if (startX >= sizeX || startY >= sizeY || startX < 0 || startY < 0
                    || endX >= sizeX || endY >= sizeY || endX < 0 || endY < 0) {
                    throw invalid_argument("wrong trip range\n");
                }

                this->tripInformation = this->tripInfoParser(tripId, startX, startY, endX, endY,
                                                             numOfPassengers, tariff,
                                                             this->map,time);
                taxiCenter.addTrip(this->tripInformation);
                break;

            case 9:
                // Start the trips.
                this->time++;
                taxiCenter.driving(this->time);
                break;

            case 4:
                // Print driver location
                cin >> driverId;
                taxiCenter.printDriverLocation(driverId);
                break;

            case 7:
                return;
            default:
                throw invalid_argument("invalid number of mission\n");
        }
    } while (mission != 7);
}

Cab *MainFlow::cabParser(int cabId, int cabType, char manufacturer, char color1) {
    CarManufacturer carManufacturer = CarManufacturer(manufacturer);
    Color color = Color(color1);
    FactoryCab factoryCab;
    if (cabType == 1) {
        return factoryCab.getCab("StandardCab", cabId, carManufacturer, color);
    } else {
        return factoryCab.getCab("LuxuryCab", cabId, carManufacturer, color);
    }
}

Driver *MainFlow::driverParser(int driverId, double age, char status, double experience,
                               int cabId) {
    MaritalStatus maritalStatus = MaritalStatus(status);
    return new Driver(driverId, age, maritalStatus, experience, cabId,
                      this->map->getSourceElement(0, 0));
}

TripInformation *MainFlow::tripInfoParser(int tripId, int startX, int startY, int endX, int endY,
                                          int numOfPassengers, double tariff,
                                          Grid *map,double time) {
    Point startP(startX, startY);
    Point endP(endX, endY);
    return new TripInformation(tripId, startP, endP, numOfPassengers, tariff, map, time);
}

Grid *MainFlow::MapParser(int n, int m) {
    return new Matrix(n, m);
}

