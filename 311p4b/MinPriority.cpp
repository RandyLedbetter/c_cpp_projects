MinPriority::MinPriority(int heap_length)
{
    m_heapLength = heap_length;
    m_heapSize = 0;
    m_pos = NULL;
    m_array = NULL;
}
MinPriority::~MinPriority()
{
    delete m_pos;
    delete[] m_array;
}

void swapMinPriorityNode(MinPriorityNode** a, MinPriorityNode** b)
{
    MinPriorityNode* temp = *a;
    *a = *b;
    b* = temp;
}
int parent(i)
{
    return (static_cast <int> (std::floor(i / 2));
}

int left(i)
{
    return 2 * i;
}

int right(i)
{
    return 2 * i + 1;
}

void minHeapify(MinPriority* A, int i)
{
    int smallest, l, r;
    smallest = i;
    l = 2 * i + 1;
    r = 2 * i + 2;

    if(l < A->m_heapSize && A->m_array[l]->m_key < A->m_array[smallest]->m_key)
    {
        smallest = l;
    }
    if(r < A->m_heapSize && A->m_array[r]->m_key < A->m_array[smallest]->m_key)
    {
        smallest = r;
    }
    if(smallest != i)
    {
        MinPriorityNode* smallestNode = A->m_array[smallest];
        MinPriorityNode* currentNode = A->m_array[i];

        // Swap node positions
        A->m_pos[smallestNode->m_v] = i;
        A->m_pos[currentNode->m_v] = smallest;

        // Swap nodes
        swapMinPriorityNode(&A->m_array[smallest], &A->m_array[i]);

        minHeapify(A, smallest);
    }

}

bool isEmpty(MinPriority* A)
{
    return (m_heapSize) ? true : false;
}

MinPriorityNode* extractMin(MinPriority* A)
{
    if(isEmpty(A))
    {
        return NULL;
    }

    MinPriorityNode* root = A->m_array[0];

    // Replace root node with last node
    MinPriorityNode* lastNode = A->m_array[A->m_heapSize - 1];
    A->m_array[0] = lastNode;

    // Update position of last node]
    A->m_pos[root->m_v] = A->m_heapSize - 1;
    A->m_pos[lastNode->m_v] = 0;

    // reduce heap size and heapify root
    --A->m_heapSize;
    minHeapify(A, 0);

    return root;
}

void decreaseKey(MinPriority* A, int i, int key)
{
    int index = A->m_pos[i];

    // Get the node and update its key value
    A->m_array[index]->m_key = key;

    // Travel up while the complete tree is not heapified
    while(index && A->m_array[index]->m_key < A->m_array[(i - 1) / 2]->m_key)
    {
        // Swap this node with its parent
        A->m_pos[A->m_array[index]->m_v] = (index - 1) / 2;
        A->m_pos[A->m_array[(index - 1) / 2]->m_v] = index;
        swapMinPriorityNode(&A->m_array[index], &A->m_array[(index - 1) / 2]);

        // Move to parent index

        index = (index - 1) / 2;
    }
}

bool isInMinHeap(MinPriority* A, int i)
{
    if(A->m_pos[i] < A->m_heapSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printArr(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        std::cout << arr[i] << " - " << i << endl;
    }
}

    
MinPriorityNode::MinPriorityNode(int v, int key)
{
    m_v = v;
    m_key = key;
}

MinPriorityNode::~MinPriorityNode()
{
}
