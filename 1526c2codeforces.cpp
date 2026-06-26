#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& arr , int n)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    int count = 0;
    long  long  sum =0;
    for(int  i= 0 ;i<n;i++)
    {  
        sum =sum + arr[i];
        if(sum < 0)
        {
            int element =pq.top();
            pq.pop();
            sum =sum - element ;
            count--;
        }
        pq.push(arr[i]);
        count++;
    }
    return count ;
}
int main()
{
   int n ;
   cin>>n;
   vector<int>arr(n);
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   int ans =solve(arr ,n);
   cout<<ans;
   return 0;
}