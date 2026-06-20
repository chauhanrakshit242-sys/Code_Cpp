#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// long long int countDerangements(int n) {
//     if(n == 1)
//         return 0;
//     if(n == 2)
//         return 1;

//     long long ans = ((n - 1) % MOD *
//                     ((countDerangements(n - 2) % MOD +
//                       countDerangements(n - 1) % MOD) % MOD))
//                     % MOD;

//     return ans;
// }
// long long int solve(int n ,vector<long long int>& dp)
// {
//     if(n==1)
//      return 0;
//     if(n==2)
//       return 1;
//     if(dp[n]!=-1)
//        return dp[n];
//     dp[n] = ((n - 1) % MOD *
//                     ((solve(n - 2,dp) % MOD +
//                       solve(n - 1,dp) % MOD) % MOD))
//                     % MOD;
//     return dp[n];              
// }


// long long int countDerangements(int n) {
//     vector<long long int>dp(n+1,0);
//     dp[1]=0;
//     dp[2]=1;
//     for(int i = 3 ;i<=n;i++)
//     {
//         dp[i] = ((i-1)%MOD * ((dp[i-2])%MOD+(dp[i-1])%MOD)%MOD)%MOD;
//     }
//     return dp[n];
// }
long long int countDerangements(int n) {
    if(n==1)
    return 0;
    if(n==2)
    return 1;
   long long int prev2=0;
   long long int prev1 =1;
    for(int  i=3;i<=n;i++)
    {
        long long int ans = ((i-1)%MOD * (prev2%MOD + prev1 %MOD)%MOD)%MOD;
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
int main()
{
    int n;
    cin>>n;
    long long int ans = countDerangements(n);
    cout<<ans;
    return 0;
}