
#include <stdio.h>
#include <string>
#include <gtest/gtest.h>
#include "../src/LuxuryCab.h"
#include "Defines.h"
#include "../src/FactoryCab.h"

// This file is for the Cab class tests.
using namespace std;

// Testing the class Cab.
class CabTest : public ::testing::Test {
protected:
    // Members of the test.
    FactoryCab factoryCab;
    Cab *cab1, *cab2;
    int cabId1, cabId2;
    CarManufacturer manufacturer1, manufacturer2;
    Color color1, color2;

    /*************************************************************************
	* The function initialize cab1 and cab2 before every test.
	**************************************************************************/
    virtual void SetUp() {
        this->cab1 = factoryCab.getCab("StandardCab", cabId1, manufacturer1, color1);
        this->cab2 = factoryCab.getCab("LuxuryCab", cabId2, manufacturer2, color2);
    }

    /*************************************************************************
	* The function delete/destroy the members cab1 and cab2 at the and
    * of every test.
	**************************************************************************/
    virtual void TearDown() {
        delete cab1;
        delete cab2;
    }

public:
    /*************************************************************************
    * Constructor - initialize parameters to null or put them details.
    **************************************************************************/
    CabTest() {
        this->cab1 = NULL;
        this->cab2 = NULL;
        this->cabId1 = CAB_ID1;
        this->cabId2 = CAB_ID2;
        this->manufacturer1 = CarManufacturer::HONDA;
        this->manufacturer2 = CarManufacturer::SUBARO;
        this->color1 = Color::BLUE;
        this->color2 = Color::PINK;

    }

    /*************************************************************************
    * Destructor.
    **************************************************************************/
    ~CabTest() {

    }
};
/*************************************************************************
* The function checks the cab's getters of the functions.
**************************************************************************/
TEST_F(CabTest, CheckCabGetters) {
    EXPECT_EQ(this->cabId1, this->cab1->getCabId());
    EXPECT_EQ(0, this->cab1->getKilometerPassed());
    EXPECT_EQ(this->manufacturer1, this->cab1->getManufacturer());
    EXPECT_EQ(this->color1, this->cab1->getColor());
}
/*************************************************************************
* The function checks the cab's setters of the functions.
**************************************************************************/
TEST_F(CabTest, CheckCabSetters) {
    this->cab1->setCabId(NEW_CAB_ID1);
    this->cab1->setKilometerPassed(NEW_KLM_PASSED1);
    this->cab1->setManufacturer(CarManufacturer::TESLA);
    this->cab1->setColor(Color::WHITE);

    EXPECT_EQ(NEW_CAB_ID1, this->cab1->getCabId());
    EXPECT_EQ(NEW_KLM_PASSED1, this->cab1->getKilometerPassed());
    EXPECT_EQ(CarManufacturer::TESLA, this->cab1->getManufacturer());
    EXPECT_EQ(Color::WHITE, this->cab1->getColor());
}

