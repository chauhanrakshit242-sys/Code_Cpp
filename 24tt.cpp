#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, d;
        cin >> n >> m >> d;

        int maxBoxes = (d / m) + 1;
        int result = (n + maxBoxes - 1) / maxBoxes;

        cout << result << endl;
    }

    return 0;
}

