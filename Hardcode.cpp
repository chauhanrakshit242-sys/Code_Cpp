#include<bits/stdc++.h>
using namespace std;
void create_g(vector<vector<int>>& graph_mat ,vector<vector<int>>list)
{
    for(auto it: list)
    {
        int u=it[0];
        int v=it[1];
        graph_mat[u][v]=1;
        graph_mat[v][u]=1;
    }
}
int main()
{
    int vertex=4;
    vector<vector<int>>list={{0,1}, {0,3},{1,2},{2,3}};
    vector<vector<int>>graph_mat(vertex,vector<int>(vertex,0));
    create_g(graph_mat,list);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<" "<<graph_mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}