// File Name: Graph.h
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
#include <cstdlib>
#include <string>
#include <limits.h>
#include <math.h>
#include <vector>
#include <cassert>
#include <sstream>
#include "MinPriority.h"

using namespace std;




#ifndef H_GRAPH
#define H_GRAPH

class AdjListNode
{
public:
    AdjListNode(string id, int dest, int weight);

    AdjListNode(string id, int src, int dest, string d_id, int weight);

    ~AdjListNode();

    string m_id;
    string m_d_id;
    int m_src;
    int m_dest;
    int m_weight;
    string m_parent;
    AdjListNode* m_next;
};

class AdjList
{
public:
    AdjList();
    ~AdjList();        

    AdjListNode* m_head;
};



class Graph
{
    public:   
    int m_size;

    Graph();
    ~Graph();

   void MSTPrim();


        

    AdjList* m_array;    
};

#endif
