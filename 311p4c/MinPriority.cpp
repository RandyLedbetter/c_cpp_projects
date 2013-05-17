// File Name: MinPriority.cppcd
// Author: Randy Ledbetter
// Class: CSCI 311
// Instructor: Dr. Judith Challinger
// Date: 05/11/2013

/*
===============================================================================
Description: This is the header file Graph.h. It represents the interface
             file for a minimum priority queue.
===============================================================================
*/
#include <iostream>
#include <cmath>
#include "MinPriority.h"


MinPriorityNode::MinPriorityNode(int value, int key)
{
    m_value = value;
    m_key = key;
}
MinPriorityNode::~MinPriorityNode() {}

MinPriority::MinPriority(int length)
{
    heapSize = 0;
    heapLength = length;
    m_array = new MinPriorityNode*[length];
    m_position = new int[length];
}
MinPriority::~MinPriority()
{
    
}

int Parent(int i) { return (static_cast <int> (floor( i / 2 + 1))); }
int Left(int i) { return 2 * i + 1; }
int Right(int i) { return 2 * i + 2; }

void MinPriority::swapMinPriorityNode(MinPriorityNode** a, MinPriorityNode**b)
{
    MinPriorityNode* temp = *a;
    *a = *b;
    *b = temp;
}

bool MinPriority::isEmpty(MinPriority* minHeap)
{
    return minHeap->heapSize == 0;
}

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

