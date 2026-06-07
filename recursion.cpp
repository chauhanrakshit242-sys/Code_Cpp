#include<bits/stdc++.h>
using namespace std;

void dfs(int start,
         vector<vector<int>>& graph,
         vector<bool>& vis)
{
    vis[start] = true;

    cout << start << " ";

    for(auto neighbour : graph[start])
    {
        if(!vis[neighbour])
        {
            dfs(neighbour, graph, vis);
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph(v);

    for(int i = 0; i < e; i++)
    {
        int u, w;
        cin >> u >> w;

        graph[u].push_back(w);
        graph[w].push_back(u);
    }

    vector<bool> vis(v, false);

    dfs(0, graph, vis);

    return 0;
}