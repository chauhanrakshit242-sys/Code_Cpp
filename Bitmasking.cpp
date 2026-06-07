#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int mid = n / 2;

    vector<long long> leftSums, rightSums;

    // Bitmasking on left half
    for (int mask = 0; mask < (1 << mid); mask++) {
        long long sum = 0;
        for (int i = 0; i < mid; i++) {
            if (mask & (1 << i)) {
                sum += a[i];
            }
        }
        leftSums.push_back(sum);
    }

    // Bitmasking on right half
    for (int mask = 0; mask < (1 << (n - mid)); mask++) {
        long long sum = 0;
        for (int i = 0; i < n - mid; i++) {
            if (mask & (1 << i)) {
                sum += a[mid + i];
            }
        }
        rightSums.push_back(sum);
    }

    sort(rightSums.begin(), rightSums.end());

    long long ans = 0;

    for (long long s : leftSums) {
        long long need = x - s;
        auto range = equal_range(rightSums.begin(), rightSums.end(), need);
        ans += (range.second - range.first);
    }

    cout << ans << "\n";
    return 0;
}
