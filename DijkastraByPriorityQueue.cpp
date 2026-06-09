#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int vertex;
    int edges;

    cin >> vertex >> edges;

    vector<vector<pair<int,int>>> adj(vertex);

    for(int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected Graph
    }

    int src;
    cin >> src;

    vector<int> dist(vertex, INT_MAX);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty())
    {
        auto node =pq.top();
        int weight=node.first;
        int element=node.second;
        pq.pop();
        for(auto neighbor : adj[element])
        {
              int adjNode = neighbor.first;
              int edges_weight=neighbor.second;
              if(edges_weight+weight < dist [adjNode])
              {
                dist[adjNode]=edges_weight+weight;
                pq.push({dist[adjNode],adjNode});
              }
        }

    }
    cout << "Shortest Distance from Source Node " << src << ":\n";

    for(int i = 0; i < vertex; i++)
    {
        cout << "Node " << i << " -> ";

        if(dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }
    }
    return 0;
}