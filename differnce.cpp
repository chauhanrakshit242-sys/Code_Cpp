#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, w;
    cin >> n >> w;

    vector<int> s(n);
    vector<int> pat(w);

    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    for(int i = 0; i < w; i++)
    {
        cin >> pat[i];
    }

    if(w == 1)
    {
        cout << n << endl;
        return 0;
    }

    vector<int> diff_pat;
    for(int i = 0; i < w - 1; i++)
    {
        diff_pat.push_back(pat[i + 1] - pat[i]);
    }

    vector<int> diff_s;
    for(int i = 0; i < n - 1; i++)
    {
        diff_s.push_back(s[i + 1] - s[i]);
    }

    // LPS Construction
    vector<int> lps(diff_pat.size(), 0);

    int len = 0;
    int i = 1;

    while(i < diff_pat.size())
    {
        if(diff_pat[i] == diff_pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    // KMP Matching
    i = 0;
    int j = 0;
    int cnt = 0;

    while(i < diff_s.size())
    {
        if(diff_s[i] == diff_pat[j])
        {
            i++;
            j++;
        }

        if(j == diff_pat.size())
        {
            cnt++;
            j = lps[j - 1];
        }
        else if(i < diff_s.size() && diff_s[i] != diff_pat[j])
        {
            if(j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}