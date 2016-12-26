
#ifndef EX2_SEARCHABLE_H
#define EX2_SEARCHABLE_H


#include <stack>
#include "AbstractNode.h"

/* The class: Searchable.
 * The class is an abstract class to different kind of search. */
class Searchable {

public:
    virtual ~Searchable() = 0;

/* Function: The bfs algorithm.
     * Function members: source node and destination node.
     * Return : stack of the trail from source and destination. */
    virtual std::stack<AbstractNode *>
    BfsAlgorithm(AbstractNode *source, AbstractNode *destination)=0;
};


#endif //EX2_SEARCHABLE_H
