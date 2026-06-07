#include<iostream>
#include<vector>
using namespace std;
long long power(long  long a, long long b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b<0)
    {
        b=-b;
    }
    if(b&1)
    {
        return power(a,(b-1)/2)*power(a,(b-1)/2)*a;
    }
    else
    {
        return power(a,b/2)*power(a,b/2);
    }
}
int main()
{
   int a;
   cout<<"Enter the base:";
   cin>>a;
   int b;
   cout<<"Enter the exponent:";
   cin>>b;
   long long ans=power( a ,b);
   cout<<b<<" Power of -> "<<a<<" "<<ans;
   return 0;
}