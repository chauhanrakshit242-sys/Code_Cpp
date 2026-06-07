#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,y;
        cin>>n>>x>>y;
        vector<int>nums(n);
        for(int i=0;i<n;i++)
        {
            cin>>nums[i];
        }
    int sum=0;
    for(int i=0;i<n;i++)
    {
       sum=sum+nums[i];
    }
    int count=0;
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++)
    {
        int lower_range = sum - nums[i]-y;
        int upper_range = sum-nums[i]-x;
        for(int j=1;j<n;j++)
        {
            if (lower_range <= nums[j]<<upper_range)
            {
                count++;
            }
            
        }
    }
    cout<<count;
    }
    return 0;
}