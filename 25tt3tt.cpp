#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long s, m;
        cin >> s >> m;

        if((s & m) != s) {
            cout << -1 << endl;
        } else {
            long long n = (s + m - 1) / m;
            cout << n << endl;
        }
    }

    return 0;
}