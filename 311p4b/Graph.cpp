Graph::Graph(int V)
{
    m_V = V;
    this.array = new AdjList(V);

    for(int i = 0; i < V; i++)
    {
        array[i].m_head = NULL;
    }

}