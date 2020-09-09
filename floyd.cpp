#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("fw_input.txt", "r", stdin);
    freopen("fw_output.txt", "w", stdout);

    int node, edge;
    cin >> node >> edge;

    int graph[node + 1][node + 1];
    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            graph[i][j] = INT_MAX;
            graph[i][i] =0;
        }
    }

    int src, dest, cost;

    for (int i = 1; i <= edge; i++)
    {
        cin >> src >> dest >> cost;
        graph[src][dest] = cost;
    }


    for (int k = 1; k <= node; k++)
    {
        for (int i = 1; i <= node; i++)
        {
            for (int j = 1; j <= node; j++)
            {
                if(i==j || i==k) continue;

                if (graph[i][k] < INT_MAX && graph[k][j] < INT_MAX) // caution for negative edge
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}