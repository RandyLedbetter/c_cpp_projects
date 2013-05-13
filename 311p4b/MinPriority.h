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

#ifndef H_MIN_PRIORITY
#define H_MIN_PRIORITY

class MinPriority
{
public:

    MinPriority(int heap_length);
    ~MinPriority();

    void minHeapify(MinPriority* A, int index);
    bool isEmpty(MinPriority* A);
    MinPriorityNode* extractMin(MinPriority* A);
    void decreaseKey(MinPriority* A, int i, int key);
    bool isInMinHeap(MinPriority* A, int i);
    void printArr(int arr[], int n);



private:
    int m_heapLength; // Capacity of min heap
    int m_heapSize; // Number of heap nodes present currently
    int *m_pos; // To be used with descreaseKey()
    int parent(i);
    int left(i);
    int right(i);
    MinPriorityNode **m_array;

        class MinPriorityNode
        {
            MinPriorityNode();
            ~MinPriorityNode();

            int m_v;
            int m_key;
        };

void swapMinPriorityNode(MinPriorityNode** a, MinPriorityNode** b);

};

#endif