#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int N = 100000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k;
    cin >> t >> k;

    vector<long long> dp(N + 1, 0);
    vector<long long> prefix(N + 1, 0);

    dp[0] = 1;

    for(int i = 1; i <= N; i++)
    {
        dp[i] = dp[i - 1];

        if(i >= k)
            dp[i] = (dp[i] + dp[i - k]) % MOD;
    }

    prefix[0] = dp[0];

    for(int i = 1; i <= N; i++)
    {
        prefix[i] = (prefix[i - 1] + dp[i]) % MOD;
    }

    while(t--)
    {
        int a, b;
        cin >> a >> b;

        long long ans = prefix[b];

        if(a > 1)
            ans = (ans - prefix[a - 2] + MOD) % MOD;

        cout << ans << '\n';
    }

    return 0;
}