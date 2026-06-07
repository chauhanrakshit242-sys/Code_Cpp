#include<bits/stdc++.h>
using namespace std;
void  solve(vector<int> arr ,int n, int m ,int i, int& ans)
{
    if(i == n) {
        bool ischeck= true;
        for(int j = 0; j <n-1; j++) {
            if(j % 2 == 0 && !(arr[j] < arr[j+1])) ischeck = false;
            if(j % 2 == 1 && !(arr[j] > arr[j+1])) ischeck= false;
        }
        if(ischeck)ans++;
        return;
    }
    if(arr[i]!=-1)
    {
        solve(arr,n,m,i+1,ans);
    }
    else{
        for(int j=1;j<=m;j++)
        {
            arr[i]=j;
            solve(arr, n, m,i+1,ans);
        }
        arr[i]=-1;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n;i++)
    {
       cin>>arr[i];
    }
    int m;
    cin>>m;
    int ans=0;
    int i=0;
    solve(arr, n,m,i,ans);
    cout<<ans;
    return 0;
}

