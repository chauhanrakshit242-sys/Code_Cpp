#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

long long int solve(vector<int>& arr)
{
    long long  int prev2 = 0;
     long long int prev1 = arr[0];

    for(int i = 1; i < arr.size(); i++)
    {
         long long int include = prev2 + arr[i];
        long long int exclude = prev1;

        long long int ans = max(include, exclude);

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

long long houseRobber(vector<int>& arr)
{
    int n = arr.size();

    if(n == 1) return arr[0];

    vector<int> temp1, temp2;

    for(int i = 0; i < n; i++)
    {
        if(i != n-1) temp1.push_back(arr[i]);
        if(i != 0)   temp2.push_back(arr[i]);
    }

    return max(solve(temp1), solve(temp2));
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
       cin>>arr[i];
    }
    long long int ans =houseRobber(arr);
    cout<<ans;
    return 0;
}