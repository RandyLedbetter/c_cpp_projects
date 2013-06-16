// File Name: Graph.h
// Author: Randy Ledbetter
// Class: CSCI 311
// Instructor: Dr. Judith Challinger
// Date: 05/17/2013

/*
===============================================================================
Description:  This is the header file Graph.h. Functions declared
              within this file implement A Prim Minimum Spanning Tree algorithm,
              drawn from chapter 23 of "Introduction to Algorithms" by Thomas
              Cormen. Functions related to the implementation of a list of 
              Adjacency Lists to implement the graph are contained herein
              well.
===============================================================================
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "MinPriority.h"



using namespace std;


#ifndef H_GRAPH
#define H_GRAPH


class AdjListNode
{
public:

    // Constructor
    AdjListNode(string id, int src, int dest, string d_id, int weight);

    // Destructor
    ~AdjListNode();

    // Declare member variables
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

    // Constructor
    AdjList();

    // Destructor
    ~AdjList();        

    // Declare member variables
    AdjListNode* m_head;
};



class Graph
{
    public:   
    
    // Constructor
    Graph();

    // Destructor
    ~Graph();


    //Precondition:     An Graph object has been instantiated and properly
    //                  constructed.
    //Postcondition:    A Prim Minimum Spanning Tree algorithm, drawn from
    //                  chapter 23 of "Introduction to Algorithms" by Thomas
    //                  Cormen has constructed a Prim Minimum Spanning Tree
    //                  and output to standard out the result, formatted in
    //                  accordance with the specifications set forth by Dr.
    //                  Judith Challinger in the CSCI 311 Project 4.
    void MSTPrim();


    // Declare member variables    
    int m_size;
    AdjList* m_array;    
};

#endif
