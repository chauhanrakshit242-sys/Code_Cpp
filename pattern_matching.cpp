#include<bits/stdc++.h> 
#define d 31
#define MOD 1000000007
using namespace std;
int main()
{
      string  text;
      string pattern;
      cin>>text;
      cin>>pattern;
      int p=pattern.length();
      int t=text.length();
      long long  pattern_hash=0;
      long long  window_hash=0;
      vector<int>ans;
      for(int  i = 0;i<pattern.length();i++)
      {
          pattern_hash =(pattern_hash %MOD + (((int)pow(d,p-i-1))%MOD * (pattern[i]-'a'+1)%MOD)%MOD)%MOD;
          window_hash =(window_hash%MOD +(((int)pow(d,p-i-1))%MOD*(text[i]-'a'+1)%MOD)%MOD)%MOD;
      }
      for(int i = 0 ; i<=t-p;i++)
      {
         bool match = true;
         if(pattern_hash==window_hash)
         {
            for(int j =0 ; j< p ;j++)
            {
                if(pattern[j]!=text[i+j])
                {
                    match=false;
                    break;
                }
            }
         }
         else{
            match=false;
         }
         if(match)
         {
            ans.push_back(i);
         }
         if(i <  t - p)
         {
         window_hash =
(((((window_hash -
((((int)pow(d,p-1)) % MOD) * (text[i]-'a'+1)) % MOD
+ MOD) % MOD)
* d) % MOD)
+ (text[i+p]-'a'+1))
% MOD;
         }
      }
      for(auto i : ans)
      {
        cout<<i;
      }
    return 0;
}