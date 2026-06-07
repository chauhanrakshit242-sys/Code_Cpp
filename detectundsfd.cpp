#include<iostream>
#include<vector>
using namespace std;

bool detect(int parent, int node, vector<int> AdjList[], vector<bool>& visited)
{
    visited[node] = true;

    for(int j = 0; j < AdjList[node].size(); j++)
    {
        int neighbor = AdjList[node][j];

        if(neighbor == parent)
            continue;

        if(visited[neighbor])
            return true;

        if(detect(node, neighbor, AdjList, visited))
            return true;
    }

    return false;
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<int> AdjList[v];

    int u, w;
    for(int i = 0; i < e; i++)
    {
        cin >> u >> w;
        AdjList[u].push_back(w);
        AdjList[w].push_back(u);
    }

    vector<bool> visited(v, false);

    bool ans = detect(-1, 0, AdjList, visited);

    cout << ans;

    return 0;
}