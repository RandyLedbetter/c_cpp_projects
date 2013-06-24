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
#include <cmath> // Needed for floor()
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

    // Constructor
    MinPriority(int length);

    // Destructor
    ~MinPriority();


    // Precondition:     A valid parameter of type int has been passed to the 
    //                   function.
    // Postcondition:    The floor of i/2 = 1 has been returned to the calling
    //   
    int Parent(int i) { return (static_cast <int> (floor( i / 2 + 1))); }


    // Precondition:     A valid parameter of type int has been passed to the 
    //                   function.
    // Postcondition:    The result of the mathematical operation (2 * i + 1)
    //                   has been returned to the calling function.
    int Left(int i) { return 2 * i + 1; }


    // Precondition:     A valid parameter of type int has been passed to the 
    //                   function.
    // Postcondition:    The result of the mathematical operation (2 * i + 2)
    //                   has been returned to the calling function.    
    int Right(int i) { return 2 * i + 2; }


    // Precondition:     A pointer of type MinPriority has been passed to the
    //                   function.
    // Postcondition:    If the min-priority queue that minHeap points to is
    //                   empty, the function returns true; otherwise, the 
    //                   function returns false.
    bool isEmpty(MinPriority* minHeap);



    // Precondition:     Valid parameters have been passed to the function.
    // Postcondition:    The function HEAP-DECREASE-KEY, as outlined in
    //                   chapter 6 of "Introduction to Algorithms", by
    //                   Thomas Cormen has been executed.
    void heapDecreaseKey(MinPriority* A, int i, int key);


    // Precondition:     Valid parameters have been passed to the function.
    // Postcondition:    If value is within the min-priority queue that
    //                   parameter A points to, the function returns true;
    //                   otherwise, the function returns false.
    bool isInMinPriority(MinPriority* A, int value);


    // Precondition:     Valid parameters have been passed to the function.
    // Postcondition:    The function HEAP-EXTRACT-MIN, as outlined in
    //                   chapter 6 of "Introduction to Algorithms", by
    //                   Thomas Cormen has been executed.
    MinPriorityNode* heapExtractMin(MinPriority* A);



    // Precondition:     Valid parameters have been passed to the function.
    // Postcondition:    The function MIN-HEAPIFY, as outlined in
    //                   chapter 6 of "Introduction to Algorithms", by
    //                   Thomas Cormen has been executed.
    void minHeapify(MinPriority* A, int i);

    // Precondition:     Two pointers to pointers of type MinPriorityNode
    //                   have been passed to the function.
    // Postcondition:    The pointers passed into the function have been swapped    
    void swapMinPriorityNode(MinPriorityNode** a, MinPriorityNode**b);


    // Declare member variables
    MinPriorityNode **m_array;
    int *m_position; // Used in function heapDecreaseKey
    int heapSize; // Number of nodes present currently
    int heapLength; // Capacity of min heap

};

#endif
