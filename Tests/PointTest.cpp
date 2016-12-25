
#include "../src/Node.h"
#include "gtest/gtest.h"
#include "Defines.h"

// This file is for the Point class tests.
using namespace std;

// Testing the class Point.
class PointTest : public ::testing::Test {
protected:
    // Members of the test.
    Point p1;
    Point p2;
    Point p3;

    /*************************************************************************
	* The function initialize p1, p2, p3 before every test.
	**************************************************************************/
    virtual void SetUp() {
        this->p1 = Point(P1_X, P1_Y);
        this->p2 = Point(P2_X, P2_Y);
        this->p3 = p2;
    }

    /*************************************************************************
	* The function delete/destroy the members at the and
    * of every test.
	**************************************************************************/
    virtual void TearDown() {

    }

public:
    /*************************************************************************
    * Constructor.
    **************************************************************************/
    PointTest() {

    }

    /*************************************************************************
    * Destructor.
    **************************************************************************/
    ~PointTest() {

    }
};
/*************************************************************************
* The function checks the point getters of the functions.
**************************************************************************/
TEST_F(PointTest, checkPointGetters) {
    EXPECT_EQ(P1_X, p1.getX());
    EXPECT_EQ(P1_Y, p1.getY());
    EXPECT_EQ(P2_X, p2.getX());
    EXPECT_EQ(P2_Y, p2.getY());
}
/*************************************************************************
* The function checks the point setters of the functions.
**************************************************************************/
TEST_F(PointTest, checkPointSetters) {
    this->p1.setX(NEW_P1_X);
    this->p1.setY(NEW_P1_Y);
    this->p2.setX(NEW_P2_X);
    this->p2.setY(NEW_P2_Y);
    this->p3.setX(NEW_P3_X);
    this->p3.setY(NEW_P3_Y);

    EXPECT_EQ(NEW_P1_X, p1.getX());
    EXPECT_EQ(NEW_P1_Y, p1.getY());
    EXPECT_EQ(NEW_P2_X, p2.getX());
    EXPECT_EQ(NEW_P2_Y, p2.getY());
    EXPECT_EQ(NEW_P3_X, p3.getX());
    EXPECT_EQ(NEW_P3_Y, p3.getY());
}
/*************************************************************************
* The function checks the operator functions of the functions.
**************************************************************************/
TEST_F(PointTest, checkPointOperators) {
    EXPECT_TRUE(p3 == p2); // Check operator "==".
    testing::internal::CaptureStdout(); // Check operator "<<"
    cout << p1;
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(5,53)\n");
}
/*************************************************************************
* The function checks the validate function of point.
**************************************************************************/
TEST_F(PointTest, CheckPointValidate) {
    try {
        // Set incorrect parameters.
        Point p4(0, -2);
        Point p5(-6, 4);
        Point p6(-2, -2);
    } catch (std::invalid_argument &err) {
        ASSERT_STREQ(err.what(), "can't get negative coordinate");
    }
}







