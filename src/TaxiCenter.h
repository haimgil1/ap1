//
// Created by haim gil on 02/12/2016.
//

#ifndef TASK2BFS_TAXICENTER_H
#define TASK2BFS_TAXICENTER_H

#include "MaritalStatus.h"
#include "TripInformation.h"
#include "Grid.h"
#include "Matrix.h"
#include "Cab.h"
#include "Driver.h"
#include <algorithm>
#include <deque>

/* Class- TaxiCenter.
 * The members: map.
 * The taxi center manage the cabs, the drivers, can get calls from customers
 * and can find the closet driver to the passenger. The taxi center
 * prints the driver location and set cab to driver. */
class TaxiCenter {
private:
    /**
     * Members.
     */
    vector<Driver *> drivers;
    vector<Cab *> cabs;
    vector<TripInformation *> trips;
    Grid *map;

public:
    /**
     * Constructor - get map.
     * @param newMap
     */
    TaxiCenter(Grid *newMap);

    TaxiCenter();

    /**
     * Add driver to drivers list.
     * @param newDriver
     */
    void addDriver(Driver *newDriver);

    /**
     * Add cab to the cab list.
     * @param newCab
     */
    void addCab(Cab *newCab);

    /**
     * Add trip to the trip list.
     * @param newTrip
     */
    void addTrip(TripInformation *newTrip);

    /**
     * The function returns the drivers list.
     * @return vector of trips.
     */
    vector<Driver *> getDriverVec();

    /**
     * The function returns the cab list.
     * @return vector of drivers.
     */
    vector<Cab *> getCabVec();

    /**
     * The function returns the trip list.
     * @return vector of cabs.
     */
    vector<TripInformation *> getTripQueue();

    /**
     * The function removes driver from list.
     * @param newDriver
     */
    void removeDriver(Driver *newDriver);

    /**
     * The function removes cab from cab list.
     * @param newCab
     */
    void removeCab(Cab *newCab);
    /**
     * The function removes trip from trip list.
     * @param newTrip
     */
    void removeTrip(TripInformation *newTrip);
    /**
     * The function print the location of the driver.
     * @param driverId
     */
    void printDriverLocation(int driverId);

    /**
     * The function gets passenger and start a nw trip information.
     * @param p
     */
    void answerCall(Passenger *p);

    /**
     * The functions gets id of cab and return the cab.
     * @param vehicleId
     * @return cab.
     */
    Cab *findCabById(int vehicleId);

    /**
     * The function fins the closet driver by the point
     * the function gets.
     * @param tripLocation
     * @return driver.
     */
    Driver *findClosestDriverByTripLocation(Point tripLocation);

    /**
     * The functions gets id of driver and return the driver.
     * @param driverId
     * @return driver.
     */
    Driver *findDriverById(int driverId);

    /**
     * Start the trips.
     */
    void driving(double time);

    virtual ~TaxiCenter();
};



#endif //TASK2BFS_TAXICENTER_H
