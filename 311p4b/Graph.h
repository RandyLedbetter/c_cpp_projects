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

#ifndef H_GRAPH
#define H_GRAPH

class Graph
{
public:
    Graph(int V);
    ~Graph();

    int V;
    AdjList* array;

private:

    class AdjList
    {
    public:
        AdjList();
        ~AdjList();

    private:

        class AdjListNode
        {
        public:
                AdjListNode(string id, int weight) 
                {m_id = id; m_weight = weight; m_next = NULL;}
                ~AdjListNode()
                {delete m_next;}

                string m_id;
                string m_predecessor_id;
                int m_weight;
                AdjListNode* m_next;
            };

    AdjListNode* m_head; // pointer to head node of list

    };



};

#endif