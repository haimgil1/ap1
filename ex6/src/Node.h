#ifndef TASK2BFS_NODE_H
#define TASK2BFS_NODE_H

#include <vector>
#include "Point.h"
#include "AbstractNode.h"

using namespace std;

// Class: Node extends the AbstractNode and holds a point.
class Node : public AbstractNode {
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & boost::serialization::base_object<AbstractNode>(*this);
        ar & point;
    }

private:
    // Members.
    Point point;
    bool obstacle;

public:
    // A constructor.
    Node();

    // A constructor that gets a point and pointer to the previous node.
    Node(Point newPoint, AbstractNode *prevNode);

    // A destructor.
    ~Node();

    // Overriding the == operator.
    virtual bool operator==(const AbstractNode &otherNode) const;


    bool operator!=(const AbstractNode &otherNode) const;

    // Overriding the << operator.
    friend ostream &operator<<(ostream &os, const AbstractNode &node);

    // Printing the node.
    ostream &print(ostream &os) const;

    // Setting obstacle.
    void setObstacle(bool isObstacle);

    //Getting obstacle.
    bool getObstacle();

    // Setting the point.
    void setPoint(const Point &point);

    Point *getPointNode();

    // Getting the point.
    const Point &getPoint() const;

    // Overriding the == operator by node.
    bool operator==(const Node &node) const;

    // Overriding the != operator by node..
    bool operator!=(const Node &node) const;

    // Overriding the == operator by point..
    bool operator==(const Point p) const;

    // Overriding the != operator by point..
    bool operator!=(const Point p) const;

};


#endif //TASK2BFS_NODE_H
