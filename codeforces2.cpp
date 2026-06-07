c#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    while (cases--) {
        int len;
        cin >> len;
        vector<int> arr(len);
        for (int idx = 0; idx < len; idx++) cin >> arr[idx];

        for (int start = 0; start < len; start++) {
            int best = start;
            for (int cur = start; cur < len; cur++) {
                if (arr[cur] > arr[best]) best = cur;
            }
            if (best != start) {
                reverse(arr.begin() + start, arr.begin() + best + 1);
                break;
            }
        }

        for (int val : arr) cout << val << " ";
        cout << "\n";
    }
    return 0;
}