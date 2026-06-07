#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);  // safer way

    int u, w;
    for(int i = 0; i < e; i++)
    {   
        cin >> u >> w;

        // safety check
        if(u >= v || w >= v)
        {
            cout << "Invalid edge!" << endl;
            return 0;
        }

        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    vector<bool> visited(v, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int neighbor : adj[node])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);  // correct
            }
        }
    }

    return 0;
}