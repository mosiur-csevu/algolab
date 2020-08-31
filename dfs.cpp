#include <bits/stdc++.h>
using namespace std;

void dfs(stack<int>Q,int node) {

}

int main()
{
    freopen("list.txt","r",stdin);
    map<int, list<int> > adj;
    list<int>::iterator x;

    int node,edge;
    cin >> node >> edge;

    int source,destination;

    bool visited[node+1];
    memset(visited,false,sizeof(visited));

    // input adjacency
    for(int i=0; i<edge; i++)
    {
        cin>>source>>destination;
        adj[source].push_back(destination);
        adj[destination].push_back(source);
    }

    // input first node;
    cin >> source;

    stack<int>Q;
    Q.push(source);
    visited[source]=true;
    cout << source << " ";
    bool new_push = false;

    while(!Q.empty()) {
        int current_node = Q.top();
        for (x = adj[current_node].begin(); x != adj[current_node].end(); x++)
        {
            //cout << "Node: " << current_node << " - " << *x << endl;
            if (!visited[*x])
            {

                visited[*x] = true;
                Q.push(*x);
                new_push=true;
                cout << *x << " ";
                break;
            }
            else {
                new_push=false;
            }
        }
        if(!new_push) Q.pop();
    }

    return 0;
}

