#include<iostream>
#include<vector>
using namespace std;
// int fib(int n)
// {
//     vector<int>dp(n+1,-1);
//     dp[0]=0;
//     dp[1]=1;
//     for(int i=2;i<=n;i++)
//     {
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     return dp[n];
// }
// int fib(int n)
// {
//     if(n<=1)
//     {
//     return n;
//     }
//     return fib(n-1)+fib(n-2);
// }

// int fib(int n,vector<int>& dp)
// {
//     if(n<=1)
//     {
//         return n;
//     }
//     if(dp[n]!=-1)
//     {
//         return dp[n];
//     }
//     dp[n]=fib(n-1,dp)+fib(n-2,dp);
//     return dp[n];
// }

int fib(int n)
{
    if(n<=1)
    {
        return n;
    }
    int first_term=0;
    int second_term=1;
    int c;
    for(int i=2;i<=n;i++)
    {
        c=first_term+second_term;
        first_term=second_term;
        second_term=c;
        
    }
    return c;
}
int main()
{
    int n;
    cout<<"Enter the Number :";
    cin>>n;
    // vector<int>dp(n+1, -1);
    int answer=fib(n);
    cout<<answer;
    return 0;
}