// File Name: MinPriority.h
// Author: Randy Ledbetter
// Class: CSCI 311
// Instructor: Dr. Judith Challinger
// Date: 05/11/2013

/*
===============================================================================
Description: This is the header file MinPriority.h. It represents the interface
             file for a minimum priority queue.
===============================================================================
*/
#include <cmath>
#ifndef H_MIN_PRIORITY
#define H_MIN_PRIORITY

using namespace std;




class MinPriorityNode
{
public:
    MinPriorityNode(int value, int key);
    ~MinPriorityNode();

    int m_value;
    int m_key;
};

class MinPriority
{
public:

    int heapSize; // Number of nodes present currently
    int heapLength; // Capacity of min heap

    MinPriority(int length);
    ~MinPriority();

    int Parent(int i) { return (static_cast <int> (floor( i / 2 + 1))); }
    int Left(int i) { return 2 * i + 1; }
    int Right(int i) { return 2 * i + 2; }

     bool isEmpty(MinPriority* minHeap);

    void heapDecreaseKey(MinPriority* A, int i, int key);

    bool isInMinPriority(MinPriority* A, int value);

    MinPriorityNode* heapExtractMin(MinPriority* A);   

    void minHeapify(MinPriority* A, int i);

    
    void swapMinPriorityNode(MinPriorityNode** a, MinPriorityNode**b);


     MinPriorityNode **m_array;
     int *m_position; // Used in function heapDecreaseKey

};

#endif
