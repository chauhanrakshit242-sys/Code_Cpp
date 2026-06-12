#include <iostream>
#include <vector>
#include <set>
using namespace std;

void dfs(int node,
         int parent,
         vector<int>& disc,
         vector<int>& low,
         vector<bool>& vis,
         vector<vector<int>>& adj,
         set<int>& ans,
         int& timer)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;

    int child = 0;

    for (auto neighbor : adj[node])
    {
        if (neighbor == parent)
            continue;

        if (!vis[neighbor])
        {
            child++;

            dfs(neighbor, node, disc, low, vis, adj, ans, timer);

            low[node] = min(low[node], low[neighbor]);

            // Root node
            if (parent == -1 && child > 1)
            {
                ans.insert(node);
            }

            // Non-root node
            if (parent != -1 && low[neighbor] >= disc[node])
            {
                ans.insert(node);
            }
        }
        else
        {
            low[node] = min(low[node], disc[neighbor]);
        }
    }
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<int>> adj(vertex);

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> disc(vertex, -1);
    vector<int> low(vertex, -1);
    vector<bool> vis(vertex, false);

    set<int> ans;
    int timer = 0;

    for (int i = 0; i < vertex; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, disc, low, vis, adj, ans, timer);
        }
    }

    cout << "Articulation Points: ";

    for (auto node : ans)
    {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}