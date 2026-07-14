#include<bits/stdc++.h>
using namespace std;
int convertD2B(int n)
{
     int i=0;
     int digit=0;
     while(n!=0)
     {
        int bit= n&1;
        digit = bit * pow(10,i)+digit;
        n=n>>1;
        i++;
     }
     return digit;
}
int main()
{
    int  n;
    cout<<"Enter the Number:";
    cin>>n;
    int ans =convertD2B(n);
    // while(n)
    // {
    //     if(n%2==1)
    //     {
    //         ans+='1';
    //     }
    //     else{
    //     ans+='0';
    //     }
    //     n=n>>1;
    // }
    // reverse(ans.begin(),ans.end());
    cout<<"The binary Representation of "<<n<<" is "<<ans;
    return 0;
}