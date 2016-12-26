
#include "Node.h"

using namespace std;

Node::Node() {

}

Node::~Node() {

}

// constructor
Node::Node(Point newPoint, AbstractNode *prevNode) {
    this->point = newPoint;
    this->prev = prevNode;
    this->distance = -1; // A flag that say it's not visited yet.
    this->numOfNeighbors = 0;
    this->obstacle = false;
}

bool Node::operator==(const AbstractNode &otherNode) const {
    // Override the operator "==" by checking the x and y values.
    return ((point.getX() == ((Node &) otherNode).point.getX()) &&
            (point.getY() == ((Node &) otherNode).point.getY()));
}

bool Node::operator!=(const AbstractNode &otherNode) const {
    return !(otherNode == *this);
}

ostream &Node::print(ostream &os) const {
    return os << point;
}


void Node::setObstacle(bool isObstacle) {
    this->obstacle = isObstacle;
}

bool Node::getObstacle() {
    return this->obstacle;
}

void Node::setPoint(const Point &point) {
    this->point = point;
}

