#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n+1);
        for(int i = 1; i <= n; i++)
            cin >> a[i];

        unordered_map<int, vector<int>> groups;

        for(int i = 1; i <= n; i++) {
            int x = i;
            while(x % 2 == 0)
                x /= 2;
            groups[x].push_back(i);
        }

        bool ok = true;

        for(auto &g : groups) {
            vector<int> cur, need;

            for(int idx : g.second) {
                cur.push_back(a[idx]);
                need.push_back(idx);
            }

            sort(cur.begin(), cur.end());
            sort(need.begin(), need.end());

            if(cur != need) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}
