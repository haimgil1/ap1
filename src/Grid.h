
#ifndef TASK2BFS_SHAPEGRAPH_H
#define TASK2BFS_SHAPEGRAPH_H

#include "Node.h"

/* A Grid class is an interface that holds a graph,
 * a source point and destination point.
   The grid it's a general shape.
   It can hold many shape such as nodes, graph and etc.*/
class Grid {
public:
    virtual ~Grid() = 0;

    // Building the graph.
    virtual void buildGraph()=0;

    // Getting the source by x and y coordinate.
    virtual Node *getSourceElement(int x, int y)=0;

    // Getting the destination by x and y coordinate..
    virtual Node *getDestinationElement(int x, int y)=0;

    // Getting the source by a point.
    virtual Node *getSourceElement(Point p)=0;

    // Getting the destination by a point.
    virtual Node *getDestinationElement(Point p)=0;

    virtual void setDistanceNeighbors()=0;
};


#endif //TASK2BFS_SHAPEGRAPH_H
