#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        const int INF = 1e9;

        vector<int> dp(7), newdp(7);

        // First position
        for(int x = 1; x <= 6; x++)
            dp[x] = (a[0] != x);

        for(int i = 1; i < n; i++) {

            for(int x = 1; x <= 6; x++)
                newdp[x] = INF;

            for(int x = 1; x <= 6; x++) {
                for(int y = 1; y <= 6; y++) {

                    if(x == y) continue;
                    if(x == 7 - y) continue;

                    newdp[x] = min(newdp[x],
                                   dp[y] + (a[i] != x));
                }
            }

            dp = newdp;
        }

        int ans = *min_element(dp.begin()+1, dp.end());
        cout << ans << "\n";
    }
}
