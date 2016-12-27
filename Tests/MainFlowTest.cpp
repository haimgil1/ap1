#include "gtest/gtest.h"
#include "Defines.h"
#include "../src/Node.h"
#include "../src/Matrix.h"
#include "../src/Driver.h"
#include "../src/TaxiCenter.h"
#include "../src/FactoryCab.h"
#include "../src/MainFlow.h"

// Testing the class Matrix.
class MainFlowTest : public ::testing::Test {
protected:
    // Members of the test.
    MainFlow mainFlow;
    TaxiCenter *taxiCenter1;
    FactoryCab factoryCab;
    Driver *driver1;
    Cab *taxiCab1;
    TripInformation *tripInfo1;
    Grid *map1;
    Cab *cab1;
    Node *node1;
    Passenger *pass1;

    /*************************************************************************
    * The function initialize the members of the test before every test.
    **************************************************************************/
    virtual void SetUp() {

        this->map1 = new Matrix(6, 6);
        this->taxiCenter1 = new TaxiCenter (map1);
        this->cab1 = factoryCab.getCab("StandardCab", 1,
                                       CarManufacturer::HONDA, Color::GREEN);
        this->driver1 = new Driver(1, 20, MaritalStatus::MARRIED, 5, 40,
                                   map1->getSourceElement(0, 0));
        this->taxiCab1 = factoryCab.getCab("LuxuryCab", CAB_ID1, CarManufacturer::FIAT,
                                           Color::BLUE);
        this->tripInfo1 = new TripInformation(TRIP_RIDE_ID1, Point(0, 0), Point(3, 3),
                                              TRIP_NUM_PASS1, TRIP_TARIFF1, map1,TIME1);
        node1 = new Node(Point(1, 2), NULL);
        pass1 = new Passenger(Point(0, 0), Point(1, 1));
    }

    /*************************************************************************
	* The function delete/destroy the members at the and
    * of every test.
	**************************************************************************/
    virtual void TearDown() {
        delete tripInfo1;
        delete driver1;
        delete cab1;
        delete node1;
        delete pass1;
        delete taxiCab1;
        delete map1;
        delete taxiCenter1;
    }

public:
    /*************************************************************************
    * Constructor - initialize the parameters to null.
    **************************************************************************/
    MainFlowTest() {
        this->taxiCenter1 = NULL;
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
    ~MainFlowTest() {

    }
};

 /************************************************************************
 * The function checks the cab parsing function of MainFlow class.
 **************************************************************************/
 TEST_F(MainFlowTest, checkCabParsing) {
    Cab * cab = mainFlow.cabParser(1, 0, 'H', 'G');
     EXPECT_TRUE(*(this->cab1) == *(cab));
    delete cab;
 }
 /************************************************************************
 * The function checks the driver parsing function of MainFlow class.
 **************************************************************************/
 TEST_F(MainFlowTest, checkDriverParsing) {
     //EXPECT_TRUE(*(this->driver1) == *(driver));
 }
 /************************************************************************
 * The function checks the trip information parsing function of
  * MainFlow class.
 **************************************************************************/
 TEST_F(MainFlowTest, checkTripInfoParsing) {
    TripInformation * tripInformation =mainFlow.tripInfoParser(TRIP_RIDE_ID1, 0, 0, 3, 3,
                                                               TRIP_NUM_PASS1, TRIP_TARIFF1,
                                                               this->map1,TIME1);
     EXPECT_TRUE(*(this->tripInfo1) == *(tripInformation));
    delete tripInformation;
 }

/************************************************************************
 * The function checks the map parsing function of MainFlow class.
 **************************************************************************/
// TEST_F(MainFlowTest, checkMapParsing) {
//    Grid* map =mainFlow.MapParser(6, 6);
//     EXPECT_TRUE(*(this->map1->getSourceElement(0, 0)) ==
//                 *(map->getSourceElement(0, 0)));
//     EXPECT_TRUE(*(this->map1->getDestinationElement(6, 6)) ==
//                 *(map->getDestinationElement(6, 6)));
//    delete map;
// }
