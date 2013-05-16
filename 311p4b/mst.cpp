#include <iostream>
#include <cstdlib>
#include <string>
#include <limits.h>
#include <math.h>
#include <vector>
#include <cassert>
#include <sstream>

using namespace std;

class AdjListNode
        {
        public:
            AdjListNode(string id, int dest, int weight)
            {
                m_id = id;
                m_dest = dest;
                m_weight = weight;
                m_parent = "NIL";
                m_next = NULL;
            }

            AdjListNode(string id, int src, int dest, string d_id, int weight)
            {
                m_id = id;
                m_d_id = d_id;
                m_src = src;
                m_dest = dest;
                m_weight = weight;
                m_parent = "NIL";
                m_next = NULL;
            }

            ~AdjListNode()
            {
                //delete m_parent;
                delete m_next;
            }

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
            AdjList()
            {
                m_head = NULL;
            }
            ~AdjList()
            {
                delete m_head;
            }

        
                

            AdjListNode* m_head;
        };

class Graph
{
    public:

    
    int m_size;

    Graph()
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
            //cout << "vertices[" << m_size << "] = " << vertices[m_size] << endl;
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


               /* //Print properties of newNode as debugging tool
                cout << "id = " << newNode->m_id << endl;
                cout << "d_id = " << newNode->m_d_id << endl;
                cout << "src = " << newNode->m_src << endl;
                cout << "dest = " << newNode->m_dest << endl;
                cout << "parent = " << newNode->m_parent << endl;
                cout << "weight = " << newNode->m_weight << endl << endl << endl;

                //Print properties of newNode2 as debugging tool
                cout << "id = " << newNode2->m_id << endl;
                cout << "d_id = " << newNode2->m_d_id << endl;
                cout << "src = " << newNode2->m_src << endl;
                cout << "dest = " << newNode2->m_dest << endl;
                cout << "parent = " << newNode2->m_parent << endl;
                cout << "weight = " << newNode2->m_weight << endl << endl << endl;
                */

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

    Graph(int size)
    {
        m_size = size;
        m_array = new AdjList[size];


    }
    ~Graph()
    {
        delete m_array;
    }

        

AdjList* m_array;
    
};

void addEdge(Graph* graph, int src, int dest, int weight, string id)
    {
        

        // Add an edge from src to dest.  A new node is added to the adjacency
        // list of src.  The node is added at the begining
        AdjListNode* newNode = new AdjListNode(id, dest, weight);
        newNode->m_next = graph->m_array[src].m_head;
        graph->m_array[src].m_head = newNode;
     
        // Since graph is undirected, add an edge from dest to src also
        newNode = new AdjListNode(id, src, weight);
        newNode->m_next = graph->m_array[dest].m_head;
        graph->m_array[dest].m_head = newNode;
    } 

class MinPriorityNode
{
public:
    MinPriorityNode(int value, int key)
    {
        m_value = value;
        m_key = key;
    }
    ~MinPriorityNode() {}

    int m_value;
    int m_key;
};


class MinPriority
{
public:

    int heapSize; // Number of nodes present currently
    int heapLength; // Capacity of min heap

    MinPriority(int length)
    {
        heapSize = 0;
        heapLength = length;
        m_array = new MinPriorityNode*[length];
        m_position = new int[length];
    }
    ~MinPriority()
    {
        delete [] m_array;
        delete m_position;
    }

    int Parent(int i) { return (static_cast <int> (floor( i / 2 + 1))); }
    int Left(int i) { return 2 * i + 1; }
    int Right(int i) { return 2 * i + 2; }

     bool isEmpty(MinPriority* minHeap)
    {
        return minHeap->heapSize == 0;
    }

    

    void heapDecreaseKey(MinPriority* A, int i, int key)
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
            swapMinPriorityNode(&A->m_array[index], &A->m_array[(index - 1)/2]);

            // Move to parent index
            index = (index - 1) / 2;
        }
    }

    bool isInMinPriority(MinPriority* A, int value)
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

    MinPriorityNode* heapExtractMin(MinPriority* A)
    {
        if(isEmpty(A))
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



    

    void minHeapify(MinPriority* A, int i)
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
            swapMinPriorityNode(&A->m_array[smallest], &A->m_array[i]);

            minHeapify(A, smallest);
        }
    }

   



private:
    

    void swapMinPriorityNode(MinPriorityNode** a, MinPriorityNode**b)
    {
        MinPriorityNode* temp = *a;
        *a = *b;
        *b = temp;
    }

    

public:
     MinPriorityNode **m_array;
     int *m_position; // Used in function heapDecreaseKey

};






void printArray(int array[], int n)
{
    for(int i = 1; i < n; ++i)
    {
        cout << array[i] << " - " << i << endl;

    }
}

// The main function that constructs Minimum Spanning Tree (MST)
// using Prim's algorithm
void PrimMST(Graph* graph)
{

    int V = graph->m_size;// Get the number of vertices in graph
    int* parent = new int[V];   // Array to store constructed MST
    int* key = new int[V];      // Key values used to pick minimum weight edge in cut
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
        AdjListNode* pCrawl = graph->m_array[u].m_head;

       


        while (pCrawl != NULL)
        {
            
            int v = pCrawl->m_dest;
 
            // If v is not yet included in MST and weight of u-v is
            // less than key value of v, then update key value and
            // parent of v
            if (minHeap->isInMinPriority(minHeap, v) && pCrawl->m_weight < key[v])
            {
                key[v] = pCrawl->m_weight;
                graph->m_array[v].m_head->m_parent = graph->m_array[u].m_head->m_id;
                parent[v] = u;
                minHeap->heapDecreaseKey(minHeap, v, key[v]);
            }
            pCrawl = pCrawl->m_next;


        }

        cout << graph->m_array[u].m_head->m_id << " " 
             << graph->m_array[u].m_head->m_parent << " " 
             << minHeapNode->m_key << endl;
             

        total_weight += minHeapNode->m_key;
 
        

    }

    cout << total_weight << endl;
 
    // print edges of MST
    //printArray(parent, V);


}


// Driver program to test above functions
int main()
{
    // Let us create the graph given in above fugure
 

    Graph* graph = new Graph();

 
    PrimMST(graph);

 
    return 0;
}
