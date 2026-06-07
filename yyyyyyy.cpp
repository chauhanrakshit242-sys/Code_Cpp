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

        int count = 0;
        bool same_Found = false;

        for(int i = 0; i < n; i++) {
            int prev = (i - 1 + n) % n;

            if(s[i] != s[prev])
                count++;
            else
                same_Found = true;
        }

        if(count == 0)
            cout << 1 << endl;
        else if(same_Found)
            cout << count + 1 << endl;
        else
            cout << count << endl;
    }
    return 0;
}