#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertex;
    int edges;
    cout<<"Enter the Vertex:";
    cin>>vertex;
    cout<<"Enter the Edges:";
    cin>>edges;
    vector<vector<int>>AdjMat(vertex,(vector<int>(vertex,0)));
    int u, v , w;
    for(int i=0;i<edges;i++)
    {
      cin >> u>> v >>w;
      AdjMat[u][v]=w;
      AdjMat[v][u]=w;
    }
    cout<<"Adjanceny Matrix:"<<endl;
    cout<<"{"<<endl;
    for(int i=0;i<vertex;i++)
    {   
        cout<<"{";
        for (int  j = 0; j < vertex; j++)
        {
            cout<<" "<<AdjMat[i][j]<<" ";
        }
        cout<<"}";
        cout<<endl;
    }
    cout<<"}";
  return 0;
}