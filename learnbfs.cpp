#include<bits/stdc++.h>
using namespace std; // namespace name

void bfs(vector<vector<int>>Graph)
{
    queue<int>q;
    vector<bool>visited(Graph.size(),false);
    q.push(0);
    visited[0]=true;
    while(!q.empty())
    {
       int node=q.front();
       cout<<node<<" ";
       q.pop();
       for(auto i :Graph[node])
       {
        if(!(visited[i]==true))
        {
         visited[i]=true;
         q.push(i);
        }
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
    bfs(Graph);
    return 0;
}