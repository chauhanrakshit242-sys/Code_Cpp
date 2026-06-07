#include<bits/stdc++.h>
using namespace std;
void dfs(int start ,vector<int>& ans, vector<bool>& visited,vector<vector<int>>Graph)
{
    ans.push_back(start);
    visited[start]=true;
    for(auto neighbor : Graph[start])
    {
        if(!(visited[neighbor]==true))
        {
            dfs(neighbor ,ans,visited,Graph);
        }
    }
}
int main()
{
    int vertex;
    int edges;
    cout<<"Enetr the Vertex";
    cin>>vertex;
    cout<<"Enter the Edges:";
    cin>>edges;
    vector<vector<int>>Graph(vertex);
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin >> u >>v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    vector<bool>visited(vertex,0);
    vector<int>ans;
    dfs(0, ans, visited ,Graph);
    for(auto i : ans)
    {
        cout<<i<<" ";
    }
    return 0;
}