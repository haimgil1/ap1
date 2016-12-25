#ifndef TASK2BFS_NODE_H
#define TASK2BFS_NODE_H

#include <vector>
#include "Point.h"
#include "AbstractNode.h"

using namespace std;

// Class: Node extends the AbstractNode and holds a point.
class Node : public AbstractNode {
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
    bool operator==(const AbstractNode &otherNode) const;


    bool operator!=(const AbstractNode &otherNode) const;

    // Overriding the << operator.
    friend ostream &operator<<(ostream &os, const AbstractNode &node);

    // Printing the node.
    ostream &print(ostream &os) const;

    void setObstacle(bool isObstacle);

    bool getObstacle();

    void setPoint(const Point &point);

    const Point &getPoint() const;

    bool operator==(const Node &node) const;

    bool operator!=(const Node &node) const;

    bool operator==(const Point p) const;

    bool operator!=(const Point p) const;

};


#endif //TASK2BFS_NODE_H
