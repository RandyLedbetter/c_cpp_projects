// File Name: MinPriority.cpp
// Author: Randy Ledbetter
// Class: CSCI 311
// Instructor: Dr. Judith Challinger
// Date: 05/17/2013

/*
===============================================================================
Description: This is the implementation file MinPriority.cpp. It contains
             the definitions for functions required to implement a min-priority
             queue.
===============================================================================
*/
#include <iostream>
#include <cmath>
#include "MinPriority.h"

// MinPriorityNode Class Constructor
MinPriorityNode::MinPriorityNode(int value, int key)
{
    m_value = value;
    m_key = key;
}

// MinPriorityNode Class Destructor
MinPriorityNode::~MinPriorityNode() 
{
    // Not strictly required.
}

// MinPriority Class Constructor
MinPriority::MinPriority(int length)
{
    heapSize = 0;
    heapLength = length;
    m_array = new MinPriorityNode*[length];
    m_position = new int[length];
}

// MinPriority Class Destructor
MinPriority::~MinPriority()
{
    delete[] m_array;
    delete[] m_position;
    m_array = 0;
    m_position = 0;
}

// Precondition:        A valid parameter of type int has been passed to the 
//                      function.
// Postcondition:       The floor of i/2 = 1 has been returned to the calling
//                      function.
int Parent(int i) { return (static_cast <int> (floor( i / 2 + 1))); }


// Precondition:        A valid parameter of type int has been passed to the 
//                      function.
// Postcondition:       The result of the mathematical operation (2 * i + 1)
//                      has been returned to the calling function.
int Left(int i) { return 2 * i + 1; }


// Precondition:        A valid parameter of type int has been passed to the 
//                      function.
// Postcondition:       The result of the mathematical operation (2 * i + 2)
//                      has been returned to the calling function.
int Right(int i) { return 2 * i + 2; }


// Precondition:        Two pointers to pointers of type MinPriorityNode
//                      have been passed to the function.
// Postcondition:       The pointers passed into the function have been swapped.
void MinPriority::swapMinPriorityNode(MinPriorityNode** a, MinPriorityNode**b)
{
    MinPriorityNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Precondition:        A pointer of type MinPriority has been passed to the
//                      function.
// Postcondition:       If the min-priority queue that minHeap points to is
//                      empty, the function returns true; otherwise, the 
//                      function returns false.
bool MinPriority::isEmpty(MinPriority* minHeap)
{
    return minHeap->heapSize == 0;
}


// Precondition:        Valid parameters have been passed to the function.
// Postcondition:       The function HEAP-DECREASE-KEY, as outlined in
//                      chapter 6 of "Introduction to Algorithms", by
//                      Thomas Cormen has been executed.
void MinPriority::heapDecreaseKey(MinPriority* A, int i, int key)
{
    // Get the index of i in heap array
    int index = A->m_position[i];

    // Get the node and update its key value
    A->m_array[index]->m_key = key;

    // Travel up while the complete tree is not heapified
    while(index && A->m_array[index]->m_key < 
          A->m_array[(index - 1) / 2]->m_key)
    {
        // Swap this node with its parent
        A->m_position[A->m_array[index]->m_value] = (index - 1) / 2;
        A->m_position[A->m_array[(index - 1)/2]->m_value] = index;
        A->swapMinPriorityNode(&A->m_array[index], &A->m_array[(index - 1)/2]);

        // Move to parent index
        index = (index - 1) / 2;
    }
}


// Precondition:        Valid parameters have been passed to the function.
// Postcondition:       If value is within the min-priority queue that
//                      parameter A points to, the function returns true;
//                      otherwise, the function returns false.
bool MinPriority::isInMinPriority(MinPriority* A, int value)
{
    if(A->m_position[value] < A->heapSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// Precondition:        Valid parameters have been passed to the function.
// Postcondition:       The function MIN-HEAPIFY, as outlined in
//                      chapter 6 of "Introduction to Algorithms", by
//                      Thomas Cormen has been executed.
void MinPriority::minHeapify(MinPriority* A, int i)
{
    int smallest = i;
    int l = Left(i);
    int r = Right(i);

    if(l < A->heapSize && A->m_array[l]->m_key < A->m_array[smallest]->m_key) 
    {
        smallest = l;
    }
    if(r < A->heapSize && A->m_array[r]->m_key < A->m_array[smallest]->m_key) 
    {
        smallest = r;
    }
    if(smallest != i)
    {
        // Get the nodes to be swapped
        MinPriorityNode *smallestNode = A->m_array[smallest];
        MinPriorityNode * currentNode = A->m_array[i];

        // Swap node positions
        A->m_position[smallestNode->m_value] = i;
        A->m_position[currentNode->m_value] = smallest;

        // Swap nodes
        A->swapMinPriorityNode(&A->m_array[smallest], &A->m_array[i]);

        minHeapify(A, smallest);
    }
}


// Precondition:        Valid parameters have been passed to the function.
// Postcondition:       The function HEAP-EXTRACT-MIN, as outlined in
//                      chapter 6 of "Introduction to Algorithms", by
//                      Thomas Cormen has been executed.
MinPriorityNode* MinPriority::heapExtractMin(MinPriority* A)
{
    if(A->isEmpty(A))
    {
        return NULL;
    }

    MinPriorityNode* min =  A->m_array[0];

    // Replace root node with last node
    MinPriorityNode* endNode = A->m_array[A->heapSize - 1];
    A->m_array[0] = endNode;

    // Update position of the last node
    A->m_position[min->m_value] = A->heapSize - 1;
    A->m_position[endNode->m_value] = 0;

    // Reduce heap size and recursively call minHeapify
    A->heapSize--;
    minHeapify(A, 0);

    return min;
}   

