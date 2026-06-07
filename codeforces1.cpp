#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int size, targetSum, step;
        cin >> size >> targetSum >> step;

        int currentSum = 0;
        for (int i = 0; i < size; i++) {
            int value;
            cin >> value;
            currentSum += value;
        }

        if (currentSum <= targetSum && (targetSum - currentSum) % step == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
