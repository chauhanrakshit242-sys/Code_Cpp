#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    vector<pair<int ,int> > AdjList[v];  // adjacency list
     vector<vector<int>>adj(v);
    int u,r,w;  // use w instead of v

    // take edges input
    for(int i = 0; i < e; i++)
    {
        cin >> u >> r >> w;
        AdjList[u].push_back({r,w});
        AdjList[r].push_back({u, w}); // undirected graph
    }

    // print adjacency list
    for(int i = 0; i < v; i++)
    {
        cout << i << " -> ";
        for(auto it : AdjList[i])
        {
            cout<<"("<<it.first<<","<<it.second<<")";
        }
        cout << endl;
    }

    return 0;
}