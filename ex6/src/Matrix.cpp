

#include "Matrix.h"

using namespace std;

Matrix::Matrix(int newN, int newM) {
    this->n = newN;
    this->m = newM;
    this->buildGraph();
    this->buildNeighbors();
    this->validate();
}

Matrix::Matrix() {

}

Matrix::~Matrix() {

}

void Matrix::validate() {
    // Check the limits of the matrix.
    if ((this->n < 0) || (this->m < 0) || (this->n > 1000) || (this->m > 1000)) {
        throw invalid_argument("wrong range");
    }
}

void Matrix::buildGraph() {
    // Build the graph.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Adding a point and node.
            Point p(i, j);
            Node n(p, NULL);
            arrNode[i][j] = n;
        }
    }
}

void Matrix::buildNeighbors() {
    // Add neighbors to all nodes.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) { // Left node.
                arrNode[i][j].addNeighbor(&arrNode[i - 1][j]);
            }
            if (j < m - 1) { // Up node.
                arrNode[i][j].addNeighbor(&arrNode[i][j + 1]);
            }
            if (i < n - 1) { // Right node.
                arrNode[i][j].addNeighbor(&arrNode[i + 1][j]);
            }
            if (j > 0) { // Down node.
                arrNode[i][j].addNeighbor(&arrNode[i][j - 1]);
            }
        }
    }
}

Node *Matrix::getSourceElement(int x, int y) {
    return &arrNode[x][y];
}

Node *Matrix::getDestinationElement(int x, int y) {
    return &arrNode[x][y];
}

Node *Matrix::getSourceElement(Point p) {
    return &arrNode[p.getX()][p.getY()];
}

Node *Matrix::getDestinationElement(Point p) {
    return &arrNode[p.getX()][p.getY()];
}

void Matrix::setDistanceNeighbors() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arrNode[i][j].setDistance(-1);
        }
    }
}

BOOST_CLASS_EXPORT(Matrix)

