

#ifndef TASK2BFS_DRIVER_H
#define TASK2BFS_DRIVER_H

#include "MaritalStatus.h"
#include "Grid.h"
#include "Matrix.h"
#include "Cab.h"
#include "Searchable.h"
#include "Bfs.h"
#include <stdexcept>

/* class: Driver.
 * The class has derails on driver and has some functions. */
class Driver {
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & id;
        ar & age;
        ar & materialStatus;
        ar & experience;
        ar & satisfaction;
        ar & numOfCustomers;
        ar & cabId;
        ar & currentPoint;
        ar & cab;
        ar & occupied;

    }

private:
    // Members.
    int id;
    double age;
    MaritalStatus materialStatus;
    double experience;
    int satisfaction;
    int numOfCustomers;
    int cabId;
    AbstractNode *currentPoint;
    Cab *cab;
    bool occupied;

    void validate();

public:
    // Constructor - gets the new parameters and update the members value.
    Driver(int newId, double newAge, MaritalStatus newMaterialStatus, double newExperience,
           int cabId, AbstractNode *currentPoint);

    // Default constructor.
    Driver();

    // Destructor.
    ~Driver();

    // The function returns the id of the driver.
    int getId() const;

    // The function sets the id of the driver.
    void setId(int newid);

    // The function returns the age of the driver.
    double getAge();

    // The function sets the status of the driver.
    void setStatus(MaritalStatus newStatus);

    // The function returns the status of the driver.
    MaritalStatus getStatus();

    // The function sets the experience of the driver.
    void setExp(double newExp);

    // The function returns the experience of the driver.
    double getExp();

    // The function returns the current point.
    AbstractNode *getcurrentPoint();

    // The function sets the current point.
    void setCurrentPoint(AbstractNode *node);

    // The function sets the satisfaction if the driver.
    void setSatisfaction(int newSatisfaction);

    // The function returns the satisfaction if the driver.
    int getSatisfaction();

    // the function sets the cab of the driver.
    void setCab(Cab *newTaxiCabInformation);

    // The function returns the cab of the driver.
    Cab *getCab();

    // The function adds the num of customers.
    void addCustomers(int num);

    // The function returns the num of customers.
    void removeCustomer(int num);

    // Getting the cab id.
    int getCabId() const;

    // Moving one step according to his track.
    void moveOneStep(stack<AbstractNode *> *track, Point p);

    // Set the operator ==.
    bool operator==(const Driver &driver) const;

    // Set the operator!= .
    bool operator!=(const Driver &driver) const;

    // Checking if the driver is isOccupied.
    bool isOccupied() const;

    // Setting isOccupied member.
    void setOccupied(bool occupied);
};

#endif //TASK2BFS_DRIVER_H

