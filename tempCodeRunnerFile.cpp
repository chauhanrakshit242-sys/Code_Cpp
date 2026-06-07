#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    vector<int> AdjList[v];  // adjacency list

    int u, w;  // use w instead of v

    // take edges input
    for(int i = 0; i < e; i++)