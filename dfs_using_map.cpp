#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int node;
    map<int, list <int > > adj;
    bool *is_visited;

    Graph(int node)
    {
        this->node = node; // number of nodes
        is_visited = new bool[node+1]; // 0-based indexing
    }

    void addEdge(int source, int destination)
    {
        adj[source].push_back(destination);
        /// for undirected graph
        if(source != destination)
            adj[destination].push_back(source);
    }

    void DFS(int node)
    {
        cout << node << " ";
        is_visited[node] = true;

        list<int>::iterator x;

        for(x=adj[node].begin(); x!=adj[node].end(); x++)
        {
            if(is_visited[*x]==false)
                DFS(*x);
        }
    }
};


int main()
{
    freopen("list.txt","r",stdin);

    int node,edge;
    cin >> node >> edge;

    Graph graph(node);

    int source,destination;

    for(int i=0; i<edge; i++)
    {
        cin>>source>>destination;
        graph.addEdge(source,destination);

    }

    cin>> source;
    graph.DFS(source);

    return 0;
}
