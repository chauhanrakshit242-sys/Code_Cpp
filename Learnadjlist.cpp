#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int v , e;
    cin>>v>>e;
    vector<vector<int>>AdjList(v);
    for(int i=0;i<e;i++)
    {
        int u , w;
        cin >> u >>w;
        AdjList[u].push_back(w);
    }
    for(int i=0;i<v;i++)
    {
        cout<< i <<"--->";
        for(int j=0; j<AdjList[i].size();j++)
        {
            cout<<AdjList[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
