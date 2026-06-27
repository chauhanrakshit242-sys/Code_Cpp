#include<bits/stdc++.h>
using namespace std;
int mincostfortravel(int n , vector<int>& days, vector<int>& costs  , int index)
{
    if(index >= n)
    return 0;
    int option1 = costs[0]+mincostfortravel(n, days,costs, index+1);
    int  i;
    for(i=index;i<n&& days[i]<days[index]+7;i++);
    int option2 =costs[1]+mincostfortravel(n,days,costs,i);
    for( i = index ;i <n && days[i]<days[index]+30;i++);
    int option3=costs[2]+mincostfortravel(n,days,costs,i);
    return min(option1,min(option2,option3));
}
// Memoiazation for DP
int mincostfortravelM(int n , vector<int>& days, vector<int>& costs  , int index ,vector<int>& dp)
{
    if(index >= n)
    return 0;
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    int option1 = costs[0]+mincostfortravelM(n, days,costs, index+1,dp);
    int  i;
    for(i=index;i<n&& days[i]<days[index]+7;i++);
    int option2 =costs[1]+mincostfortravelM(n,days,costs,i,dp);
    for( i = index ;i <n && days[i]<days[index]+30;i++);
    int option3=costs[2]+mincostfortravelM(n,days,costs,i,dp);
    dp[index]= min(option1,min(option2,option3));
    return dp[index];
} 
// for Tabulation
int mincost(int n , vector<int>& days , vector<int>& costs)
{
    vector<int>dp(n+1,INT_MAX);
    dp[n]=0;
    for(int k = n-1;k>=0;k--)
    {
        int option1 = costs[0]+dp[k+1];
        int i;
        for(i=k;i<n&&days[i]<days[k]+7;i++);
        int option2=costs[1]+dp[i];
        for(i=k;i<n&& days[i]<days[k]+30;i++);
        int option3=costs[2]+dp[i];
        dp[k]=min(option1,min(option2,option3));
    }
    return dp[0];
}
// Space otptimization In this approach we have to make  two queue for track fare till so far means 
int minSpace(int n , vector<int>& days , vector<int> & costs)
{
    int ans=0;
    queue<pair<int,int>>weekly; // pair  first track days till we travel and thier amount 
    queue<pair<int,int>>monthly;
    for(int day : days)
    {
        //step 1 remove expire days
        while(!monthly.empty()&&monthly.front().first + 30 <=day ) 
        monthly.pop();
        while(!weekly.empty()&& weekly.front().first+ 7<=day)
        weekly.pop();
        weekly.push(make_pair(day,costs[1]+ans));
        monthly.push(make_pair(day,costs[2]+ans));
        ans =  min(ans+costs[0],min(weekly.front().second,monthly.front().second));
    }
    return  ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>days(n);
    vector<int>costs(3);
    for(int i =0;i<n;i++)
    {
        cin>>days[i];
    }
    for(int i =0;i<3;i++)
    {
        cin>>costs[i];
    }
    vector<int>dp(n+1,-1);
    int ans = minSpace(n,days,costs);
    cout<<ans;
    return 0;
}