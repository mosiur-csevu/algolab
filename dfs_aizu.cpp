#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int node; // number of nods
    list<int> *adj;
    bool *visited;
    int *discover_time;
    int *finish_time;
    int time;

    Graph(int node)
    {
        this->node = node;
        adj = new list<int>[node+1];
        visited = new bool[node+1];
        discover_time = new int[node+1];
        finish_time = new int[node+1];

        for(int i=0; i<=node; i++)
        {
            visited[i]=0;
            finish_time[i] = discover_time[i]= 0;
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

    void DFS(int source)
    {
        visited[source]=1;
        list<int>::iterator x;

        for(x=adj[source].begin(); x!=adj[source].end(); x++)
        {
            if(visited[*x]==0)
            {
                discover_time[*x] = time++; // 2 3 4
                DFS(*x);
            }
        }

        finish_time[source]= time++;
       // cout << "finish time of " << source << " is " << finish_time[source] << endl;
    }

    void printTime() {
        for(int i=1;i<=node;i++) {
            cout << i << " " << discover_time[i] << " " << finish_time[i] << endl;
        }
    }
};



int main()
{
    //freopen("aizu_dfs.txt", "r", stdin);
    int node;
    cin >> node;
    // object of Graph
    Graph graph(node);
    graph.makeList();
    graph.time=1;
    for(int i=1;i<=node;i++) {
        if(graph.visited[i]==0) {
            graph.discover_time[i]=graph.time++;
            graph.DFS(i);
        }
    }
    graph.printTime();
    return 0;
}
