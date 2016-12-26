
#ifndef TASK2BFS_PASSENGER_H
#define TASK2BFS_PASSENGER_H

#include "Point.h"
#include <algorithm>


/* Class- Passenger.
 * The members: source point and destination point.
 * The class has set and get to the members. */
class Passenger {
private:
    // Members.
    Point sourcePoint;
    Point destinationPoint;
public:
    Passenger();

    // Constructor.
    Passenger(Point newSource, Point newDestination);

    // The function returns the source point.
    Point getSourcePoint() const;

    // Set destination point.
    void setDestinationPoint(Point dstP);

    // The function returns destination point.
    Point getDestinationPoint() const;

    // Returning a random number between 1 to 5.
    int getFeedback();

    bool operator==(const Passenger &p1) const;

    virtual ~Passenger();
};

#endif //TASK2BFS_PASSENGER_H
