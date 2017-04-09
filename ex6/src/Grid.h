
#ifndef TASK2BFS_SHAPEGRAPH_H
#define TASK2BFS_SHAPEGRAPH_H

#include "Node.h"
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/export.hpp>

/* A Grid class is an interface that holds a graph,
 * a source point and destination point.
   The grid it's a general shape.
   It can hold many shape such as nodes, graph and etc.*/
class Grid {
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
    }

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

    // Setting the distance of the niighbors in the "child" class.
    virtual void setDistanceNeighbors()=0;
};

BOOST_SERIALIZATION_ASSUME_ABSTRACT(Grid)


#endif //TASK2BFS_SHAPEGRAPH_H
