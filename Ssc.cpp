#include<bits/stdc++.h>
using namespace std;

void dfs1(int node,
          vector<int>& vis,
          stack<int>& st,
          vector<vector<int>>& adj)
{
    vis[node] = 1;

    for(auto neighbour : adj[node])
    {
        if(!vis[neighbour])
        {
            dfs1(neighbour,
                 vis,
                 st,
                 adj);
        }
    }

    st.push(node);
}

void dfs2(int node,
          vector<int>& vis,
          vector<vector<int>>& transpose)
{
    vis[node] = 1;

    cout << node << " ";

    for(auto neighbour : transpose[node])
    {
        if(!vis[neighbour])
        {
            dfs2(neighbour,
                 vis,
                 transpose);
        }
    }
}

int main()
{
    int V,E;

    cin >> V >> E;

    vector<vector<int>> adj(V);

    for(int i=0;i<E;i++)
    {
        int u,v;

        cin >> u >> v;

        adj[u].push_back(v);
    }

    stack<int> st;

    vector<int> vis(V,0);

    // Step 1
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            dfs1(i,
                 vis,
                 st,
                 adj);
        }
    }

    // Step 2
    vector<vector<int>> transpose(V);

    for(int i=0;i<V;i++)
    {
        vis[i] = 0;

        for(auto neighbour : adj[i])
        {
            transpose[neighbour]
            .push_back(i);
        }
    }

    int sccCount = 0;

    // Step 3
    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        if(!vis[node])
        {
            sccCount++;

            cout<<"SCC "<<sccCount<<" : ";

            dfs2(node,
                 vis,
                 transpose);

            cout<<endl;
        }
    }

    cout<<"Total SCC = "
        <<sccCount;
}