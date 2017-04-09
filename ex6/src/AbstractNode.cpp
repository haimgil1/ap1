
#include "AbstractNode.h"
#include "Node.h"

AbstractNode::~AbstractNode() {

}

void AbstractNode::setPrevNode(AbstractNode *newNode) {
    prev = newNode;
}

void AbstractNode::setDistance(int newDis) {
    distance = newDis;
}

int AbstractNode::getDistance() {
    return distance;
}

int AbstractNode::getNumOfNeighbors() {
    return numOfNeighbors;
}

void AbstractNode::addNeighbor(AbstractNode *node) {
    // Adding the node to the vector.
    vectorNeighbors.push_back(node);
    numOfNeighbors++; // Updating the number of neighbors.
}

vector<AbstractNode *> AbstractNode::getNeighbors() {
    return vectorNeighbors;
}

AbstractNode *AbstractNode::getPrev() {
    return prev;
}

ostream &operator<<(ostream &os, const AbstractNode &node) {
    return node.print(os);
}

/*bool AbstractNode::operator==(const AbstractNode &node) const {
    return prev == node.prev &&
           distance == node.distance &&
           numOfNeighbors == node.numOfNeighbors &&
           vectorNeighbors == node.vectorNeighbors;
}*/

bool AbstractNode::operator!=(const AbstractNode &node) const {
    return !(node == *this);
}

AbstractNode::AbstractNode() {}


const Point &Node::getPoint() const {
    return point;
}


bool Node::operator==(const Node &node) const {
    return static_cast<const AbstractNode &>(*this) == static_cast<const AbstractNode &>(node) &&
           point == node.point &&
           obstacle == node.obstacle;
}

bool Node::operator!=(const Node &node) const {
    return !(node == *this);
}

bool Node::operator==(const Point p) const {
    return this->point == p;
}

bool Node::operator!=(const Point p) const {
    return this->point != p;
}
