
#include "gtest/gtest.h"
#include "Defines.h"
#include "../src/Node.h"
#include "../src/Matrix.h"
#include "../src/Driver.h"
#include "../src/TaxiCenter.h"
#include "../src/FactoryCab.h"


// This file is for the TaxiCenter class tests.
using namespace std;

// Testing the class TaxiCenter.
class TaxiCenterTest : public ::testing::Test {
protected:
    // Members of the test.
    TaxiCenter* taxiCenter1;
    vector<Driver *> drivers;
    vector<Cab *> cabs;
    vector<TripInformation *> trips;
    FactoryCab factoryCab;
    Driver *driver1, *driver2;
    Cab *taxiCab1, *taxiCab2;
    TripInformation *tripInfo1, *tripInfo2;
    Grid *map1;
    Cab *cab1;
    Node *node1;
    Passenger *pass1;
    AbstractNode *p1, *p2;
    /*************************************************************************
    * The function initialize the members of the test before every test.
    **************************************************************************/
    virtual void SetUp() {

        this->map1 = new Matrix(8, 8);
        this->taxiCenter1 = new TaxiCenter (map1);
        this->taxiCab1 = factoryCab.getCab("StandardCab", CAB_ID1,
                                           CarManufacturer::FIAT, Color::GREEN);
        this->taxiCab2 = factoryCab.getCab("LuxuryCab", CAB_ID2,
                                           CarManufacturer::HONDA, Color::GREEN);
        this->driver1 = new Driver(DRIVER_ID1, DRIVER_AGE1, MaritalStatus::MARRIED, DRIVER_EXP1,
                                   CAB_ID1,map1->getSourceElement(0,0));
        this->driver2 = new Driver(DRIVER_ID2, DRIVER_AGE2, MaritalStatus::DIVORCED, DRIVER_EXP2,
                                   CAB_ID2,map1->getSourceElement(0,0));
        this->cab1 = factoryCab.getCab("StandardCab", CAB_ID1, CarManufacturer::FIAT,
                                       Color::BLUE);
        this->tripInfo1 = new TripInformation(TRIP_RIDE_ID1, Point(0, 0), Point(3, 3),
                                              TRIP_NUM_PASS1, TRIP_TARIFF1, map1,TIME1);
        this->tripInfo2 = new TripInformation(TRIP_RIDE_ID2, Point(0, 0), Point(2, 3),
                                              TRIP_NUM_PASS2, TRIP_TARIFF2, map1,TIME1);
        this->node1 = new Node(Point(1, 2), NULL);
        this->pass1 = new Passenger(Point(0, 0), Point(1, 1));

        this->p1 = new Node(Point(1,1), NULL);
        this->p2 = new Node(Point(0,1), NULL);

    }
    /*************************************************************************
	* The function delete/destroy the members at the and
    * of every test.
	**************************************************************************/
    virtual void TearDown() {
        delete tripInfo2;
        delete node1;
        delete pass1;
        delete map1;
        delete p1;
        delete p2;
        delete driver1;
        delete driver2;
        delete taxiCab1;
        delete taxiCab2;
        delete tripInfo1;
        delete cab1;
        delete taxiCenter1;
    }

public:
    /*************************************************************************
    * Constructor - initialize the parameters to null.
    **************************************************************************/
    TaxiCenterTest() {
        this->tripInfo1 = NULL;
        this->driver1 = NULL;
        this->node1 = NULL;
        this->pass1 = NULL;
        this->cab1 = NULL;
        this->taxiCab1 = NULL;
        this->map1 = NULL;
        this->taxiCenter1 =NULL;
    }
    /*************************************************************************
    * Destructor.
    **************************************************************************/
    ~TaxiCenterTest() {

    }
};
/*************************************************************************
* The function checks the Taxi Center getters of the functions.
**************************************************************************/
TEST_F(TaxiCenterTest, checkGettersTaxiCenter) {
    // check get driver list.
    drivers.push_back(driver1);
    Driver * driver = new Driver(DRIVER_ID1, DRIVER_AGE1, MaritalStatus::MARRIED, DRIVER_EXP1,
                                 CAB_ID1,map1->getSourceElement(0,0));
    taxiCenter1->addDriver(driver);

    EXPECT_EQ(drivers.size(), taxiCenter1->getDriverVec().size());

    // check get cabs list.
    cabs.push_back(cab1);
    Cab* cab = factoryCab.getCab("StandardCab", CAB_ID1,
                                  CarManufacturer::FIAT, Color::GREEN);
    taxiCenter1->addCab(cab);

    EXPECT_EQ(cabs.size(), taxiCenter1->getCabVec().size());


}
/*************************************************************************
* The function checks the add functions of TaxiCenter.
**************************************************************************/
TEST_F(TaxiCenterTest, checkAddTaxiCenter) {
    // add one driver to the drivers list.
    Driver * driver = new Driver(DRIVER_ID1, DRIVER_AGE1, MaritalStatus::MARRIED, DRIVER_EXP1,
                                 CAB_ID1,map1->getSourceElement(0,0));
    taxiCenter1->addDriver(driver);
    EXPECT_EQ(1, taxiCenter1->getDriverVec().size());
    EXPECT_EQ(driver1->getId(), taxiCenter1->getDriverVec().front()->getId());

    // add one cab to the cabs list.
    Cab* cab = factoryCab.getCab("StandardCab", CAB_ID1,
                                 CarManufacturer::FIAT, Color::GREEN);
    taxiCenter1->addCab(cab);
    EXPECT_EQ(1, taxiCenter1->getCabVec().size());
    EXPECT_EQ(taxiCab1->getCabId(), taxiCenter1->getCabVec().front()->getCabId());

}
/*************************************************************************
* The function checks the remove functions of TaxiCenter.
**************************************************************************/
TEST_F(TaxiCenterTest, checkRemovesTaxiCenter) {

    Driver * driver3 = new Driver(DRIVER_ID1, DRIVER_AGE1, MaritalStatus::MARRIED, DRIVER_EXP1,
                                 CAB_ID1,map1->getSourceElement(0,0));
    Driver * driver4 = new Driver(DRIVER_ID1, DRIVER_AGE1, MaritalStatus::MARRIED, DRIVER_EXP1,
                                 CAB_ID1,map1->getSourceElement(0,0));
    taxiCenter1->addDriver(driver3);
    taxiCenter1->addDriver(driver4);
    // remove one driver
    taxiCenter1->removeDriver(driver3);
    delete driver3;
    EXPECT_EQ(1, taxiCenter1->getDriverVec().size());
    EXPECT_EQ(driver4->getId(), taxiCenter1->getDriverVec().front()->getId());

    Cab* cab3 = factoryCab.getCab("StandardCab", CAB_ID1,
                                 CarManufacturer::FIAT, Color::GREEN);
    Cab* cab4 = factoryCab.getCab("StandardCab", CAB_ID1,
                                 CarManufacturer::FIAT, Color::GREEN);
    taxiCenter1->addCab(cab3);
    taxiCenter1->addCab(cab4);
    // remove one cab
    taxiCenter1->removeCab(cab4);
    delete cab4;
    EXPECT_EQ(1, taxiCenter1->getCabVec().size());

}

/*************************************************************************
* The function checks the print driver location fuction of TaxiCenter.
**************************************************************************/
TEST_F(TaxiCenterTest, checkPrintDriverLocation) {
    Driver * driver = new Driver(DRIVER_ID1, DRIVER_AGE1, MaritalStatus::MARRIED, DRIVER_EXP1,
                                  CAB_ID1,map1->getSourceElement(0,0));
    taxiCenter1->addDriver(driver);
    taxiCenter1->printDriverLocation(driver->getId());
}
/*************************************************************************
* The function checks the checkCall function of TaxiCenter.
**************************************************************************/
TEST_F(TaxiCenterTest, checkCall) {
    unsigned long numLocations = taxiCenter1->getTripQueue().size();
    taxiCenter1->answerCall(pass1);
    EXPECT_FALSE(numLocations + 1 == taxiCenter1->getTripQueue().size());
}
/*************************************************************************
* The function checks the findCabById function of TaxiCenter.
* The function gets an id of the cab and return the cab.
**************************************************************************/
TEST_F(TaxiCenterTest, checkFindCabById) {
    Cab* cab = factoryCab.getCab("StandardCab", CAB_ID1,
                                  CarManufacturer::FIAT, Color::GREEN);
    taxiCenter1->addCab(cab);
    EXPECT_EQ(this->taxiCenter1->findCabById(CAB_ID1)->getCabId() , cab->getCabId());
}
/*************************************************************************
* The function checks the findDriverById function of TaxiCenter.
* The function gets an id of the driver and return the driver itself.
**************************************************************************/
TEST_F(TaxiCenterTest, checkFindDriverById) {
    Driver * driver = new Driver(DRIVER_ID1, DRIVER_AGE1, MaritalStatus::MARRIED, DRIVER_EXP1,
                                 CAB_ID1,map1->getSourceElement(0,0));
    taxiCenter1->addDriver(driver);
    EXPECT_EQ(this->taxiCenter1->findDriverById(DRIVER_ID1)->getId() , driver->getId());
}
/*************************************************************************
* The function checks the findClosestDriverByTripLocation of TaxiCenter.
* The function gets a new point to the trip and return the driver at the
* point.
**************************************************************************/
TEST_F(TaxiCenterTest, checkFindClosestDriverByTripLocation) {
    Driver * driver3 = new Driver(DRIVER_ID1, DRIVER_AGE1, MaritalStatus::MARRIED, DRIVER_EXP1,
                                 CAB_ID1,map1->getSourceElement(0,0));
    Driver * driver4 = new Driver(DRIVER_ID1, DRIVER_AGE1, MaritalStatus::MARRIED, DRIVER_EXP1,
                                 CAB_ID1,map1->getSourceElement(0,0));
    driver3->setCurrentPoint(p1);
    driver4->setCurrentPoint(p2);
    taxiCenter1->addDriver(driver3);
    taxiCenter1->addDriver(driver4);
    EXPECT_EQ(this->taxiCenter1->findClosestDriverByTripLocation(Point(1,1))->getId() ,
              driver3->getId());
}
/*************************************************************************
* The function checks the startDriving function of TaxiCenter.
* The function starts all the trails.
**************************************************************************/
TEST_F(TaxiCenterTest, checkStartDriving) {
    Driver * driver = new Driver(DRIVER_ID1, DRIVER_AGE1, MaritalStatus::MARRIED, DRIVER_EXP1,
                                  CAB_ID1,map1->getSourceElement(0,0));
    Cab* cab = factoryCab.getCab("StandardCab", CAB_ID1,
                                  CarManufacturer::FIAT, Color::GREEN);
    TripInformation* tripInformation=new TripInformation(TRIP_RIDE_ID1, Point(0, 0), Point(3, 3),
                                                         TRIP_NUM_PASS1, TRIP_TARIFF1, map1,TIME1);
    driver->setCab(cab);
    tripInformation->setDriver(driver);
    this->taxiCenter1->addTrip(tripInformation);
    this->taxiCenter1->driving(0);
    ASSERT_TRUE(*(driver->getcurrentPoint()) == *p2);
    delete cab;
    delete driver;
}

