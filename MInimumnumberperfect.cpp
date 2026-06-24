#include<bits/stdc++.h>
using namespace std;
int solver(int n)
{
    if(n==0) return  0;
    int ans = n;
    for(int  i= 1;i*i<=n;i++)
    {
        ans =min(ans, 1+solver(n-i*i));
    }
    return ans;
}
int solvem(int n, vector<int>& dp)
{
    if(n==0)
    return 0;
    if(dp[n]!=-1) return dp[n];
    int ans=INT_MAX;
    for(int i=1;i*i<=n;i++)
    {
      ans=min(ans,1+solvem(n-i*i ,dp));
    }
    dp[n]=ans;
    return dp[n];
}
int solveTabulation(int n)
{
    vector<int>dp(n+1 ,INT_MAX);
    dp[0]=0;
    for(int  i=1;i<=n;i++)
    {
        for(int j=1;j*j<=n;j++)
        {
            if(i-j*j >=0)
            {
               dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
    }
    return dp[n];
}
int main()
{
    int  n ;
    cin>>n;
    int ans = solver(n);
    vector<int>dp(n+1,-1);
    int res=solvem(n,dp);
    int out=solveTabulation(n);
    cout<<res<<endl;
    cout<<out;
    return 0;
}