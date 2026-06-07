#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> ops;

        for(int i = 0; i < n; i++) {
            if(s[i] == '1')
                ops.push_back(i + 1);
        }

        if(ops.size() % 2 == 1) {
            cout << -1 << endl;
        }
        else {
            cout << ops.size() << endl;
            for(int i : ops)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}