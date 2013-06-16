// File Name: MSTapp.cpp
// Author: Randy Ledbetter
// Class: CSCI 311
// Instructor: Dr. Judith Challinger
// Date: 05/17/2013

/*
===============================================================================
Description: This is the application file MSTapp.cpp. It drives the Graph
             class member function MSTPrim. The function MSTPrim builds a
             Prim Minimum Spanning Tree drawn from chapter 23 of 
             "Introduction to Algorithms" by Thomas Cormen. It then displays
             the resultant MST tree and the tree's total weight in 
             accordance with the formatting specified by Dr. Judith
             Challinger in the posted CSCI 311 Project 4 specifications.
===============================================================================
*/
#include "MSTapp.h"
#include "Graph.h"
#include "MinPriority.h"


int main()
{
    Graph graph; 
    graph.MSTPrim();
  
    return 0;
}
