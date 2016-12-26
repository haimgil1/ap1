
#include <stdio.h>
#include <string>
#include <gtest/gtest.h>
#include "../src/TripInformation.h"

// This file is for the Passenger class tests.
using namespace std;

// Testing the class Passenger.
class PassengerTest : public ::testing::Test {
protected:
    // Members of the test.
    Passenger *passenger;
    Point p1, p2;
    /*************************************************************************
	* The function initialize p1, p2 and passenger before every test.
	**************************************************************************/
    virtual void SetUp() {
        this->p1 = Point(1, 1);
        this->p2 = Point(2, 6);
        this->passenger = new Passenger(p1, p2);
    }
    /*************************************************************************
	* The function delete/destroy the members at the and
    * of every test.
	**************************************************************************/
    virtual void TearDown() {
        delete passenger;
    }

public:
    /*************************************************************************
    * Constructor - initialize passenger to null.
    **************************************************************************/
    PassengerTest() {
        this->passenger = NULL;
    }
    /*************************************************************************
    * Destructor.
    **************************************************************************/
    ~PassengerTest() {

    }
};
/*************************************************************************
* The function checks the passenger getters of the functions.
**************************************************************************/
TEST_F(PassengerTest, CheckPassengerGetters) {
    EXPECT_EQ(this->p1, this->passenger->getSourcePoint());
    EXPECT_EQ(this->p2, this->passenger->getDestinationPoint());

}
/*************************************************************************
* The function checks the passenger setters of the functions.
**************************************************************************/
TEST_F(PassengerTest, CheckPassengerSetters) {
    this->passenger->setDestinationPoint(Point(9, 9));
    EXPECT_EQ(Point(9, 9), this->passenger->getDestinationPoint());
}

/*************************************************************************
* The function checks the passenger feedback.
**************************************************************************/
TEST_F(PassengerTest, CheckPassengerFeedback) {
    int num[] = {1, 2, 3, 4, 5};
    ASSERT_TRUE(find(num, num, this->passenger->getFeedback()));
}

