#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& ans, vector<bool>& visited)
{
    visited[node] = true;
    ans.push_back(node);

    int size = adj.size();

    for(int j = 0; j < size; j++)
    {
        if(adj[node][j] != 0 && !visited[j])
        {
            dfs(j, adj, ans, visited);
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v, vector<int>(v, 0));

    int u, w, val;
    for(int i = 0; i < e; i++)
    {
        cin >> u >> w >> val;
        adj[u][w] = val;
        adj[w][u] = val;
    }

    vector<int> ans;
    vector<bool> visited(v, false);

    dfs(0, adj, ans, visited);

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}