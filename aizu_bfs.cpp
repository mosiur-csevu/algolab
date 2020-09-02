#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int node;
    list <int > *adj;
    bool *is_visited;
    int *level;

    Graph(int node)
    {
        this->node = node; // number of nodes
        adj = new list<int>[node+1];
        is_visited = new bool[node+1]; // 0-based indexing
        level = new int[node+1];

        for(int i=1; i<=node; i++) {
            is_visited[i] = 0;
            level[i]=-1;
        }
    }

    void makeList()
    {
        int source,degree,destination;
        for(int i=1; i<=node; i++)
        {
            cin >> source >> degree;
            for(int j=1; j<=degree; j++)
            {
                cin >> destination;
                adj[source].push_back(destination);
            }
        }
    }

    void BFS(int source)
    {
        queue<int>Q;
        Q.push(source);
        is_visited[source]=true;
        level[source]=0;

        list<int>::iterator x;

        while(!Q.empty())
        {
            int current_node = Q.front();
            Q.pop();
            for (x = adj[current_node].begin(); x != adj[current_node].end(); x++)
            {
                if (!is_visited[*x])
                {
                    is_visited[*x] = true;
                    Q.push(*x);
                    level[*x]= level[current_node]+1;
                }
            }
        }
    }

    void printLevel() {
        for(int i=1;i<=node;i++) {
            cout << i << " " << level[i] << endl;
        }
    }
};


int main()
{
    int node;
    cin >> node;
    Graph graph(node);
    graph.makeList();
    graph.BFS(1);
    graph.printLevel();
    return 0;
}

