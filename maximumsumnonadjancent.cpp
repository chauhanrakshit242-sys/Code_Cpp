#include<bits/stdc++.h>
using namespace std;
// int solve(vector<int>arr, int n)
// {
//     if(n<0)
//     return 0;
//     if(n==0)
//     {
//         return arr[0];
//     }
//     int include =solve(arr,n-2)+arr[n];
//     int exclude = solve(arr,n-1);
//     return max(include,exclude);
// }

// solve by Memoization
// int solve(vector<int>& arr, int n, vector<int>& dp)
// {
//     if(n<0)
//     return 0;
//     if(n==0)
//     return arr[0];
//     if(dp[n]!=-1)
//     {
//         return dp[n];
//     }
//     int include =solve(arr,n-2,dp)+arr[n];
//     int exclude = solve(arr,n-1,dp);
//     dp[n]= max(include,exclude);
//     return dp[n];
// }

// //solve by tabulation
// int solve(vector<int>& arr, int n)
// {
//     vector<int>dp(n,0);
//     dp[0]=arr[0];
//     for(int i = 1; i<n;i++)
//     {
//         int include = dp[i-2]+nums[i];
//         int exculde = dp[i-1]+0;
//         dp[i]=max(include,exculde);
//     }
//     return dp[n-1];
// }
//  By space otmization
int solve(vector<int>& arr, int n)
{
     int prev2=0;
     int prev1=arr[0];
    for(int i = 1; i<n;i++)
    {
        int include = prev2+arr[i];
        int exculde = prev1+0;
        int  ans=max(prev1,prev2);
         prev2=prev1;
         prev1=ans;
    }
    return prev1;
}

int main()
{
    int t;cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=solve(arr ,n-1); // Solve by recusion only
    // vector<int>dp(n,-1);
    // int ans=solve(arr ,n-1,dp);
    cout<<"Answer:"<<ans<<endl;
   }
   return 0;
}