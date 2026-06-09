#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int vertex, edges;
        cin >> vertex >> edges;

        vector<vector<int>> edgeList;

        for(int i = 0; i < edges; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            edgeList.push_back({u, v, w});

            // Undirected graph ke liye reverse edge bhi add karo
            edgeList.push_back({v, u, w});
        }

        int src;
        cin >> src;

        vector<int> dist(vertex, INT_MAX);
        dist[src] = 0;

        // Bellman-Ford Relaxation
        for(int i = 1; i <= vertex - 1; i++)
        {
            for(auto &edge : edgeList)
            {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if(dist[u] != INT_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Negative Cycle Check
        bool negativeCycle = false;

        for(auto &edge : edgeList)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                negativeCycle = true;
                break;
            }
        }

        if(negativeCycle)
        {
            cout << "Negative Weight Cycle Detected\n";
            continue;
        }

        cout << "Shortest Distance from Source Node "
             << src << ":\n";

        for(int i = 0; i < vertex; i++)
        {
            cout << "Node " << i << " -> ";

            if(dist[i] == INT_MAX)
                cout << "INF";
            else
                cout << dist[i];

            cout << '\n';
        }
    }

    return 0;
}