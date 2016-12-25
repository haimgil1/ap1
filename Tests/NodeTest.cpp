
#include "../src/Node.h"
#include "gtest/gtest.h"
#include "Defines.h"


// This file is for the Node class tests.
using namespace std;

// Testing the class Node.
class NodeTest : public ::testing::Test {
protected:
    // Members of the test.
    Point p1;
    Point p2;
    Point p3;
    Node *node1;
    Node *node2;
    Node *node3;
    Node *node4;

    /*************************************************************************
	* The function initialize the members node1, node2, node3, node4
     * of the test before every test.
	**************************************************************************/
    virtual void SetUp() {
        this->p1 = Point(P1_X, P1_Y);
        this->p2 = Point(P2_X, P2_Y);
        this->p3 = p2;
        this->node1 = new Node(p1, NULL);
        this->node2 = new Node(p2, node1);
        this->node3 = new Node(p3, node2);
        this->node4 = new Node(p3, node2);
    }

    /*************************************************************************
	* The function delete/destroy the members node1, node2, node3, node4
    * at the and of every test.
	**************************************************************************/
    virtual void TearDown() {
        delete node1;
        delete node2;
        delete node3;
        delete node4;
    }

public:
    /*************************************************************************
    * Constructor - initialize parameters to null.
    **************************************************************************/
    NodeTest() {
        this->node1 = NULL;
        this->node2 = NULL;
        this->node3 = NULL;
        this->node4 = NULL;
    }

    /*************************************************************************
    * Destructor.
    **************************************************************************/
    ~NodeTest() {

    }
};
/*************************************************************************
* The function checks the getters function of node.
**************************************************************************/
TEST_F(NodeTest, checkNodeGetters) {
    EXPECT_EQ(p1, node1->getPoint());
    EXPECT_EQ(node1, node2->getPrev());
    EXPECT_EQ(-1, node1->getDistance());
}
/*************************************************************************
* The function checks the setters function of node.
**************************************************************************/
TEST_F(NodeTest, checkNodeSetters) {
    this->node1->setPrevNode(node2);
    this->node1->setDistance(DISTANCE_NODE);
    EXPECT_EQ(node2, node1->getPrev());
    EXPECT_EQ(DISTANCE_NODE, node1->getDistance());
}
/*************************************************************************
* The function checks the operator functions of node.
**************************************************************************/
TEST_F(NodeTest, checkNodeOperators) {
    EXPECT_TRUE(*node3 == *node4); // Check operator "==".
    testing::internal::CaptureStdout(); // Check operator "<<".
    cout << node2->getPoint();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(8,9)\n");
}


