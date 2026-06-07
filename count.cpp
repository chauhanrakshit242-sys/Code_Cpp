#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , k;
    vector<int>arr(n);
    int num_one=0;
    int num_zero=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==1)
        {
            num_one++;
        }
        else
        {
            num_zero++;
        }
    }
    precompute_factorial(n);
    int minimum_need=k/2;
    
}
