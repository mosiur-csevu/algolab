#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int node;
    list <int > *adj;
    bool *is_visited;

    Graph(int node)
    {
        this->node = node; // number of nodes
        adj = new list<int>[node+1];
        is_visited = new bool[node+1]; // 0-based indexing
    }

    void addEdge(int source, int destination)
    {
        adj[source].push_back(destination);
        /// for undirected graph
        if(source != destination)
            adj[destination].push_back(source);
    }

    void BFS(int source)
    {
        // checking is_visited
        for(int i=1; i<=node; i++)
            cout << is_visited[i] << " ";
        cout << endl;

        cout << "BFS (" << source << ") : ";

        queue<int>Q;

        Q.push(source);
        is_visited[source]=true;

        list<int>::iterator x;

        while(!Q.empty())
        {
            int current_node = Q.front();
            cout << current_node << " ";
            Q.pop();

            for (x = adj[current_node].begin(); x != adj[current_node].end(); x++)
            {
                if (!is_visited[*x])
                {
                    is_visited[*x] = true;
                    Q.push(*x);
                }
            }
        }
         memset(is_visited,false,sizeof(is_visited));
    }


};


int main()
{
    freopen("list.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int node,edge;
    cin >> node >> edge;

    Graph graph(node);

    int source,destination;

    for(int i=1; i<=edge; i++)
    {
        cin>>source>>destination;
        graph.addEdge(source,destination);

    }

    while(cin >> source)
    {
        graph.BFS(source);
        cout << endl;
        
    }

    return 0;
}