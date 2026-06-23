#include<bits/stdc++.h>
using namespace std;
bool checkisdigit(char ch)
{
   return ('0'<= ch && ch<= '9');
}
bool check_word(string word, string abb)
{
    int i=0;
    int j=0;
    int n= word.length();
    int m=abb.length();
    while(i<n)
    {
        if(checkisdigit(abb[j]))
        {
            if(abb[j]=='0')
            {
                return false;
            }
            int curr=0;
            while(j<m && checkisdigit(abb[j]))
            {
                curr = curr * 10 + abb[j] - '0';
                j++;
            }
            i =i+curr;
        }
        else
        {
            if(word[i]!=abb[j])
            {
                return false;
            }
            i++;
            j++;
        }
    }
    return (i==n&&j==m);
}
int main()
{
    string word;
    cin>>word;
    string abb;
    cin>>abb;
    bool ans= check_word(word,abb);
    if(ans)
    {
        cout<<"It is "<<abb<<"  abbervation of"<<word<<" Word";
    }
    else
    {
        cout<<"It is -> "<<abb<< " not abbervation of"<<word<<"Word";
    }
    return 0;
}