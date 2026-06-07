#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int l; int r;
    cout<<"Enter the startin value....:";
    cin>>l;
    cout<<"Enter the value from whered u want to :";
    cin>>r;
    int limit =sqrt(r);
    vector<bool>primee(limit+1,true);
    primee[0]=false;
    primee[1]=false;
    for(int i=0;i<limit;i++)
    {
        if(primee[i])
        {
            for(int j=i*i;j<limit;j+i)
            {
                primee[j]=false;
            }
        }
    }
    vector<bool>prime(r-l+1,true);
    for(int i=l;i<r;i++)
    {
        if(primee[i])
        {
            for(int j=i*i;j<r;j=j+i)
            {
                prime[j]=false;
            }
        }
    }
    cout<<"Print prime";
    for(int i=l;i<r;i++)
    {
       if(prime[i])
       {
        cout<<i<<" ";
       }
    }
    return 0;
}