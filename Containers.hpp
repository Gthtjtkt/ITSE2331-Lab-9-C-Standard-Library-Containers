#ifndef CONTAINERS_HPP
#define CONTAINERS_HPP

// Function prototypes for container operations
void sequenceContainerOptions();
void orderedAssociativeContainerOptions();
void unorderedAssociativeContainerOptions();
void containerAdapterOptions();

// Sequence container functions
void arrayOperations();
void dequeOperations();
void forwardListOperations();
void listOperations();
void vectorOperations();

// Ordered associative container functions
void setOperations();
void multisetOperations();
void mapOperations();
void multimapOperations();

// Unordered associative container functions
void unorderedSetOperations();
void unorderedMultisetOperations();
void unorderedMapOperations();
void unorderedMultimapOperations();

// Container adapter functions
void stackOperations();
void queueOperations();
void priorityQueueOperations();

#include "Containers.cpp"

#endif // CONTAINERS_HPP
