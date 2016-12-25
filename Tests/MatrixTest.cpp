
#include "gtest/gtest.h"
#include "Defines.h"
#include "../src/Node.h"
#include "../src/Matrix.h"


// This file is for the Matrix class tests.
using namespace std;

// Testing the class Matrix.
class MatrixTest : public ::testing::Test {
protected:
    // Members of the test.
    Matrix *matrix1;
    Point p1;
    Point p2;
    Node *node1, *node2, *node3, *node4, *node5;
    Node *neighbour1, *neighbour2;

    /*************************************************************************
	* The function initialize the members of the test before every test.
	**************************************************************************/
    virtual void SetUp() {
        this->p1 = Point(P1_X, P1_Y);
        this->p2 = Point(P2_X, P2_Y);
        this->node1 = new Node(p1, NULL);
        this->node2 = new Node(p2, node1);
        this->node3 = new Node(Point(0, 0), NULL);
        this->node5 = new Node(Point(0, 0), NULL);
        this->neighbour1 = new Node(Point(0, 1), NULL);
        this->neighbour2 = new Node(Point(1, 0), NULL);
        this->node5->addNeighbor(neighbour1);
        this->node5->addNeighbor(neighbour2);
        this->node4 = new Node(Point(MATRIX_N1 - 1, MATRIX_M1 - 1), NULL);
        this->matrix1 = new Matrix(MATRIX_N1, MATRIX_M1);
    }

    /*************************************************************************
	* The function delete/destroy the members test at the and
    * of every test.
	**************************************************************************/
    virtual void TearDown() {
        delete matrix1;
        delete node1;
        delete node2;
        delete node3;
        delete node4;
        delete node5;
        delete neighbour1;
        delete neighbour2;
    }

public:
    /*************************************************************************
    * Constructor - initialize parameters to null or put them details.
    **************************************************************************/
    MatrixTest() {
        this->matrix1 = NULL;
        this->node1 = NULL;
        this->node2 = NULL;
        this->node3 = NULL;
        this->node4 = NULL;
        this->node5 = NULL;
        this->neighbour1 = NULL;
        this->neighbour2 = NULL;
        this->p1 = NULL;
        this->p2 = NULL;

    }

    /*************************************************************************
    * Destructor.
    **************************************************************************/
    ~MatrixTest() {

    }
};

/*************************************************************************
* The function checks the neighbors function of node.
**************************************************************************/
TEST_F(MatrixTest, checkNeighborsMatrix) {
    EXPECT_EQ(*(node5->getNeighbors()[0]), *(matrix1->getSourceElement(0, 0)->getNeighbors()[0]));
    EXPECT_EQ(*(node5->getNeighbors()[1]), *(matrix1->getSourceElement(0, 0)->getNeighbors()[1]));
}
/*************************************************************************
* The function checks the source function of node.
**************************************************************************/
TEST_F(MatrixTest, checkSourceNode) {

    EXPECT_TRUE(*(this->node3) == *(this->matrix1->getSourceElement(0, 0)));
    // Check the limits of the matrix.
    EXPECT_GE(10, this->matrix1->getDestinationElement(MATRIX_N1 - 1,
                                                       MATRIX_M1 - 1)->getPoint().getX());
    EXPECT_GE(10, this->matrix1->getDestinationElement(MATRIX_N1 - 1,
                                                       MATRIX_M1 - 1)->getPoint().getY());
    EXPECT_LE(0, this->matrix1->getDestinationElement(MATRIX_N1 - 1,
                                                      MATRIX_M1 - 1)->getPoint().getX());
    EXPECT_LE(0, this->matrix1->getDestinationElement(MATRIX_N1 - 1,
                                                      MATRIX_M1 - 1)->getPoint().getY());
}
/*************************************************************************
* The function checks the destination function of node.
**************************************************************************/
TEST_F(MatrixTest, checkDestinationNode) {

    EXPECT_TRUE(*(this->node4) ==
                *(this->matrix1->getDestinationElement(MATRIX_N1 - 1, MATRIX_M1 - 1)));
    // Check the limits of the matrix.
    EXPECT_GE(10, this->matrix1->getDestinationElement(MATRIX_N1 - 1,
                                                       MATRIX_M1 - 1)->getPoint().getX());
    EXPECT_GE(10, this->matrix1->getDestinationElement(MATRIX_N1 - 1,
                                                       MATRIX_M1 - 1)->getPoint().getY());
    EXPECT_LE(0, this->matrix1->getDestinationElement(MATRIX_N1 - 1,
                                                      MATRIX_M1 - 1)->getPoint().getX());
    EXPECT_LE(0, this->matrix1->getDestinationElement(MATRIX_N1 - 1,
                                                      MATRIX_M1 - 1)->getPoint().getY());
}
/*************************************************************************
* The function checks the validate function of the limits.
**************************************************************************/
TEST_F(MatrixTest, CheckMatrixValidate) {

    try {
        // Set incorrect parameters.
        Matrix m1(-1, 9);
        Matrix m2(20, 3);
        Matrix m3(8, -2);
        Matrix m4(5, 15);
        Matrix m5(203, 24);
        Matrix m6(-10, -2);

    } catch (std::invalid_argument &err) {
        ASSERT_STREQ(err.what(), "wrong range");
    }

}

