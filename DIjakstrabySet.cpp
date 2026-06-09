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

    dist[src] = 0;

    set<pair<int,int>> st;

    // {distance, node}
    st.insert({0, src});

    while(!st.empty())
    {
        auto node = *(st.begin());

        st.erase(st.begin());

        int distance = node.first;
        int currNode = node.second;

        for(auto neighbor : adj[currNode])
        {
            int adjNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if(distance + edgeWeight < dist[adjNode])
            {
                auto record = st.find({dist[adjNode], adjNode});

                if(record != st.end())
                {
                    st.erase(record);
                }

                dist[adjNode] = distance + edgeWeight;

                st.insert({dist[adjNode], adjNode});
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