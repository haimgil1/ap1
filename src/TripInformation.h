
#ifndef TASK2BFS_TRIPINFORMATION_H
#define TASK2BFS_TRIPINFORMATION_H


#include <vector>
#include "Passenger.h"
#include "Node.h"
#include "Point.h"
#include <list>
#include "Driver.h"
#include <stdexcept>
#include <algorithm>


/* Class- TripInformation.
 * The trip information has the information on all the trip.
 * The class has function that gets the details and update the
 * details of the class members.*/
class TripInformation {
private:
    // Members.
    int rideId;
    int totalMetersPassed;
    int numOfPassenger;
    double tariff;
    double time;
public:
    double getTime() const;

private:
    Point startPoint;
    Point endPoint;
    vector<Passenger *> passengers;
    Driver *driver;
    stack<AbstractNode *> track;
    Searchable *bfs;
    Grid *map;

    void validate();

public:
    // Default constructor.
    TripInformation();

    virtual ~TripInformation();

    // Constructor.
    TripInformation(int newRideId, Point newStartPoint, Point newEndPoint, int newNumOfPassenger,
                    double newTariff, Grid *newMap, double newTime);

    // The function returns the ride id.
    int getRideId();

    // ser the current point.
    void setMeterPassed(int meters);

    // The function returns the current point.
    int getMeterPassed();

    // The function sets the end point.
    void setEndPoint(Point p);

    // The function returns the end point.
    Point getEndPoint();

    // The function returns the start point.
    Point getStartPoint();

    // The function sets num of passengers.
    void setNumOfPassenger(int numPass);

    // The function returns num of passengers.
    int getNumOfPassenger();

    // The function sets new tariff.
    void setTariff(double newTariff);

    // The function returns new tariff.
    double getTariff();

    // The function return the best way to passenger.
    void settingTrack();

    // The function returns the map of the town.
    Grid *getMap();

    // The function adds passenger to the list.
    void addPassenger(Passenger *pass);

    // The function removes passenger from the list.
    void removePassenger(Passenger *pass);

    // The function returns the list of passenger.
    vector<Passenger *> getPassenger();

    // The function sets the map of the town.
    void setMap(Grid *map);

    // The function returns a driver.
    Driver *getDriver() const;

    // The function set a driver.
    void setDriver(Driver *driver);

    // The function change the current location one step.
    void moveOneStep();

    // The function set the river to the destination point.
    void moveTrail();

    // The function calculate the ride tariff.
    double rideCost();

    // The operator to compare TripInformation object.
    bool operator==(const TripInformation &trip) const;

    // The operator to compare TripInformation object.
    bool operator!=(const TripInformation &trip) const;
};


#endif //TASK2BFS_TRIPINFORMATION_H
