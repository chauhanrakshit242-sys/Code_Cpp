#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;

    while (cases--) {
        int size;
        cin >> size;

        if (size == 2) {
            cout << "1 2\n";
        } else {
            for (int val = 2; val <= size; val++) {
                cout << val << " ";
            }
            cout << 1 << "\n";
        }
    }
    return 0;
}