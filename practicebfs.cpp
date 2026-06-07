#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int V;
    cin >> V;

    vector<vector<int>> adj(V, vector<int>(V));

    // input weighted matrix
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cin >> adj[i][j];
        }
    }

    vector<bool> visited(V, false);
    queue<int> q;
    vector<int> ans;

    q.push(0);
    visited[0] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(int j = 0; j < V; j++)
        {
            // 🔥 change here
            if(adj[node][j] != 0 && !visited[j])
            {
                visited[j] = true;
                q.push(j);
            }
        }
    }

    for(int x : ans)
        cout << x << " ";

    return 0;
}