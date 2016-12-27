
#include <stdio.h>
#include <string>
#include <gtest/gtest.h>
#include "../src/TripInformation.h"
#include "Defines.h"
#include "../src/FactoryCab.h"
#include "../src/AbstractNode.h"

// This file is for the TripInformation class tests.
using namespace std;

// Testing the class TripInformation.
class TripInfoTest : public ::testing::Test {
protected:
    // Members of the test.
    FactoryCab factoryCab;
    TripInformation *tripInformation;
    int rideId;
    int time;
    Driver *driver1, *driver2;
    Point startPoint;
    Point endPoint;
    int numOfPassenger;
    double tariff;
    Passenger *passenger1;
    Passenger *passenger2;
    Grid *map1, *map2;
    Node *node1;
    Cab *cab1, *cab2;
    CarManufacturer manufacturer1;
    Color color1;
    /*************************************************************************
    * The function initialize the members of the test before every test.
    **************************************************************************/
    virtual void SetUp() {
        this->startPoint = Point(2, 1);
        this->endPoint = Point(5, 5);
        this->map1 = new Matrix(8, 8);
        this->map2 = new Matrix(7, 7);
        this->driver1 = new Driver(DRIVER_ID1, DRIVER_AGE1, MaritalStatus::MARRIED, DRIVER_EXP1,
                                   CAB_ID1,map1->getSourceElement(0,0));
        this->driver2 = new Driver(DRIVER_ID2, DRIVER_AGE2, MaritalStatus::WIDOWED, DRIVER_EXP2,
                                   CAB_ID2,map2->getSourceElement(0,0));
        this->tripInformation = new TripInformation(rideId, startPoint, endPoint,
                                                    numOfPassenger, tariff ,map1,time);
        this->cab1 = factoryCab.getCab("StandardCab", CAB_ID1, manufacturer1, color1);
        this->cab2 = factoryCab.getCab("LuxuryCab", CAB_ID1, manufacturer1, color1);
        this->passenger1 = new Passenger(Point(3, 2), Point());
        this->passenger2 = new Passenger(Point(6, 4), Point(8, 8));
        this->node1 = new Node (Point(0,0), NULL);
    }
    /*************************************************************************
	* The function delete/destroy the members at the and
    * of every test.
	**************************************************************************/
    virtual void TearDown() {
        delete passenger1;
        delete passenger2;
        delete tripInformation;
        delete driver1;
        delete driver2;
        delete map1;
        delete map2;
        delete cab1;
        delete cab2;
        delete node1;
    }

public:
    /*************************************************************************
    * Constructor - initialize parameters to null or put a details.
    **************************************************************************/
    TripInfoTest() {
        this->tripInformation = NULL;
        this->passenger1 = NULL;
        this->passenger2 = NULL;
        this->map1 = NULL;
        this->map2 = NULL;
        this->driver1 = NULL;
        this->driver2 = NULL;
        this->node1 = NULL;
        this->cab1 = NULL;
        this->cab2 = NULL;
        this->manufacturer1 = CarManufacturer::HONDA;
        this->color1 = Color::RED;
        this->rideId = TRIP_RIDE_ID1;
        this->numOfPassenger = NUM_OF_PASSENGERS;
        this->tariff = TARIFF;
        this->time=TIME1;
    }
    /*************************************************************************
    * Destructor.
    **************************************************************************/
    ~TripInfoTest() {

    }
};
/*************************************************************************
* The function checks the getters functions of TripIformation.
**************************************************************************/
TEST_F(TripInfoTest, CheckTripGetters) {
    EXPECT_EQ(this->rideId, this->tripInformation->getRideId());
    EXPECT_EQ(this->numOfPassenger, this->tripInformation->getNumOfPassenger());
    EXPECT_EQ(this->tariff, this->tripInformation->getTariff());
    EXPECT_EQ(this->endPoint, this->tripInformation->getEndPoint());
    EXPECT_EQ(this->startPoint, this->tripInformation->getStartPoint());
    EXPECT_EQ(0, this->tripInformation->getMeterPassed());
    EXPECT_EQ(this->map1, this->tripInformation->getMap());


}
/*************************************************************************
* The function checks the setters functions of TripIformation.
**************************************************************************/
TEST_F(TripInfoTest, CheckTripSetters) {
    this->tripInformation->setTariff(NEW_TARIFF1);
    this->tripInformation->setNumOfPassenger(NEW_NUM_OF_PASSENGERS);
    this->tripInformation->setMeterPassed(1);
    this->tripInformation->setEndPoint(Point(3, 7));
    this->tripInformation->setDriver(driver2);
    this->tripInformation->setMap(map2);

    EXPECT_EQ(NEW_TARIFF1, this->tripInformation->getTariff());
    EXPECT_EQ(NEW_NUM_OF_PASSENGERS, this->tripInformation->getNumOfPassenger());
    EXPECT_EQ(Point(3, 7), this->tripInformation->getEndPoint());
    EXPECT_EQ(driver2, this->tripInformation->getDriver());
    EXPECT_EQ(map2, this->tripInformation->getMap());
}
/*************************************************************************
* The function checks the add passenger function of TripIformation.
**************************************************************************/
TEST_F(TripInfoTest, CheckAddPassenger) {
    this->tripInformation->addPassenger(this->passenger1);
    ASSERT_EQ(1, this->tripInformation->getPassenger().size()); // check if the list size is '1'.
    this->tripInformation->addPassenger(this->passenger2);
    ASSERT_EQ(2, this->tripInformation->getPassenger().size()); // check if the list size is '2'.

    EXPECT_EQ(this->passenger1->getDestinationPoint(),
              this->tripInformation->getPassenger().front()->getDestinationPoint());
    EXPECT_EQ(this->passenger2->getDestinationPoint(),
              this->tripInformation->getPassenger().back()->getDestinationPoint());
}
/*************************************************************************
* The function checks the delete passenger function of TripIformation.
**************************************************************************/
TEST_F(TripInfoTest, CheckDeletePassenger) {
    this->tripInformation->addPassenger(this->passenger1);
    this->tripInformation->addPassenger(this->passenger2);

    this->tripInformation->removePassenger(this->passenger1);
    ASSERT_EQ(1, this->tripInformation->getPassenger().size()); // check if the list size is '1'.
    EXPECT_EQ(this->passenger2->getDestinationPoint(),
              this->tripInformation->getPassenger().front()->getDestinationPoint());

    this->tripInformation->removePassenger(this->passenger2);
    ASSERT_EQ(0, this->tripInformation->getPassenger().size()); // check if the list size is '0'.
}
/*************************************************************************
* The function checks the validate function of TripIformation.
**************************************************************************/
TEST_F(TripInfoTest, CheckTripValidate) {
    try {
        TripInformation tripInformation5(rideId, startPoint, endPoint,
                                         6, 2,map1,time);
        TripInformation tripInformation4(rideId, startPoint, endPoint,
                                         2, -2.3,map1,time);
    } catch (std::invalid_argument &err) {
        ASSERT_STREQ(err.what(), "tariff can't be negative and can't get more than 5 passenger");
    }
}
/*************************************************************************
* The function checks the function move block in standard cab class.
**************************************************************************/
TEST_F(TripInfoTest, CheckTripMovementStandardCab) {
    this->driver1->setCab(this->cab1);
    this->tripInformation->setDriver(this->driver1);
    this->tripInformation->moveOneStep();
    this->node1->setPoint(Point(2, 2));
    ASSERT_TRUE(*(node1) == *(this->tripInformation->getDriver()->getcurrentPoint()));
    ASSERT_EQ(this->tripInformation->getDriver()->getCab()->getKilometerPassed(), 1);

    this->tripInformation->moveOneStep();
    this->node1->setPoint(Point(2, 3));
    ASSERT_EQ(this->tripInformation->getDriver()->getCab()->getKilometerPassed(), 2);
    ASSERT_TRUE(*(node1) == *(this->tripInformation->getDriver()->getcurrentPoint()));

    this->tripInformation->moveOneStep();
    this->node1->setPoint(Point(2, 4));
    ASSERT_EQ(this->tripInformation->getDriver()->getCab()->getKilometerPassed(), 3);
    ASSERT_TRUE(*(node1) == *(this->tripInformation->getDriver()->getcurrentPoint()));
}

/*************************************************************************
* The function checks the function move block for luxury cab.
**************************************************************************/
    TEST_F(TripInfoTest, CheckTripMovementLuxuryCab){
    this->driver2->setCab(this->cab2);
    this->tripInformation->setDriver(this->driver2);
    this->tripInformation->moveOneStep();
    this->node1->setPoint(Point(2,3));
    ASSERT_TRUE(*(node1) == * (this->tripInformation->getDriver()->getcurrentPoint()));
    ASSERT_EQ(this->tripInformation->getDriver()->getCab()->getKilometerPassed(), 2);

    this->tripInformation->moveOneStep();
    this->node1->setPoint(Point(2,5));
    ASSERT_EQ(this->tripInformation->getDriver()->getCab()->getKilometerPassed(), 4);
    ASSERT_TRUE(*(node1) == * (this->tripInformation->getDriver()->getcurrentPoint()));
}
/*************************************************************************
* The function checks the move of all the trails until the destination.
**************************************************************************/
TEST_F(TripInfoTest, CheckAllTripMovement){
    this->driver1->setCab(this->cab1);
    this->tripInformation->setDriver(this->driver1);
    this->tripInformation->moveTrail();
    this->node1->setPoint(Point(5,5));
    ASSERT_EQ(this->tripInformation->getDriver()->getCab()->getKilometerPassed(), 7);
    ASSERT_TRUE(*(node1) == * (this->tripInformation->getDriver()->getcurrentPoint()));

}
/*************************************************************************
* The function checks the function rideCost in trip information class.
**************************************************************************/
TEST_F(TripInfoTest, CheckTripRideCost){
    this->driver1->setCab(this->cab1);
    this->tripInformation->setDriver(this->driver1);
    EXPECT_EQ(TARIFF*1, this->tripInformation->rideCost());
    this->driver1->setCab(this->cab2);
    EXPECT_EQ(TARIFF*2, this->tripInformation->rideCost());
}
