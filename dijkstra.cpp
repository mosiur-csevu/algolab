#include <bits/stdc++.h>
using namespace std;


class Graph
{
public:
    int node;
    int *parent;
    list<pair<int, int>> *adj;
    int *cost;

    Graph(int node)
    {
        this->node = node;
        parent = new int[node + 1];
        adj = new list<pair<int, int>>[node + 1];
        cost = new int[node + 1];
        for (int i = 0; i <= node; i++)
            cost[i] = INT_MAX;
    }

    void addEdge(int source, int dest, int cost)
    {
        adj[source].push_back(make_pair(dest, cost));
        //adj[dest].push_back(make_pair(source,cost));
    }

    void dijkstra(int source)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        cost[source] = 0;
        parent[source] = source;
        Q.push(make_pair(cost[source], source));

        list<pair<int, int>>::iterator it;

        while (!Q.empty())
        {
            int parent_node = Q.top().second;
            Q.pop();

            for (it = adj[parent_node].begin(); it != adj[parent_node].end(); it++)
            {
                int current_node = it->first;
                int current_cost = it->second;

                

                if (cost[parent_node] + current_cost < cost[current_node])
                {
                    parent[current_node] = parent_node;
                    cost[current_node] = cost[parent_node] + current_cost;
                    Q.push(make_pair(cost[current_node],current_node));
                }

            }
        }
    }

    void printCost()
    {
        for (int i = 1; i <= node; i++)
        {
            printf("cost[%d] = %d\n", i, cost[i]);
        }
    }

    void print_path(int source) {
        for(int i=1;i<=node;i++) {
            if(i==source) {
                cout << "Source :" << i << endl;
                continue;
            }
            cout << "Path of "<< i << " :"; 
            int tmp = i;
            while(parent[tmp]!=source) {
                cout << parent[tmp] << " ";
                tmp = parent[tmp];
            }
            cout << source << endl;
        }
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int node, edge;
    cin >> node >> edge;

    Graph graph(node);

    int source, dest, cost;
    for (int i = 0; i < edge; i++)
    {
        cin >> source >> dest >> cost;
        graph.addEdge(source, dest, cost);
    }

    graph.dijkstra(1);
    graph.printCost();
    graph.print_path(1);

    return 0;
}