#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(
    vector<pair<int,int>> edges,
    int n,
    int m,
    int s,
    int t)
{
    // Adjacency List
    vector<vector<int>> adj(n + 1);

    for(auto it : edges)
    {
        int u = it.first;
        int v = it.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Visited Array
    vector<bool> vis(n + 1, false);

    // Parent Array
    vector<int> parent(n + 1, -1);

    queue<int> q;

    vis[s] = true;
    q.push(s);

    // BFS
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        // Early stop if destination found
        if(node == t)
        {
            break;
        }

        for(auto neighbour : adj[node])
        {
            if(!vis[neighbour])
            {
                vis[neighbour] = true;
                parent[neighbour] = node;
                q.push(neighbour);
            }
        }
    }

    // Destination not reachable
    if(!vis[t])
    {
        return {};
    }

    // Reconstruct path
    vector<int> path;

    int currentNode = t;

    while(currentNode != -1)
    {
        path.push_back(currentNode);
        currentNode = parent[currentNode];
    }

    reverse(path.begin(), path.end());

    return path;
}

int main()
{
    int n, m;

    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<pair<int,int>> edges;

    cout << "Enter edges:\n";

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        edges.push_back({u, v});
    }

    int source, destination;

    cout << "Enter source and destination: ";
    cin >> source >> destination;

    vector<int> ans =
        shortestPath(edges,
                     n,
                     m,
                     source,
                     destination);

    if(ans.empty())
    {
        cout << "No Path Exists\n";
    }
    else
    {
        cout << "Shortest Path: ";

        for(auto node : ans)
        {
            cout << node << " ";
        }

        cout << "\nPath Length (Edges): "
             << ans.size() - 1;
    }

    return 0;
}