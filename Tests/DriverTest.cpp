
#include <stdio.h>
#include <string>
#include <gtest/gtest.h>
#include "../src/MaritalStatus.h"
#include "../src/TripInformation.h"
#include "../src/FactoryCab.h"
#include "Defines.h"


// This file is for the Driver class tests.
using namespace std;

// Testing the class Driver.
class DriverTest : public ::testing::Test {
protected:
    // Members of the test.
    FactoryCab factoryCab;
    Driver *driver1, *driver2;
    int id1;
    double age1;
    MaritalStatus materialStatus1;
    double exp1;
    int satisfaction1;
    Cab *taxiCab2;
    Grid *map1, *map2;

    /*************************************************************************
	* The function initialize taxiCab2, tripinfo1, tripInfo2, map1, map2,
    * and driver1 before every test.
	**************************************************************************/
    virtual void SetUp() {
        this->taxiCab2 = factoryCab.getCab("LuxuryCab", CAB_ID2,
                                           CarManufacturer::HONDA, Color::BLUE);
        this->map1 = new Matrix(8, 8);
        this->map2 = new Matrix(7, 7);
        this->driver1 = new Driver(DRIVER_ID1, DRIVER_AGE1, MaritalStatus::MARRIED, DRIVER_EXP1,
                                   CAB_ID1, map1->getSourceElement(0, 0));
    }

    /*************************************************************************
	* The function delete/destroy the members at the and
    * of every test.
	**************************************************************************/
    virtual void TearDown() {
        delete driver1;
        delete driver2;
        delete taxiCab2;
        delete map1;
        delete map2;
    }

public:
    /*************************************************************************
    * Constructor - initialize parameters to null or put them details.
    **************************************************************************/
    DriverTest() {
        this->driver1 = NULL;
        this->driver2 = NULL;
        this->taxiCab2 = NULL;
        this->map1 = NULL;
        this->map2 = NULL;
        this->id1 = DRIVER_ID1;
        this->age1 = DRIVER_AGE1;
        this->materialStatus1 = MaritalStatus::MARRIED;
        this->exp1 = DRIVER_EXP1;
        this->satisfaction1 = 0;
    }

    /*************************************************************************
    * Destructor.
    **************************************************************************/
    ~DriverTest() {

    }
};
/*************************************************************************
* The function checks the driver's getters of the functions.
**************************************************************************/
TEST_F(DriverTest, CheckDriverGetters) {
    EXPECT_EQ(this->id1, this->driver1->getId());
    EXPECT_EQ(this->age1, this->driver1->getAge());
    EXPECT_EQ(this->materialStatus1, this->driver1->getStatus());
    EXPECT_EQ(this->exp1, this->driver1->getExp());
    EXPECT_EQ(this->satisfaction1, this->driver1->getSatisfaction());

}
/*************************************************************************
* The function checks the driver's setters of the functions.
**************************************************************************/
TEST_F(DriverTest, CheckDriverSetters) {
    this->driver1->setStatus(MaritalStatus::SINGLE);
    this->driver1->setExp(DRIVER_EXP2);
    this->driver1->setSatisfaction(DRIVER_SATISFACTION1);
    this->driver1->setCab(taxiCab2);


    EXPECT_EQ(MaritalStatus::SINGLE, this->driver1->getStatus());
    EXPECT_EQ(DRIVER_EXP2, this->driver1->getExp());
    EXPECT_EQ(DRIVER_SATISFACTION1, this->driver1->getSatisfaction());
    EXPECT_EQ(taxiCab2, this->driver1->getCab());

}
/*************************************************************************
* The function checks the validate of parameters in driver.
**************************************************************************/
TEST_F(DriverTest, CheckDriverValidate) {
    try {
        Driver driver(DRIVER_ID1, -2, MaritalStatus::MARRIED, DRIVER_EXP1, CAB_ID1,
                      map1->getSourceElement(0, 0));
    } catch (std::invalid_argument &err) {
        ASSERT_STREQ(err.what(), "age or experience can't be negative");
    }
}
