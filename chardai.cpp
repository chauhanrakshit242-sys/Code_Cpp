#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

int n, k;
vector<int> a, b;
vector<vector<int>> g;
vector<vector<int>> trans;

vector<long long> dfs(int u, int p) {
    vector<long long> dp(k, 0);

    for (int i = 0; i < k; i++) {
        if (a[u] == b[i]) dp[i] = 1;
    }

    for (int v : g[u]) {
        if (v == p) continue;

        auto ch = dfs(v, u);
        vector<long long> ndp(k, 0);

        for (int i = 0; i < k; i++) {
            if (dp[i] == 0) continue;

            for (int j = 0; j < k; j++) {
                if (ch[j] == 0) continue;

                int t = trans[i][j];
                if (t != -1) {
                    ndp[t] = (ndp[t] + dp[i] * ch[j]) % MOD;
                }

                ndp[i] = (ndp[i] + dp[i] * ch[j]) % MOD;
            }
        }
        dp.swap(ndp);
    }
    return dp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;

        g.assign(n, {});
        a.resize(n);
        b.resize(k);

        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < k; i++) cin >> b[i];

        trans.assign(k, vector<int>(k, -1));
        unordered_map<int,int> pos;
        for (int i = 0; i < k; i++) pos[b[i]] = i;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                int x = b[i] ^ b[j];
                if (pos.count(x)) trans[i][j] = pos[x];
            }
        }

        auto res = dfs(0, -1);
        long long ans = 0;

        for (int i = 0; i < k; i++) {
            ans = (ans + res[i]) % MOD;
        }

        cout << ans << '\n';
    }
    return 0;
}