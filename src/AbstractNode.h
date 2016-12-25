
#ifndef TASK2BFS_ABSTRACTNODE_H
#define TASK2BFS_ABSTRACTNODE_H

#include <vector>
#include "Point.h"
#include <ostream>

using namespace std;

/*Class: AbstractNode.
 * is the abstract class of node with common functions of
 * different type of nodes.*/
class AbstractNode {
protected:
    // Members.
    AbstractNode *prev;
    int distance;
    int numOfNeighbors;
    vector<AbstractNode *> vectorNeighbors;
public:
    // The function Printing the node.
    virtual ostream &print(ostream &os) const =0;

    // Setting the node.
    virtual void setPrevNode(AbstractNode *newNode);

    // Setting the distance.
    virtual void setDistance(int newDis);

    // Getting the distance.
    virtual int getDistance();

    // Getting the previous node.
    virtual AbstractNode *getPrev();

    // Getting the neighbors.
    virtual vector<AbstractNode *> getNeighbors();

    // Adding a neighbor.
    virtual void addNeighbor(AbstractNode *node);

    // Getting the number of neighbors.
    virtual int getNumOfNeighbors();

    // Overriding the << operator.
    friend ostream &operator<<(ostream &os, const AbstractNode &node);

    // virtual function to set obstacle.
    virtual void setObstacle(bool isObstacle) =0;

    // virtual function to get obstacle.
    virtual bool getObstacle()  =0;

    virtual ~AbstractNode() = 0;

    // Overriding the == operator.
    virtual bool operator==(const AbstractNode &otherNode) const =0;

    virtual bool operator!=(const AbstractNode &node) const;

    virtual bool operator==(const Point p) const =0;

    virtual bool operator!=(const Point p) const =0;

};

#endif //TASK2BFS_ABSTRACTNODE_H
