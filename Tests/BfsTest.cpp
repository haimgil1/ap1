
#include "gtest/gtest.h"
#include "Defines.h"
#include "../src/Node.h"
#include "../src/Bfs.h"

// This file is for the BFS class tests.
using namespace std;

// Testing the class Bfs.
class BfsTest : public ::testing::Test {
protected:
    // Members of the test.
    stack<AbstractNode *> trailBfs;
    Grid *matrix;
    Searchable *bfs;
    Node *node1, *node2, *node3, *node4, *node5, *node6, *node7, *node8;

    /*************************************************************************
	* The function initialize matrix before every test.
	**************************************************************************/
    virtual void SetUp() {
        matrix = new Matrix(MATRIX_N3, MATRIX_M3);
        bfs = new Bfs();
        this->node1 = new Node(Point(2, 2), NULL);
        this->node2 = new Node(Point(1, 2), NULL);
        this->node3 = new Node(Point(0, 2), NULL);
        this->node4 = new Node(Point(0, 1), NULL);
        this->node5 = new Node(Point(0, 0), NULL);
        this->node6 = new Node(Point(0, 0), NULL);
        this->node7 = new Node(Point(0, 0), NULL);
        this->node8 = new Node(Point(0, 0), NULL);
    }

    /*************************************************************************
	* The function delete/destroy the matrix at the and of every test.
	**************************************************************************/
    virtual void TearDown() {
        delete matrix;
        delete bfs;
        delete node1;
        delete node2;
        delete node3;
        delete node4;
        delete node5;
        delete node6;
        delete node7;
        delete node8;

    }

public:
    /*************************************************************************
	* Constructor - initialize bfs and matrix to null.
	**************************************************************************/
    BfsTest() {
        this->bfs = NULL;
        this->matrix = NULL;
        this->node1 = NULL;
        this->node2 = NULL;
        this->node3 = NULL;
        this->node4 = NULL;
        this->node5 = NULL;
        this->node6 = NULL;
        this->node7 = NULL;
        this->node8 = NULL;
    }

    /*************************************************************************
    * Destructor.
    **************************************************************************/
    ~BfsTest() {

    }
};

/*************************************************************************
* The function checks the bfs algorithem by one trail.
**************************************************************************/
TEST_F(BfsTest, checkBfsAlgorithem1) {
    stack<AbstractNode *> trail1;
    // Push one trail from 0,0 to 2,2 points.
    trail1.push(this->node1);
    trail1.push(this->node2);
    trail1.push(this->node3);
    trail1.push(this->node4);
    trail1.push(this->node5);
    // Call the Bfs Algorithms.
    trailBfs = bfs->BfsAlgorithm(matrix->getSourceElement(0, 0),
                                 matrix->getDestinationElement(2, 2));
    // Compare the trails.
    while (!trail1.empty()) {
        ASSERT_TRUE(*(trail1.top()) == *(trailBfs.top()));
        trail1.pop();
        trailBfs.pop();
    }
}
/*************************************************************************
* The function checks the bfs algorithem by another trail.
**************************************************************************/
TEST_F(BfsTest, checkBfsAlgorithem2) {
    stack<AbstractNode *> trail2;
    // Push one trail from 3,0 to 1,2 points.
    this->node1->setPoint(Point(1, 2));
    this->node2->setPoint(Point(1, 1));
    this->node3->setPoint(Point(1, 0));
    this->node4->setPoint(Point(2, 0));
    this->node5->setPoint(Point(3, 0));
    trail2.push(this->node1);
    trail2.push(this->node2);
    trail2.push(this->node3);
    trail2.push(this->node4);
    trail2.push(this->node5);
    // Call the Bfs algorithm.
    trailBfs = bfs->BfsAlgorithm(matrix->getSourceElement(3, 0),
                                 matrix->getDestinationElement(1, 2));
    // Compare the trails.
    while (!trail2.empty()) {
        ASSERT_TRUE(*(trail2.top()) == *(trailBfs.top()));
        trail2.pop();
        trailBfs.pop();
    }
}

/*************************************************************************
* The function checks the bfs algorithem by another trail.
**************************************************************************/
TEST_F(BfsTest, checkBfsAlgorithemObstacle1) {

    stack<AbstractNode *> trail3;
    this->node1->setPoint(Point(2, 2));
    this->node2->setPoint(Point(1, 2));
    this->node3->setPoint(Point(1, 1));
    this->node4->setPoint(Point(1, 0));
    this->node5->setPoint(Point(0, 0));
    // Push one trail from 0,0 to 2,2 points.
    trail3.push(this->node1);
    trail3.push(this->node2);
    trail3.push(this->node3);
    trail3.push(this->node4);
    trail3.push(this->node5);

    // Call the Bfs algorithm and set the obstacle.
    matrix->getSourceElement(0, 1)->setObstacle(true);
    trailBfs = bfs->BfsAlgorithm(matrix->getSourceElement(0, 0),
                                 matrix->getDestinationElement(2, 2));
    // Compare the trails.
    while (!trail3.empty()) {
        ASSERT_TRUE(*(trail3.top()) == *(trailBfs.top()));
        trail3.pop();
        trailBfs.pop();
    }
}

/*************************************************************************
* The function checks the bfs algorithem by another trail.
**************************************************************************/
TEST_F(BfsTest, checkBfsAlgorithemObstacle2) {

    stack<AbstractNode *> trail4;
    this->node1->setPoint(Point(5, 4));
    this->node2->setPoint(Point(5, 3));
    this->node3->setPoint(Point(4, 3));
    this->node4->setPoint(Point(3, 3));
    this->node5->setPoint(Point(3, 2));
    this->node6->setPoint(Point(2, 2));
    this->node7->setPoint(Point(2, 1));
    this->node8->setPoint(Point(1, 1));

    // Push one trail from 0,0 to 2,2 points.
    trail4.push(this->node1);
    trail4.push(this->node2);
    trail4.push(this->node3);
    trail4.push(this->node4);
    trail4.push(this->node5);
    trail4.push(this->node6);
    trail4.push(this->node7);
    trail4.push(this->node8);

    // Call the Bfs algorithm and set the obstacle.
    matrix->getSourceElement(1, 2)->setObstacle(true);
    matrix->getSourceElement(2, 3)->setObstacle(true);
    matrix->getSourceElement(4, 4)->setObstacle(true);
    trailBfs = bfs->BfsAlgorithm(matrix->getSourceElement(1, 1),
                                 matrix->getDestinationElement(5, 4));
    // Compare the trails.
    while (!trail4.empty()) {
        ASSERT_TRUE(*(trail4.top()) == *(trailBfs.top()));
        trail4.pop();
        trailBfs.pop();
    }
}