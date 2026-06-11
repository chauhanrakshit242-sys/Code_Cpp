#include<bits/stdc++.h>
using namespace std;

void dfs(int node,
         int parent,
         vector<int>& disc,
         vector<int>& low,
         vector<int>& vis,
         int& timer,
         vector<vector<int>>& bridges,
         vector<vector<int>>& adj)
{
    vis[node] = 1;

    disc[node] = low[node] = timer++;

    for(auto neighbor : adj[node])
    {
        if(neighbor == parent)
        {
            continue;
        }

        if(!vis[neighbor])
        {
            dfs(neighbor,
                node,
                disc,
                low,
                vis,
                timer,
                bridges,
                adj);

            low[node] = min(low[node],
                            low[neighbor]);

            if(low[neighbor] > disc[node])
            {
                bridges.push_back(
                {node, neighbor});
            }
        }
        else
        {
            low[node] = min(low[node],
                            disc[neighbor]);
        }
    }
}

int main()
{
    int V, E;

    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges:\n";

    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    vector<int> vis(V, 0);

    vector<vector<int>> bridges;

    int timer = 0;

    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            dfs(i,
                -1,
                disc,
                low,
                vis,
                timer,
                bridges,
                adj);
        }
    }

    cout << "\nBridges are:\n";

    for(auto it : bridges)
    {
        cout << it[0]
             << " - "
             << it[1]
             << endl;
    }

    return 0;
}