
#ifndef TASK2BFS_MATRIX_H
#define TASK2BFS_MATRIX_H

#include "Node.h"
#include "Grid.h"
#include <stdexcept>

// A Matrix class that holds a matrix of nodes and the width and the height.
class Matrix : public Grid {
private:
    // Members.
    int n, m;
    Node arrNode[10][10];

    void validate();

public:

    // Default constructor.
    Matrix();

    // A constructor that gets a width and height.
    Matrix(int newN, int newM);

    // A destructor.
    ~Matrix();

    // Building the graph.
    void buildGraph();

    // Building the neighbors.The left neighbor is the first and the down neighbor is last.
    void buildNeighbors();

    // Set the distance to -1.
    void setDistanceNeighbors();

    // Getting the source by x and y coordinate.
    Node *getSourceElement(int x, int y);

    // Getting the destination by x and y coordinate..
    Node *getDestinationElement(int x, int y);

    // Getting the source by a point.
    Node *getSourceElement(Point p);

    // Getting the destination by a point.
    Node *getDestinationElement(Point p);


};


#endif //TASK2BFS_MATRIX_H
