// File Name: Graph.cpp
// Author: Randy Ledbetter
// Class: CSCI 311
// Instructor: Dr. Judith Challinger
// Date: 05/17/2013

/*
===============================================================================
Description:  This is the implementation file Graph.cpp. Functions defined
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
#include <cstdio>
#include <climits>


#include "Graph.h"
#include "MinPriority.h" // Used for minPriority Queue


using namespace std;

// AdjListNode Class constructor
AdjListNode::AdjListNode(string id, int src, int dest, string d_id, int weight)
{
    m_id = id;
    m_d_id = d_id;
    m_src = src;
    m_dest = dest;
    m_weight = weight;
    m_parent = "NIL";
    m_next = NULL;
}

// AdjListNode Class Destructor
AdjListNode::~AdjListNode()
{
    delete m_next;
    m_next = 0;
}

// AdjList Class Constructor
AdjList::AdjList()
{
    m_head = NULL;
}

// AdjList Class Destructor
AdjList::~AdjList()
{
    delete m_head;
}

// Graph Class constructor

// This constructor builds a vector of adjacency lists. Input is received
// via standard input in the for of vertex identifiers on the first line
// and source destination and weight data on each subsequent line of input.
// The resulting graph is a vector of alphabetically-sorted adjacency lists.
Graph::Graph()
{
    vector<string> vertices;
    string id, dest, line;
    int weight, i, j;
    m_size = 0;


    getline(cin, line);
    istringstream iss(line);

    while(iss)
    {
        string v;
        while(iss >> v)
        {
            vertices.push_back(v);
            m_size++;
        }
    } 
       
    m_array = new AdjList[m_size];
    
    AdjListNode* ptr = NULL;

    if(cin >> id)
    {
        cin >> dest;
        cin >> weight;
        if(cin.peek() == '\n')
        {
            getchar(); // Get end of line character
        }
    }

    for(i = 0; i < m_size; i++)
    {
        ptr = m_array[i].m_head;
        
        while(id == vertices[i])
        {
            for(j = 0; vertices[j] != dest; j++);

            AdjListNode* ptr2 = m_array[j].m_head;

            AdjListNode* newNode = new AdjListNode(id, i, j, dest, weight);
            AdjListNode* newNode2 = new AdjListNode(dest, j, i, id, weight);
            
            // Insert edge from src to dest
            if(ptr == NULL)
            {
                m_array[i].m_head = newNode;
            }
            else if(ptr->m_d_id > dest)
            {
                newNode->m_next = m_array[i].m_head;
                m_array[i].m_head = newNode;
            }
            else
            {
                while(ptr->m_next && ptr->m_next->m_d_id <= dest)
                {
                    ptr = ptr->m_next;
                }

                newNode->m_next = ptr->m_next;
                
                ptr->m_next = newNode;
            }              

            // Insert edge from dest to src
            if(ptr2 == NULL)
            {
                m_array[j].m_head = newNode2;
            }
            else if(ptr2->m_d_id > dest)
            {
                newNode2->m_next = m_array[j].m_head;         
                m_array[j].m_head = newNode2;
            }
            else
            {
                while(ptr2->m_next && ptr2->m_next->m_d_id <= dest)
                {
                    ptr2 = ptr2->m_next;
                }

                newNode2->m_next = ptr2->m_next;
                ptr2->m_next = newNode2;

            }

            ptr = m_array[i].m_head;
            ptr2 = m_array[j].m_head;

            if(cin >> id)
            {
                cin >> dest;
                cin >> weight;

                if(cin.peek() == '\n')
                {
                    getchar(); // Get end of line character
                }
            }
            else
            {
                break;
            }           
        }
    }    
}

// Graph Class destructor
Graph::~Graph()
{
    delete[] m_array;
}

//Precondition:     An Graph object has been instantiated and properly
//                  constructed.
//Postcondition:    A Prim Minimum Spanning Tree algorithm, drawn from
//                  chapter 23 of "Introduction to Algorithms" by Thomas
//                  Cormen has constructed a Prim Minimum Spanning Tree
//                  and output to standard out the result, formatted in
//                  accordance with the specifications set forth by Dr.
//                  Judith Challinger in the CSCI 311 Project 4 specifications.
void Graph::MSTPrim()
{
    int V = this->m_size;// Get the number of vertices in graph
    int* parent = new int[V];   // Array to store constructed MST
    int* key = new int[V];      // Key values used to pick minimum weight edge 
    int total_weight = 0; // Used to sum individual weights.

    // minHeap represents set E
    MinPriority* minHeap = new MinPriority(V);

    // Initialize min heap with all vertices. Key value of
    // all vertices (except 0th vertex) is initially infinite
    for (int v = 1; v < V; ++v)
    {
        parent[v] = -1;
        key[v] = INT_MAX;
        minHeap->m_array[v] = new MinPriorityNode(v, key[v]);
        minHeap->m_position[v] = v;
    }

    // Make key value of 0th vertex as 0 so that it
    // is extracted first
    key[0] = 0;
    minHeap->m_array[0] = new MinPriorityNode(0, key[0]);
    minHeap->m_position[0] = 0;

    // Initially size of min heap is equal to V
    minHeap->heapSize = V;

    // In the followin loop, min heap contains all nodes
    // not yet added to MST.
    while (!minHeap->isEmpty(minHeap))
    {
        // Extract the vertex with minimum key value
        MinPriorityNode* minHeapNode = minHeap->heapExtractMin(minHeap);
        int u = minHeapNode->m_value; // Store the extracted vertex number
       

        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their key values
        AdjListNode* pCrawl = this->m_array[u].m_head;

    

        while (pCrawl != NULL)
        {
            
            int v = pCrawl->m_dest;

            // If v is not yet included in MST and weight of u-v is
            // less than key value of v, then update key value and
            // parent of v
            if (minHeap->isInMinPriority(minHeap, v) && 
                pCrawl->m_weight < key[v])
            {
                key[v] = pCrawl->m_weight;
                this->m_array[v].m_head->m_parent=this->m_array[u].m_head->m_id;
                parent[v] = u;
                minHeap->heapDecreaseKey(minHeap, v, key[v]);
            }

            pCrawl = pCrawl->m_next;

        }

        // As the vertex is removed from the min-priority queue,
        // display its id, its predecessor id, and its weight
        cout << this->m_array[u].m_head->m_id << " " 
             << this->m_array[u].m_head->m_parent << " " 
             << minHeapNode->m_key << endl;
             
        // Maintain a tally of weights
        total_weight += minHeapNode->m_key;

    }

    // Display the total weight of the Minimum Spanning Tree
    cout << total_weight << endl;

    // Free dynamically allocated memory
    delete[] parent;
    parent = 0;
    delete[] key;
    key = 0;
    delete minHeap;
}
