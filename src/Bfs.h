
#ifndef TASK2BFS_Bfs_H
#define TASK2BFS_Bfs_H

#include <stack>
#include "Grid.h"
#include "Matrix.h"
#include "AbstractNode.h"
#include "Searchable.h"

/* A bfs class that contain the bfs algorithm.
  BFS is an algorithm for traversing or searching tree or graph data structures.
  It starts at the tree root (or some arbitrary node of a graph,
  sometimes referred to as a 'search key'[1]) and explores the neighbor nodes first,
  before moving to the next level neighbors.*/
class Bfs : public Searchable {
public:

    Bfs();

/* Function: The bfs algorithm.
     * Function members: source node and destination node.
     * Return : stack of the trail from source and destination. */
    std::stack<AbstractNode *> BfsAlgorithm(AbstractNode *source, AbstractNode *destination);

    ~Bfs();

};

#endif //TASK2BFS_Bfs_H
