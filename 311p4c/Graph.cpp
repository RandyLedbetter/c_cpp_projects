// File Name: Graph.cpp
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


#include "Graph.h"
#include "MinPriority.h"


using namespace std;


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

AdjListNode::~AdjListNode()
{
    
}

AdjList::AdjList()
{
    m_head = NULL;
}
AdjList::~AdjList()
{
    
}

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
                //newNode->m_next->m_parent = newNode;
                m_array[i].m_head = newNode;
            }
            else
            {
                while(ptr->m_next && ptr->m_next->m_d_id <= dest)
                {
                    ptr = ptr->m_next;
                }

                //newNode->m_parent = ptr;
                newNode->m_next = ptr->m_next;
                
                if(ptr->m_next)
                {
                    //ptr->m_next->m_parent = newNode;
                }

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
                //newNode2->m_next->m_parent = newNode2;

                
                m_array[j].m_head = newNode2;
            }
            else
            {
                while(ptr2->m_next && ptr2->m_next->m_d_id <= dest)
                {
                    ptr2 = ptr2->m_next;
                }

                //newNode2->m_parent = ptr2;
                
                newNode2->m_next = ptr2->m_next;
                
                if(ptr2->m_next)
                {
                    //ptr2->m_next->m_parent = newNode2;
                    
                }

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


Graph::~Graph()
{
    

}

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
            if (minHeap->isInMinPriority(minHeap, v) && pCrawl->m_weight < key[v])
            {
                key[v] = pCrawl->m_weight;
                this->m_array[v].m_head->m_parent = this->m_array[u].m_head->m_id;
                parent[v] = u;
                minHeap->heapDecreaseKey(minHeap, v, key[v]);
            }
            pCrawl = pCrawl->m_next;


        }

        cout << this->m_array[u].m_head->m_id << " " 
             << this->m_array[u].m_head->m_parent << " " 
             << minHeapNode->m_key << endl;
             

        total_weight += minHeapNode->m_key;
 
    }

    cout << total_weight << endl;

}






