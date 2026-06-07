#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int k;
    int count=0;
    cin>>n>>k;
    vector<int>isPrime(n+1,1);

    isPrime[0]=0;
    isPrime[1]=0;

    for(int i=2;i*i<=n;i++){
        if(isPrime[i]==1){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=0;
            }
        }
    }

    vector<int>primes;

    for(int i=2;i<=n;i++){
        if(isPrime[i]==1){
            primes.push_back(i);
        }
    }

    for(int i=0;i+1<primes.size();i++){
        int val=primes[i]+primes[i+1]+1;

        if(val<=n && isPrime[val]){
            count++;
        }
    }

    if(count>=k){
        cout<<"yes";
    }else{
        cout<<"no";
    }
}